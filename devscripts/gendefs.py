
import json

import genutils

def gendefs(input_file, output_file):
    with open(input_file, 'r') as rs:
        obj = json.load(rs)
        name = obj['name']
        version = obj['version']
        width = obj['width']

        instructions = [genutils.Instruction(name, width, instr) for instr in obj['instructions']]

        newline = '\n'

        output = f'''#ifndef {name.upper()}DEF_H
#define {name.upper()}DEF_H

#define {name.upper()}_VER {version}

#include <stdint.h>

typedef uint{width}_t {name}_word_t;

{newline.join(map(genutils.Instruction.encode, instructions))}

#endif
        '''

        if output_file == 'stdout':
            print(output)
        with open(output_file, 'w') as ws:
            ws.write(output)

if __name__ == '__main__':
    gendefs('.vmdefs', 'inc/m86def.h')