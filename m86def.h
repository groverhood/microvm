#ifndef M86DEF_H
#define M86DEF_H

#include <stdint.h>

typedef uint64_t m86_word_t;

// ========== Mini86 Instruction Encodings ==========

// halt
// - terminate the running process
#define M86_INSTR_HALT  0x00

// nop
// - do nothing
#define M86_INSTR_NOP   0x01

// [op]
// - perform an operation between a specified source value (immediate, register, or value stored in memory)
//   and a specified destination (register or memory address) value, and store the result in the destination.
//
// - move byte immediate into the specified register.
#define M86_INSTR_OP_IMM8_REG   0x02
// - move word immediate into the specified register.
#define M86_INSTR_OP_IMM16_REG  0x03
// - move dword immediate into the specified register.
#define M86_INSTR_OP_IMM32_REG  0x04
// - move qword immediate into the specified register.
#define M86_INSTR_OP_IMM64_REG  0x05
// - move zero into the specified register.
#define M86_INSTR_OP_ZERO_REG   0x06
// - move byte immediate into the specified memory address.
#define M86_INSTR_OP_IMM8_MEM   0x07
// - move word immediate into the specified memory address.
#define M86_INSTR_OP_IMM16_MEM  0x08
// - move dword immediate into the specified memory address.
#define M86_INSTR_OP_IMM32_MEM  0x09
// - move qword immediate into the specified memory address.
#define M86_INSTR_OP_IMM64_MEM  0x0A
// - move zero into the specified byte address.
#define M86_INSTR_OP_ZERO_MEM8  0x0B
// - move zero into the specified byte address.
#define M86_INSTR_OP_ZERO_MEM16 0x0C
// - move zero into the specified byte address.
#define M86_INSTR_OP_ZERO_MEM32 0x0D
// - move zero into the specified byte address.
#define M86_INSTR_OP_ZERO_MEM64 0x0E
// - move value of register into another register.
#define M86_INSTR_OP_REG_REG    0x0F
// - move value of register into the specified memory address.
#define M86_INSTR_OP_REG_MEM    0x10
// - move value stored at address into specified register.
#define M86_INSTR_OP_MEM_REG    0x11

// operation functons
// 
// - store value of source into the destination
#define M86_OPFUN_MOV     0x00
// - store sum of source and destination into the destination
#define M86_OPFUN_ADD     0x01
// - store difference of source and destination into the destination
#define M86_OPFUN_SUB     0x02
// - store product of source and destination into the destination
#define M86_OPFUN_MUL     0x03
// - store quotient of source and destination into the destination,
//   and the remainder into %r12.
#define M86_OPFUN_DIV     0x04
// - store bitwise and product of source and destination into the destination
#define M86_OPFUN_AND     0x05
// - store bitwise or product of source and destination into the destination
#define M86_OPFUN_OR      0x06
// - store bitwise xor product of source and destination into the destination
#define M86_OPFUN_XOR     0x07
// - performs bitwise and of source and destination into the destination, but
//   only stores condition codes
#define M86_OPFUN_TEST    0x08


// cmov
// - move the value of one register to another depending on the current condition code
//
// - move if sf is set
#define M86_INSTR_CMOV_LESS             0x12
// - move if sf or zf are set
#define M86_INSTR_CMOV_LESS_EQUAL       0x13
// - move if zf is set
#define M86_INSTR_CMOV_EQUAL            0x14
// - move if zf is set and sf isn't set
#define M86_INSTR_CMOV_GREATER_EQUAL    0x15
// - move if neither zf or sf is set
#define M86_INSTR_CMOV_GREATER          0x16

// lea
// - compute an address using the form r1 + r2 * s + c and load it into the destination register
//
// - compute address using r1, r2, s, 8-bit c
#define M86_INSTR_LEA_R1R2SC    0x17
// - compute address using r1, r2, s, 16-bit c
#define M86_INSTR_LEA_R1R2SC    0x18
// - compute address using r1, r2, s, 32-bit c
#define M86_INSTR_LEA_R1R2SC    0x19
// - compute address using r1, r2, s, 64-bit c
#define M86_INSTR_LEA_R1R2SC    0x1A
// - compute address using r1, r2, s
#define M86_INSTR_LEA_R1R2S     0x1B
// - compute address using r1, r2
#define M86_INSTR_LEA_R1R2      0x1C
// - compute address using r1
#define M86_INSTR_LEA_R1        0x1D
// - compute address using r2, s, 8-bit c
#define M86_INSTR_LEA_R2SC8     0x1E
// - compute address using r2, s, 16-bit c
#define M86_INSTR_LEA_R2SC16    0x1F
// - compute address using r2, s, 32-bit c
#define M86_INSTR_LEA_R2SC32    0x20
// - compute address using r2, s, 64-bit c
#define M86_INSTR_LEA_R2SC64    0x21
// - compute address using r2, s
#define M86_INSTR_LEA_R2S       0x22
// - compute address using 8-bit c
#define M86_INSTR_LEA_C8        0x23
// - compute address using 16-bit c
#define M86_INSTR_LEA_C16       0x24
// - compute address using 32-bit c
#define M86_INSTR_LEA_C32       0x25
// - compute address using 64-bit c
#define M86_INSTR_LEA_C64       0x26



#endif