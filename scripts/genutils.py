
import re

from enum import Enum
from itertools import chain

# TODO: allow for descriptions which can be converted to comments

class Use(Enum):
    Either = 0
    Left = 1
    Right = 2

class Operand(object):
    def __init__(self, name, width):
        self.__name = name
        self.__width = width

    def __str__(self):
        return f'{self.__name.upper()}{self.__width}' if self.__width is not None else self.__name.upper()

    def __repr__(self):
        return str(self)

class OperandTemplate(object):
    def __init__str(self, width, s: str):
        self.__repeatable = True
        self.__use = Use.Either
        self.__maxwidth = width
        self.__scale = False
        self.__dict = False

        for idx, ch in enumerate(s):
            if ch.isalnum():
                break

            if ch == '$':
                self.__repeatable = False
                self.__use = Use.Right
            elif ch == '^':
                self.__repeatable = False
                self.__use = Use.Left
            elif ch == '?':
                self.__repeatable = False
            elif ch == '&':
                self.__scale = True
            
        self.__str = s[idx:len(s)]

    def __init__dict(self, width, d: dict):
        self.__modes = [OperandTemplate(width, name) for name in d['modes']]
        self.__dict = True
        self.__maxwidth = width

        if 'use' in d:
            self.__use = Use[d['use'].capitalize()]
        else:
            self.__use = Use.Either

        if 'repeatable' in d:
            self.__repeatable = d['repeatable']
        elif self.__use is not Use.Either:
            self.__repeatable = False

    def __init__(self, width, obj):
        typeof_obj = type(obj)

        if typeof_obj is str:
            self.__init__str(width, obj)
        else:
            self.__init__dict(width, obj)


    def __combinations(self, other):
        if self.__use == Use.Right or other.__use == Use.Left or not self.__repeatable and self == other:
            return []

        can_left = lambda self: self.__use is Use.Either or self.__use is Use.Left
        can_right = lambda self: self.__use is Use.Either or self.__use is Use.Right

        if self.__dict and other.__dict:
            return chain.from_iterable([
                left.combinations(right)
                    for left in filter(can_left, self.__modes)
                        for right in filter(can_right, other.__modes)
            ])
        if self.__dict:
            return chain.from_iterable([
                left.combinations(other) for left in filter(can_left, self.__modes)
            ])
        if other.__dict:
            return chain.from_iterable([
                self.combinations(right) for right in filter(can_right, other.__modes)
            ])
        
        widths = filter(lambda n: n <= self.__maxwidth, [8, 16, 32, 64])

        if self.__scale and other.__scale:
            return [
                (Operand(self.__str, lw), Operand(other.__str, rw))
                    for lw in widths
                        for rw in widths
            ]
        if self.__scale:
            return [
                (Operand(self.__str, width), Operand(other.__str, None)) for width in widths
            ]
        if other.__scale:
            return [
                (Operand(self.__str, None), Operand(other.__str, width)) for width in widths
            ]
        
        return [(Operand(self.__str, None), Operand(other.__str, None))]

    def combinations(self, other):
        return list(self.__combinations(other))

    def unwrap(self):
        if self.__dict:
            return chain.from_iterable(map(OperandTemplate.unwrap, self.__modes))

        if self.__scale:
            return [Operand(self.__str, width) for width in filter(lambda n: n <= self.__maxwidth, [8, 16, 32, 64])]

        return [Operand(self.__str, None)]

    def __eq__(self, other):
        if self.__dict and other.__dict:
            return self.__modes == other.__modes
        
        if not self.__dict and not other.__dict:
            return self.__str == other.__str

        return False

class EncodingOutOfBoundsError(Exception):
    pass

