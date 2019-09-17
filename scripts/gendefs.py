
import json
import argparse
import scripts.genutils as genutils
import itertools

def gendefs(input_file, output_file):
    with open(input_file, 'r') as rs:
        obj = json.load(rs)
        name = obj['name']
        version = obj['version']
        width = obj['width']
        fmt = '02X'

        instructions = [genutils.Instruction(name, width, instr) for instr in obj['instructions']]
        registers = [genutils.Register(name, width, reg) for reg in obj['registers']]

        required_headers = '\n'.join([f'#include <{name}>' for name in obj['dependencies']['gendefs']])
        instr_encodings = '\n'.join(map(genutils.Instruction.encode, instructions))
        regcmb_encodings = '\n'.join([left.encode_combinations(right) 
                                    for left in registers
                                        for right in registers])
        reg_encodings = '\n'.join([f'#define {name.upper()}_REG_{reg} 0x{format(idx, fmt)}' for idx, reg in enumerate(map(str, registers))])  

        output = f'''#ifndef {name.upper()}DEF_H
#define {name.upper()}DEF_H

#define {name.upper()}_VER {version}

#include <stdint.h>
{required_headers}

typedef uint{width}_t {name}_word_t;

{instr_encodings}

#define {name.upper()}_REGCOUNT {len(registers)}

{regcmb_encodings}

{reg_encodings}

#endif'''

        if output_file == 'stdout':
            print(output)
        else:
            with open(output_file, 'w') as ws:
                ws.write(output)

def main():
    parser = argparse.ArgumentParser('gendefs')
    parser.add_argument('-f', '--file', dest='file', nargs='?', default='.vmdefs', type=str)
    parser.add_argument('-o', '--out', dest='out', nargs='?', default='stdout', type=str)

    argv = parser.parse_args()
    gendefs(argv.file, argv.out)
