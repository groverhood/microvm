
import scripts.genutils as genutils
import argparse
import json
import os
import itertools
import functools

def genfprotov(obj: dict):
    namesp = obj['name']
    stages = obj['stages']
    width = obj['width']

    return [genutils.CFuncPrototype(namesp, stages, genutils.Instruction(namesp, width, instr))
                for instr in obj['instructions']]

def genfproto(input_file, output_file):
    with open(input_file, 'r') as rs:
        defs = json.load(rs)
        cfuncps = genfprotov(defs)
        stages = cfuncps[0].stages()

        name = defs['name']
        upper = name.upper()

        with open(output_file, 'w') as ws:
            listify = lambda names: ',\n\t'.join(names)

            typedefs = '\n\n'.join(genutils.unique(itertools.chain.from_iterable(map(genutils.CFuncPrototype.typedefs, cfuncps))))
            protos = '\n\n'.join(genutils.unique(itertools.chain.from_iterable(map(genutils.CFuncPrototype.protos, cfuncps))))
            stage_typedefs = '\n\n'.join(map(genutils.DatapathStage.function_typedef, stages))
            stage_funbfers = '\n\n'.join([f'const {stage.gname()} = {{\n\t{listify(itertools.chain.from_iterable([cfunc.names(stage) for cfunc in cfuncps ]))}\n}};' 
                                            for stage in stages])

            ws.write(f'''#ifndef {upper}FPROTO_H
#define {upper}FPROTO_H

#include <{name}def.h>

{typedefs}

{protos}

{stage_typedefs}

{stage_funbfers}

#endif''')

def main():
    parser = argparse.ArgumentParser('genfproto')
    parser.add_argument('--file', '-f', type=str, default=f'{os.getcwd()}/.vmdefs', dest='input_file')
    parser.add_argument('--out', '-o', type=str, dest='output_file')

    argv = parser.parse_args()

    genfproto(argv.input_file, argv.output_file)
    
if __name__ == '__main__':
    main()