class Instruction(object):
    __encode_cnt = 0

    def __init__(self, namespace, width, obj: dict):
        self.__namespace = namespace
        self.__width = width

        operands = obj['operands']
        self.__num_operands = obj['numoperands']
        if operands == 'none':
            self.__operands = []
        else:
            self.__operands = [OperandTemplate(width, op) for op in operands]

        self.__name = obj['name']

        if 'functions' in obj:
            if 'alias' in obj:
                self.__aliases = obj['alias']
            else:
                self.__aliases = True

            self.__uses_functions = True
            self.__functions = obj['functions']
        else:
            self.__uses_functions = False

    def aliases(self):
        return self.__uses_functions and self.__aliases

    @classmethod
    def __inc_enccnt(cls):
        tmp = cls.__encode_cnt
        inc_tmp = tmp + 1
        if inc_tmp > 0xFF:
            raise EncodingOutOfBoundsError()
        cls.__encode_cnt = inc_tmp
        return tmp

    def __encode_unary(self):
        fmt = '02X'
        namesp = self.__namespace.upper()
        name = self.__name.upper()
        unwrapped = chain.from_iterable(map(OperandTemplate.unwrap, self.__operands))

        if self.__uses_functions:
            if self.__aliases:
                return '\n'.join([f'#define {namesp}_INSTR_{name}{alias.upper()}_{operand} 0x{format(Instruction.__inc_enccnt(), fmt)}'
                                    for operand in unwrapped
                                        for alias in self.__functions])
            else:
                return '\n'.join([
                    '\n'.join([
                        f'#define {namesp}_INSTR_{name}_{operand} 0x{format(Instruction.__inc_enccnt(), fmt)}' for operand in unwrapped
                    ]),
                    '\n'.join([
                        f'#define {namesp}_{name}FUNC_{func.upper()} 0x{format(idx, fmt)}' for idx, func in enumerate(self.__functions)
                    ])
                ])
        else:
            return '\n'.join([f'#define {namesp}_INSTR_{name}_{operand} 0x{format(Instruction.__inc_enccnt(), fmt)}'
                                for operand in unwrapped])

    def __encode_binary(self):
        fmt = '02X'
        namesp = self.__namespace.upper()
        name = self.__name.upper()

        operand_combos = chain.from_iterable([left.combinations(right)
                                                for left in self.__operands
                                                    for right in self.__operands])

        if self.__uses_functions:
            if self.__aliases:
                return '\n'.join(chain.from_iterable([
                    f'#define {namesp}_INSTR_{alias.upper()}_{left}_{right} 0x{format(Instruction.__inc_enccnt(), fmt)}'
                        for left, right in operand_combos
                            for alias in self.__functions
                ]))
            else:
                return '\n'.join([
                    '\n'.join([
                        f'#define {namesp}_INSTR_{name}_{left}_{right} 0x{format(Instruction.__inc_enccnt(), fmt)}'
                            for left, right in operand_combos
                    ]),
                    '\n'.join([
                        f'#define {namesp}_{name}FUNC_{func.upper()} 0x{format(idx, fmt)}' for idx, func in enumerate(self.__functions)
                    ])
                ])
        
        return '\n'.join([
            f'#define {namesp}_INSTR_{name}_{left}_{right} 0x{format(Instruction.__inc_enccnt(), fmt)}' for left, right in operand_combos
        ])

    def encode(self):
        if self.__num_operands == 0:
            fmt = '02X'
            return f'#define {self.__namespace.upper()}_INSTR_{self.__name.upper()} 0x{format(Instruction.__inc_enccnt(), fmt)}'

        if self.__num_operands == 1:
            return self.__encode_unary()

        if self.__num_operands == 2:
            return self.__encode_binary()

    def binary(self):
        return self.__num_operands == 2

    def unary(self):
        return self.__num_operands == 1

    def name(self):
        return self.__name

class InvalidStageError(Exception):
    pass

