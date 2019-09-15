#ifndef M86FPROTO_H
#define M86FPROTO_H

#include <m86def.h>

struct m86_fetch_output_t {
    int instr;
	int func;
	int r_a;
	int r_b;
	int r_c;
	m86_word_t val_c1;
	m86_word_t val_c2;
	int val_s;
	uint8_t* predicted_val_p;
};

struct m86_decode_output_t {
    
};

m86_word_t op_zero32_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r1c16_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_zero16_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_reg_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r2sc64_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_c8_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t set_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r1c64_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_c8_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_c64_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t set_mem_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_zero64_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_reg_mem_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r1r2c8_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_zero32_mem_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r2sc16_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r1c32_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r1r2sc64_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_imm8_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_imm16_mem_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r1_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_r1c8_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r2sc32_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_imm64_mem_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t halt_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_r1r2sc8_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_imm32_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_imm64_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r2s_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r1r2c16_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t set_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_zero16_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r1r2sc8_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_zero8_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t set_mem_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r1r2c32_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_r1r2_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r1r2s_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_r2sc32_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_r1r2c8_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_imm16_mem_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_r1_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_zero8_mem_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t halt_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_zero32_mem_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_reg_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_r2sc8_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_mem_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_imm64_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_zero64_mem_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r1r2sc64_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r1r2s_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r1r2sc16_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_r1c32_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_r2sc8_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_r2sc16_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_zero8_mem_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_imm8_mem_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_imm8_mem_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_r1c16_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_imm8_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_r1r2c16_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r2s_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_zero64_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_imm16_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_reg_mem_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_imm32_mem_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r1c64_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_c32_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_zero64_mem_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_c64_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_c32_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r1r2c32_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_c16_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r1r2c64_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_r1r2_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_imm32_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r1c8_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_r1r2sc16_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r1r2c64_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r2sc64_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_c16_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_zero16_mem_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_zero32_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_imm16_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_r1r2sc32_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_mem_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_imm32_mem_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_r1r2sc32_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_zero8_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_zero16_mem_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_imm64_mem_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

typedef m86_word_t (*fetch_handler)(uint8_t*, struct m86_fetch_output_t*);

typedef m86_word_t (*decode_handler)(struct m86_fetch_output_t*, struct m86_decode_output_t*);

const fetch_handler fetch_handlers[] = {
	halt_fetch,
	op_zero8_reg_fetch,
	op_zero16_reg_fetch,
	op_zero32_reg_fetch,
	op_zero64_reg_fetch,
	op_zero8_mem_fetch,
	op_zero16_mem_fetch,
	op_zero32_mem_fetch,
	op_zero64_mem_fetch,
	op_reg_reg_fetch,
	op_reg_mem_fetch,
	op_imm8_reg_fetch,
	op_imm16_reg_fetch,
	op_imm32_reg_fetch,
	op_imm64_reg_fetch,
	op_imm8_mem_fetch,
	op_imm16_mem_fetch,
	op_imm32_mem_fetch,
	op_imm64_mem_fetch,
	op_mem_reg_fetch,
	lea_r1r2sc8_reg_fetch,
	lea_r1r2sc16_reg_fetch,
	lea_r1r2sc32_reg_fetch,
	lea_r1r2sc64_reg_fetch,
	lea_r1r2s_reg_fetch,
	lea_r1r2c8_reg_fetch,
	lea_r1r2c16_reg_fetch,
	lea_r1r2c32_reg_fetch,
	lea_r1r2c64_reg_fetch,
	lea_r1r2_reg_fetch,
	lea_r1c8_reg_fetch,
	lea_r1c16_reg_fetch,
	lea_r1c32_reg_fetch,
	lea_r1c64_reg_fetch,
	lea_r2sc8_reg_fetch,
	lea_r2sc16_reg_fetch,
	lea_r2sc32_reg_fetch,
	lea_r2sc64_reg_fetch,
	lea_r2s_reg_fetch,
	lea_r1_reg_fetch,
	lea_c8_reg_fetch,
	lea_c16_reg_fetch,
	lea_c32_reg_fetch,
	lea_c64_reg_fetch,
	set_reg_fetch,
	set_mem_fetch
};

const decode_handler decode_handlers[] = {
	halt_decode,
	op_zero8_reg_decode,
	op_zero16_reg_decode,
	op_zero32_reg_decode,
	op_zero64_reg_decode,
	op_zero8_mem_decode,
	op_zero16_mem_decode,
	op_zero32_mem_decode,
	op_zero64_mem_decode,
	op_reg_reg_decode,
	op_reg_mem_decode,
	op_imm8_reg_decode,
	op_imm16_reg_decode,
	op_imm32_reg_decode,
	op_imm64_reg_decode,
	op_imm8_mem_decode,
	op_imm16_mem_decode,
	op_imm32_mem_decode,
	op_imm64_mem_decode,
	op_mem_reg_decode,
	lea_r1r2sc8_reg_decode,
	lea_r1r2sc16_reg_decode,
	lea_r1r2sc32_reg_decode,
	lea_r1r2sc64_reg_decode,
	lea_r1r2s_reg_decode,
	lea_r1r2c8_reg_decode,
	lea_r1r2c16_reg_decode,
	lea_r1r2c32_reg_decode,
	lea_r1r2c64_reg_decode,
	lea_r1r2_reg_decode,
	lea_r1c8_reg_decode,
	lea_r1c16_reg_decode,
	lea_r1c32_reg_decode,
	lea_r1c64_reg_decode,
	lea_r2sc8_reg_decode,
	lea_r2sc16_reg_decode,
	lea_r2sc32_reg_decode,
	lea_r2sc64_reg_decode,
	lea_r2s_reg_decode,
	lea_r1_reg_decode,
	lea_c8_reg_decode,
	lea_c16_reg_decode,
	lea_c32_reg_decode,
	lea_c64_reg_decode,
	set_reg_decode,
	set_mem_decode
};

#endif