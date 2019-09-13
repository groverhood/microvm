#ifndef M86DEF_H
#define M86DEF_H

#define M86_VER 0

#include <stdint.h>

typedef uint64_t m86_word_t;

#define M86_INSTR_HALT 0x00
#define M86_INSTR_OP_ZERO8REG 0x01
#define M86_INSTR_OP_ZERO16REG 0x02
#define M86_INSTR_OP_ZERO32REG 0x03
#define M86_INSTR_OP_ZERO64REG 0x04
#define M86_INSTR_OP_ZERO8MEM 0x05
#define M86_INSTR_OP_ZERO16MEM 0x06
#define M86_INSTR_OP_ZERO32MEM 0x07
#define M86_INSTR_OP_ZERO64MEM 0x08
#define M86_INSTR_OP_REGREG 0x09
#define M86_INSTR_OP_REGMEM 0x0A
#define M86_INSTR_OP_IMM8REG 0x0B
#define M86_INSTR_OP_IMM16REG 0x0C
#define M86_INSTR_OP_IMM32REG 0x0D
#define M86_INSTR_OP_IMM64REG 0x0E
#define M86_INSTR_OP_IMM8MEM 0x0F
#define M86_INSTR_OP_IMM16MEM 0x10
#define M86_INSTR_OP_IMM32MEM 0x11
#define M86_INSTR_OP_IMM64MEM 0x12
#define M86_INSTR_OP_MEMREG 0x13
#define M86_OPFUNC_MOV 0x00
#define M86_OPFUNC_ADD 0x01
#define M86_OPFUNC_SUB 0x02
#define M86_OPFUNC_MUL 0x03
#define M86_OPFUNC_DIV 0x04
#define M86_OPFUNC_AND 0x05
#define M86_OPFUNC_OR 0x06
#define M86_OPFUNC_XOR 0x07
#define M86_OPFUNC_CMP 0x08
#define M86_OPFUNC_TEST 0x09
#define M86_INSTR_LEA_R1R2SC8REG 0x14
#define M86_INSTR_LEA_R1R2SC16REG 0x15
#define M86_INSTR_LEA_R1R2SC32REG 0x16
#define M86_INSTR_LEA_R1R2SC64REG 0x17
#define M86_INSTR_LEA_R1R2SREG 0x18
#define M86_INSTR_LEA_R1R2C8REG 0x19
#define M86_INSTR_LEA_R1R2C16REG 0x1A
#define M86_INSTR_LEA_R1R2C32REG 0x1B
#define M86_INSTR_LEA_R1R2C64REG 0x1C
#define M86_INSTR_LEA_R1R2REG 0x1D
#define M86_INSTR_LEA_R1C8REG 0x1E
#define M86_INSTR_LEA_R1C16REG 0x1F
#define M86_INSTR_LEA_R1C32REG 0x20
#define M86_INSTR_LEA_R1C64REG 0x21
#define M86_INSTR_LEA_R2SC8REG 0x22
#define M86_INSTR_LEA_R2SC16REG 0x23
#define M86_INSTR_LEA_R2SC32REG 0x24
#define M86_INSTR_LEA_R2SC64REG 0x25
#define M86_INSTR_LEA_R2SREG 0x26
#define M86_INSTR_LEA_R1REG 0x27
#define M86_INSTR_LEA_C8REG 0x28
#define M86_INSTR_LEA_C16REG 0x29
#define M86_INSTR_LEA_C32REG 0x2A
#define M86_INSTR_LEA_C64REG 0x2B

#endif
        