class CType(object):
    def __init__dict(self, properties: dict):
        cls = type(self)
        self.__properties = {
            prop:cls.get(tn) for prop, tn in properties.items()
        }

    def __init__(self, name: str, properties=None):
        cls = type(self)
        setattr(cls, f'__{name}', self)

        self.__struct = properties is not None
        self.__typename = f'struct {name}' if self.__struct and not name.startswith('struct') else name
        if self.__struct:
            self.__init__dict(properties)

    def typename(self):
        return self.__typename

    def struct(self):
        return self.__struct

    def __eq__(self, other):
        return self.__typename == other.__typename

    def __str__(self):
        return self.__typename

    def __repr__(self):
        return str(self)

    def vardecl(self, name):
        return f'{self} {name};'

    @classmethod
    def get(cls, name):
        return getattr(cls, f'__{name}')

    def props(self):
        if self.__struct:
            return self.__properties
        return {}
        

class DatapathStage(object):
    def __transform_blueprint(self, previous, blueprint):
        blueprint_type = type(blueprint)
    
        if blueprint_type is str:
            if blueprint == '$word':
                return CType(f'{self.__namespace}_word_t').typename()
            if blueprint == '$previous':
                if previous is None:
                    raise InvalidStageError()
                return previous.__output_type.typename()

            return CType(blueprint).typename()


        return { prop:self.__transform_blueprint(previous, bp) for prop, bp in blueprint.items() }

    def __init__(self, namespace: str, previous, obj: dict):
        self.__namespace = namespace
        self.__name = obj['name']

        input_type_blueprint = self.__transform_blueprint(previous, obj['input'])
        output_type_blueprint = self.__transform_blueprint(previous, obj['output'])

        if type(input_type_blueprint) is dict:
            self.__input_type = CType(f'{namespace}_{self.__name}_input_t', input_type_blueprint)
        else:
            self.__input_type = CType(input_type_blueprint)
        
        if type(output_type_blueprint) is dict:
            self.__output_type = CType(f'{namespace}_{self.__name}_output_t', output_type_blueprint)
        else:
            self.__output_type = CType(output_type_blueprint)

    def input_typedef(self):
        newline = '\n\t'
        props = self.__input_type.props()
        return f'''{self.__input_type.typename()} {{
{newline.join([ty.vardecl(name) for name, ty in props.items()])}
}};'''

    def output_typedef(self):
        newline = '\n\t'
        props = self.__output_type.props()
        return f'''{self.__output_type.typename()} {{
    {newline.join([ty.vardecl(name) for name, ty in props.items()])}
}};'''

    def input_type(self):
        return self.__input_type

    def output_type(self):
        return self.__output_type

    def __str__(self):
        return self.__name
        
    
class CFuncPrototype(object):
    def __init__(self, namespace: str, stages: list, instr: Instruction):
        self.__namespace = namespace
        self.__instr = instr
        self.__stages = []

        previous_stage = None
        for stage_def in stages:
            stage = DatapathStage(namespace, previous_stage, stage_def)
            self.__stages.append(stage)
            previous_stage = stage

    def __sig(self, stage: DatapathStage):
        return f'{self.__namespace}_word_t {self.name()}_{stage}(const {stage.input_type()} *in, {stage.output_type()} *out)'

    def __proto(self, stage: DatapathStage):
        sin = stage.input_type()
        sout = stage.output_type()
        proto = f'{self.__sig(stage)};'

        if sin.struct() and sout.struct():
            return '\n'.join(
                [
                    stage.input_typedef(),
                    stage.output_typedef(),
                    proto
                ]
            )

        if sin.struct():
            return '\n'.join(
                [
                    stage.input_typedef(),
                    proto
                ]
            )

        if sout.struct():
            return '\n'.join(
                [
                    stage.output_typedef(),
                    proto
                ]
            )

        return proto

    def protos(self):
        return map(self.__proto, self.__stages)

    def __definition(self, stage: DatapathStage):
        return f'''{self.__sig(stage)} {{
return 0;
}}'''

    def definitions(self):
        return map(self.__definition, self.__stages)

    def name(self):
        return f'{self.__namespace}_instr_{self.__instr.name()}'