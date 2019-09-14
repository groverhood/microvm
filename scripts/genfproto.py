
import scripts.genutils as genutils
import argparse
import json
import os
import itertools

def genfprotov(obj: dict):
    namesp = obj['name']
    stages = obj['stages']
    width = obj['width']

    return [genutils.CFuncPrototype(namesp, stages, genutils.Instruction(namesp, width, instr))
                for instr in obj['instructions']]

def genfproto(input_file, output_file, genimp):
    with open(input_file, 'r') as rs:
        defs = json.load(rs)
        cfuncps = genfprotov(defs)

        name = defs['name']
        upper = name.upper()

        if genimp:
            _, _, filename = output_file.rpartition('/').replace('.h', '.c')
            source_output_file = f'{os.getcwd()}/src/{filename}'

            with open(source_output_file, 'w') as ws:
                ws.write('\n\n'.join(itertools.chain.from_iterable(map(genutils.CFuncPrototype.definitions, cfuncps))))

        with open(output_file, 'w') as ws:
            content = '\n\n'.join(itertools.chain.from_iterable(map(genutils.CFuncPrototype.protos, cfuncps)))
            ws.write(f'''#ifndef {upper}FPROTO_H
#define {upper}FPROTO_H

#include <{name}def.h>

{content}

#endif''')

def main():
    parser = argparse.ArgumentParser('genfproto')
    parser.add_argument('--implement', '-imp', dest='implement', action='store_true')
    parser.add_argument('--file', '-f', type=str, default=f'{os.getcwd()}/.vmdefs', dest='input_file')
    parser.add_argument('--out', '-o', type=str, dest='output_file')

    argv = parser.parse_args()

    genfproto(argv.input_file, argv.output_file, argv.implement)
    
if __name__ == '__main__':
    main()