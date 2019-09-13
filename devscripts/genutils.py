
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

    def __eq__(self, other):
        if self.__dict and other.__dict:
            return self.__modes == other.__modes
        
        if not self.__dict and not other.__dict:
            return self.__str == other.__str

        return False

class Instruction(object):
    __encode_cnt = 0

    def __init__(self, namespace, width, obj: dict):
        self.__namespace = namespace
        self.__width = width

        operands = obj['operands']
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
        cls.__encode_cnt = tmp + 1
        return tmp

    def encode(self):
        fmt = '02X'
        namesp = self.__namespace.upper()
        name = self.__name.upper()

        operand_combos = chain.from_iterable([left.combinations(right)
                                                for left in self.__operands
                                                    for right in self.__operands])

        if self.__uses_functions:
            if self.__aliases:
                return '\n'.join(chain.from_iterable([
                    f'#define {namesp}_INSTR_{alias.upper()}_{left.combinations(right)} 0x{format(Instruction.__inc_enccnt(), fmt)}'
                        for left, right in operand_combos
                            for alias in self.__functions
                ]))
            else:
                return '\n'.join([
                    '\n'.join(
                        f'#define {namesp}_INSTR_{name}_{left}{right} 0x{format(Instruction.__inc_enccnt(), fmt)}'
                            for left, right in operand_combos
                    ),
                    '\n'.join(
                        f'#define {namesp}_{name}FUNC_{func.upper()} 0x{format(idx, fmt)}' for idx, func in enumerate(self.__functions)
                    )
                ])
        
        if len(self.__operands) > 0:
            return '\n'.join([
                f'#define {namesp}_INSTR_{name}_{left}{right} 0x{format(Instruction.__inc_enccnt(), fmt)}' for left, right in operand_combos
            ])
        
        return f'#define {namesp}_INSTR_{name} 0x{format(Instruction.__inc_enccnt(), fmt)}'
