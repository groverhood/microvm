#ifndef M86FPROTO_H
#define M86FPROTO_H

#include <m86def.h>
#include <m86cpu.h>

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
	int instr;
	int func;
	m86_word_t val_a;
	m86_word_t val_b;
	m86_word_t dest_m;
	int dest_e;
	int size_dest_m;
	int size_dest_e;
	uint8_t* predicted_val_p;
};

struct m86_execute_output_t {
	int instr;
	int func;
	m86_word_t val_e;
	int cc;
	m86_word_t dest_m;
	int dest_e;
	int size_dest_m;
	int size_dest_e;
	uint8_t* predicted_val_p;
};

struct m86_memory_output_t {
	int instr;
	int func;
	m86_word_t val_e;
	m86_word_t val_m;
	int cc;
	m86_word_t dest_m;
	int dest_e;
	int size_dest_m;
	int size_dest_e;
	uint8_t* predicted_val_p;
};

m86_word_t halt_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t halt_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t halt_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t halt_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t halt_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_zero8_reg8_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_zero8_reg16_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_zero8_reg32_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_zero8_reg64_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_zero16_reg16_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_zero16_reg32_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_zero16_reg64_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_zero32_reg32_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_zero32_reg64_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_zero64_reg64_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_zero8_mem_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_zero16_mem_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_zero32_mem_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_zero64_mem_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_reg8_reg8_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_reg8_reg16_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_reg8_reg32_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_reg8_reg64_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_reg16_reg16_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_reg16_reg32_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_reg16_reg64_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_reg32_reg32_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_reg32_reg64_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_reg64_reg64_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_reg8_mem_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_reg16_mem_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_reg32_mem_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_reg64_mem_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_imm8_reg8_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_imm8_reg16_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_imm8_reg32_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_imm8_reg64_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_imm16_reg16_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_imm16_reg32_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_imm16_reg64_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_imm32_reg32_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_imm32_reg64_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_imm64_reg64_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_imm8_mem_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_imm16_mem_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_imm32_mem_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_imm64_mem_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_mem_reg8_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_mem_reg16_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_mem_reg32_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_mem_reg64_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t op_zero8_reg8_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_zero8_reg16_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_zero8_reg32_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_zero8_reg64_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_zero16_reg16_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_zero16_reg32_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_zero16_reg64_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_zero32_reg32_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_zero32_reg64_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_zero64_reg64_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_zero8_mem_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_zero16_mem_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_zero32_mem_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_zero64_mem_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_reg8_reg8_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_reg8_reg16_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_reg8_reg32_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_reg8_reg64_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_reg16_reg16_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_reg16_reg32_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_reg16_reg64_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_reg32_reg32_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_reg32_reg64_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_reg64_reg64_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_reg8_mem_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_reg16_mem_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_reg32_mem_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_reg64_mem_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_imm8_reg8_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_imm8_reg16_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_imm8_reg32_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_imm8_reg64_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_imm16_reg16_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_imm16_reg32_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_imm16_reg64_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_imm32_reg32_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_imm32_reg64_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_imm64_reg64_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_imm8_mem_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_imm16_mem_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_imm32_mem_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_imm64_mem_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_mem_reg8_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_mem_reg16_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_mem_reg32_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_mem_reg64_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t op_zero8_reg8_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_zero8_reg16_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_zero8_reg32_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_zero8_reg64_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_zero16_reg16_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_zero16_reg32_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_zero16_reg64_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_zero32_reg32_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_zero32_reg64_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_zero64_reg64_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_zero8_mem_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_zero16_mem_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_zero32_mem_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_zero64_mem_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_reg8_reg8_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_reg8_reg16_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_reg8_reg32_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_reg8_reg64_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_reg16_reg16_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_reg16_reg32_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_reg16_reg64_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_reg32_reg32_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_reg32_reg64_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_reg64_reg64_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_reg8_mem_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_reg16_mem_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_reg32_mem_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_reg64_mem_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_imm8_reg8_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_imm8_reg16_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_imm8_reg32_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_imm8_reg64_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_imm16_reg16_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_imm16_reg32_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_imm16_reg64_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_imm32_reg32_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_imm32_reg64_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_imm64_reg64_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_imm8_mem_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_imm16_mem_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_imm32_mem_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_imm64_mem_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_mem_reg8_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_mem_reg16_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_mem_reg32_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_mem_reg64_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t op_zero8_reg8_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_zero8_reg16_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_zero8_reg32_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_zero8_reg64_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_zero16_reg16_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_zero16_reg32_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_zero16_reg64_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_zero32_reg32_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_zero32_reg64_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_zero64_reg64_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_zero8_mem_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_zero16_mem_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_zero32_mem_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_zero64_mem_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_reg8_reg8_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_reg8_reg16_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_reg8_reg32_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_reg8_reg64_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_reg16_reg16_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_reg16_reg32_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_reg16_reg64_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_reg32_reg32_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_reg32_reg64_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_reg64_reg64_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_reg8_mem_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_reg16_mem_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_reg32_mem_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_reg64_mem_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_imm8_reg8_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_imm8_reg16_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_imm8_reg32_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_imm8_reg64_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_imm16_reg16_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_imm16_reg32_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_imm16_reg64_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_imm32_reg32_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_imm32_reg64_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_imm64_reg64_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_imm8_mem_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_imm16_mem_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_imm32_mem_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_imm64_mem_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_mem_reg8_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_mem_reg16_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_mem_reg32_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_mem_reg64_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t op_zero8_reg8_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_zero8_reg16_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_zero8_reg32_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_zero8_reg64_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_zero16_reg16_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_zero16_reg32_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_zero16_reg64_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_zero32_reg32_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_zero32_reg64_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_zero64_reg64_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_zero8_mem_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_zero16_mem_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_zero32_mem_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_zero64_mem_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_reg8_reg8_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_reg8_reg16_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_reg8_reg32_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_reg8_reg64_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_reg16_reg16_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_reg16_reg32_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_reg16_reg64_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_reg32_reg32_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_reg32_reg64_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_reg64_reg64_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_reg8_mem_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_reg16_mem_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_reg32_mem_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_reg64_mem_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_imm8_reg8_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_imm8_reg16_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_imm8_reg32_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_imm8_reg64_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_imm16_reg16_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_imm16_reg32_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_imm16_reg64_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_imm32_reg32_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_imm32_reg64_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_imm64_reg64_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_imm8_mem_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_imm16_mem_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_imm32_mem_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_imm64_mem_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_mem_reg8_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_mem_reg16_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_mem_reg32_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t op_mem_reg64_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t lea_r1r2sc8_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r1r2sc16_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r1r2sc32_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r1r2sc64_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r1r2s_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r1r2c8_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r1r2c16_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r1r2c32_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r1r2c64_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r1r2_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r1c8_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r1c16_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r1c32_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r1c64_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r2sc8_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r2sc16_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r2sc32_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r2sc64_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r2s_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r1_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_c8_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_c16_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_c32_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_c64_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t lea_r1r2sc8_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_r1r2sc16_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_r1r2sc32_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_r1r2sc64_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_r1r2s_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_r1r2c8_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_r1r2c16_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_r1r2c32_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_r1r2c64_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_r1r2_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_r1c8_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_r1c16_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_r1c32_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_r1c64_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_r2sc8_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_r2sc16_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_r2sc32_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_r2sc64_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_r2s_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_r1_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_c8_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_c16_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_c32_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_c64_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t lea_r1r2sc8_reg_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t lea_r1r2sc16_reg_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t lea_r1r2sc32_reg_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t lea_r1r2sc64_reg_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t lea_r1r2s_reg_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t lea_r1r2c8_reg_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t lea_r1r2c16_reg_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t lea_r1r2c32_reg_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t lea_r1r2c64_reg_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t lea_r1r2_reg_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t lea_r1c8_reg_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t lea_r1c16_reg_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t lea_r1c32_reg_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t lea_r1c64_reg_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t lea_r2sc8_reg_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t lea_r2sc16_reg_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t lea_r2sc32_reg_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t lea_r2sc64_reg_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t lea_r2s_reg_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t lea_r1_reg_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t lea_c8_reg_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t lea_c16_reg_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t lea_c32_reg_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t lea_c64_reg_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t lea_r1r2sc8_reg_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t lea_r1r2sc16_reg_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t lea_r1r2sc32_reg_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t lea_r1r2sc64_reg_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t lea_r1r2s_reg_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t lea_r1r2c8_reg_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t lea_r1r2c16_reg_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t lea_r1r2c32_reg_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t lea_r1r2c64_reg_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t lea_r1r2_reg_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t lea_r1c8_reg_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t lea_r1c16_reg_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t lea_r1c32_reg_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t lea_r1c64_reg_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t lea_r2sc8_reg_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t lea_r2sc16_reg_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t lea_r2sc32_reg_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t lea_r2sc64_reg_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t lea_r2s_reg_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t lea_r1_reg_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t lea_c8_reg_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t lea_c16_reg_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t lea_c32_reg_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t lea_c64_reg_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t lea_r1r2sc8_reg_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t lea_r1r2sc16_reg_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t lea_r1r2sc32_reg_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t lea_r1r2sc64_reg_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t lea_r1r2s_reg_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t lea_r1r2c8_reg_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t lea_r1r2c16_reg_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t lea_r1r2c32_reg_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t lea_r1r2c64_reg_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t lea_r1r2_reg_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t lea_r1c8_reg_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t lea_r1c16_reg_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t lea_r1c32_reg_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t lea_r1c64_reg_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t lea_r2sc8_reg_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t lea_r2sc16_reg_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t lea_r2sc32_reg_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t lea_r2sc64_reg_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t lea_r2s_reg_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t lea_r1_reg_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t lea_c8_reg_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t lea_c16_reg_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t lea_c32_reg_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t lea_c64_reg_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t set_reg_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t set_mem_fetch(uint8_t* in, struct m86_fetch_output_t* out);

m86_word_t set_reg_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t set_mem_decode(struct m86_fetch_output_t* in, struct m86_decode_output_t* out);

m86_word_t set_reg_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t set_mem_execute(struct m86_decode_output_t* in, struct m86_execute_output_t* out);

m86_word_t set_reg_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t set_mem_memory(struct m86_execute_output_t* in, struct m86_memory_output_t* out);

m86_word_t set_reg_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

m86_word_t set_mem_write(struct m86_memory_output_t* in, struct m86_cpu_state_t* out);

typedef m86_word_t (*fetch_handler)(uint8_t*, struct m86_fetch_output_t*);

typedef m86_word_t (*decode_handler)(struct m86_fetch_output_t*, struct m86_decode_output_t*);

typedef m86_word_t (*execute_handler)(struct m86_decode_output_t*, struct m86_execute_output_t*);

typedef m86_word_t (*memory_handler)(struct m86_execute_output_t*, struct m86_memory_output_t*);

typedef m86_word_t (*write_handler)(struct m86_memory_output_t*, struct m86_cpu_state_t*);

const fetch_handler fetch_handlers[] = {
	halt_fetch,
	op_zero8_reg8_fetch,
	op_zero8_reg16_fetch,
	op_zero8_reg32_fetch,
	op_zero8_reg64_fetch,
	op_zero16_reg16_fetch,
	op_zero16_reg32_fetch,
	op_zero16_reg64_fetch,
	op_zero32_reg32_fetch,
	op_zero32_reg64_fetch,
	op_zero64_reg64_fetch,
	op_zero8_mem_fetch,
	op_zero16_mem_fetch,
	op_zero32_mem_fetch,
	op_zero64_mem_fetch,
	op_reg8_reg8_fetch,
	op_reg8_reg16_fetch,
	op_reg8_reg32_fetch,
	op_reg8_reg64_fetch,
	op_reg16_reg16_fetch,
	op_reg16_reg32_fetch,
	op_reg16_reg64_fetch,
	op_reg32_reg32_fetch,
	op_reg32_reg64_fetch,
	op_reg64_reg64_fetch,
	op_reg8_mem_fetch,
	op_reg16_mem_fetch,
	op_reg32_mem_fetch,
	op_reg64_mem_fetch,
	op_imm8_reg8_fetch,
	op_imm8_reg16_fetch,
	op_imm8_reg32_fetch,
	op_imm8_reg64_fetch,
	op_imm16_reg16_fetch,
	op_imm16_reg32_fetch,
	op_imm16_reg64_fetch,
	op_imm32_reg32_fetch,
	op_imm32_reg64_fetch,
	op_imm64_reg64_fetch,
	op_imm8_mem_fetch,
	op_imm16_mem_fetch,
	op_imm32_mem_fetch,
	op_imm64_mem_fetch,
	op_mem_reg8_fetch,
	op_mem_reg16_fetch,
	op_mem_reg32_fetch,
	op_mem_reg64_fetch,
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
	op_zero8_reg8_decode,
	op_zero8_reg16_decode,
	op_zero8_reg32_decode,
	op_zero8_reg64_decode,
	op_zero16_reg16_decode,
	op_zero16_reg32_decode,
	op_zero16_reg64_decode,
	op_zero32_reg32_decode,
	op_zero32_reg64_decode,
	op_zero64_reg64_decode,
	op_zero8_mem_decode,
	op_zero16_mem_decode,
	op_zero32_mem_decode,
	op_zero64_mem_decode,
	op_reg8_reg8_decode,
	op_reg8_reg16_decode,
	op_reg8_reg32_decode,
	op_reg8_reg64_decode,
	op_reg16_reg16_decode,
	op_reg16_reg32_decode,
	op_reg16_reg64_decode,
	op_reg32_reg32_decode,
	op_reg32_reg64_decode,
	op_reg64_reg64_decode,
	op_reg8_mem_decode,
	op_reg16_mem_decode,
	op_reg32_mem_decode,
	op_reg64_mem_decode,
	op_imm8_reg8_decode,
	op_imm8_reg16_decode,
	op_imm8_reg32_decode,
	op_imm8_reg64_decode,
	op_imm16_reg16_decode,
	op_imm16_reg32_decode,
	op_imm16_reg64_decode,
	op_imm32_reg32_decode,
	op_imm32_reg64_decode,
	op_imm64_reg64_decode,
	op_imm8_mem_decode,
	op_imm16_mem_decode,
	op_imm32_mem_decode,
	op_imm64_mem_decode,
	op_mem_reg8_decode,
	op_mem_reg16_decode,
	op_mem_reg32_decode,
	op_mem_reg64_decode,
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

const execute_handler execute_handlers[] = {
	halt_execute,
	op_zero8_reg8_execute,
	op_zero8_reg16_execute,
	op_zero8_reg32_execute,
	op_zero8_reg64_execute,
	op_zero16_reg16_execute,
	op_zero16_reg32_execute,
	op_zero16_reg64_execute,
	op_zero32_reg32_execute,
	op_zero32_reg64_execute,
	op_zero64_reg64_execute,
	op_zero8_mem_execute,
	op_zero16_mem_execute,
	op_zero32_mem_execute,
	op_zero64_mem_execute,
	op_reg8_reg8_execute,
	op_reg8_reg16_execute,
	op_reg8_reg32_execute,
	op_reg8_reg64_execute,
	op_reg16_reg16_execute,
	op_reg16_reg32_execute,
	op_reg16_reg64_execute,
	op_reg32_reg32_execute,
	op_reg32_reg64_execute,
	op_reg64_reg64_execute,
	op_reg8_mem_execute,
	op_reg16_mem_execute,
	op_reg32_mem_execute,
	op_reg64_mem_execute,
	op_imm8_reg8_execute,
	op_imm8_reg16_execute,
	op_imm8_reg32_execute,
	op_imm8_reg64_execute,
	op_imm16_reg16_execute,
	op_imm16_reg32_execute,
	op_imm16_reg64_execute,
	op_imm32_reg32_execute,
	op_imm32_reg64_execute,
	op_imm64_reg64_execute,
	op_imm8_mem_execute,
	op_imm16_mem_execute,
	op_imm32_mem_execute,
	op_imm64_mem_execute,
	op_mem_reg8_execute,
	op_mem_reg16_execute,
	op_mem_reg32_execute,
	op_mem_reg64_execute,
	lea_r1r2sc8_reg_execute,
	lea_r1r2sc16_reg_execute,
	lea_r1r2sc32_reg_execute,
	lea_r1r2sc64_reg_execute,
	lea_r1r2s_reg_execute,
	lea_r1r2c8_reg_execute,
	lea_r1r2c16_reg_execute,
	lea_r1r2c32_reg_execute,
	lea_r1r2c64_reg_execute,
	lea_r1r2_reg_execute,
	lea_r1c8_reg_execute,
	lea_r1c16_reg_execute,
	lea_r1c32_reg_execute,
	lea_r1c64_reg_execute,
	lea_r2sc8_reg_execute,
	lea_r2sc16_reg_execute,
	lea_r2sc32_reg_execute,
	lea_r2sc64_reg_execute,
	lea_r2s_reg_execute,
	lea_r1_reg_execute,
	lea_c8_reg_execute,
	lea_c16_reg_execute,
	lea_c32_reg_execute,
	lea_c64_reg_execute,
	set_reg_execute,
	set_mem_execute
};

const memory_handler memory_handlers[] = {
	halt_memory,
	op_zero8_reg8_memory,
	op_zero8_reg16_memory,
	op_zero8_reg32_memory,
	op_zero8_reg64_memory,
	op_zero16_reg16_memory,
	op_zero16_reg32_memory,
	op_zero16_reg64_memory,
	op_zero32_reg32_memory,
	op_zero32_reg64_memory,
	op_zero64_reg64_memory,
	op_zero8_mem_memory,
	op_zero16_mem_memory,
	op_zero32_mem_memory,
	op_zero64_mem_memory,
	op_reg8_reg8_memory,
	op_reg8_reg16_memory,
	op_reg8_reg32_memory,
	op_reg8_reg64_memory,
	op_reg16_reg16_memory,
	op_reg16_reg32_memory,
	op_reg16_reg64_memory,
	op_reg32_reg32_memory,
	op_reg32_reg64_memory,
	op_reg64_reg64_memory,
	op_reg8_mem_memory,
	op_reg16_mem_memory,
	op_reg32_mem_memory,
	op_reg64_mem_memory,
	op_imm8_reg8_memory,
	op_imm8_reg16_memory,
	op_imm8_reg32_memory,
	op_imm8_reg64_memory,
	op_imm16_reg16_memory,
	op_imm16_reg32_memory,
	op_imm16_reg64_memory,
	op_imm32_reg32_memory,
	op_imm32_reg64_memory,
	op_imm64_reg64_memory,
	op_imm8_mem_memory,
	op_imm16_mem_memory,
	op_imm32_mem_memory,
	op_imm64_mem_memory,
	op_mem_reg8_memory,
	op_mem_reg16_memory,
	op_mem_reg32_memory,
	op_mem_reg64_memory,
	lea_r1r2sc8_reg_memory,
	lea_r1r2sc16_reg_memory,
	lea_r1r2sc32_reg_memory,
	lea_r1r2sc64_reg_memory,
	lea_r1r2s_reg_memory,
	lea_r1r2c8_reg_memory,
	lea_r1r2c16_reg_memory,
	lea_r1r2c32_reg_memory,
	lea_r1r2c64_reg_memory,
	lea_r1r2_reg_memory,
	lea_r1c8_reg_memory,
	lea_r1c16_reg_memory,
	lea_r1c32_reg_memory,
	lea_r1c64_reg_memory,
	lea_r2sc8_reg_memory,
	lea_r2sc16_reg_memory,
	lea_r2sc32_reg_memory,
	lea_r2sc64_reg_memory,
	lea_r2s_reg_memory,
	lea_r1_reg_memory,
	lea_c8_reg_memory,
	lea_c16_reg_memory,
	lea_c32_reg_memory,
	lea_c64_reg_memory,
	set_reg_memory,
	set_mem_memory
};

const write_handler write_handlers[] = {
	halt_write,
	op_zero8_reg8_write,
	op_zero8_reg16_write,
	op_zero8_reg32_write,
	op_zero8_reg64_write,
	op_zero16_reg16_write,
	op_zero16_reg32_write,
	op_zero16_reg64_write,
	op_zero32_reg32_write,
	op_zero32_reg64_write,
	op_zero64_reg64_write,
	op_zero8_mem_write,
	op_zero16_mem_write,
	op_zero32_mem_write,
	op_zero64_mem_write,
	op_reg8_reg8_write,
	op_reg8_reg16_write,
	op_reg8_reg32_write,
	op_reg8_reg64_write,
	op_reg16_reg16_write,
	op_reg16_reg32_write,
	op_reg16_reg64_write,
	op_reg32_reg32_write,
	op_reg32_reg64_write,
	op_reg64_reg64_write,
	op_reg8_mem_write,
	op_reg16_mem_write,
	op_reg32_mem_write,
	op_reg64_mem_write,
	op_imm8_reg8_write,
	op_imm8_reg16_write,
	op_imm8_reg32_write,
	op_imm8_reg64_write,
	op_imm16_reg16_write,
	op_imm16_reg32_write,
	op_imm16_reg64_write,
	op_imm32_reg32_write,
	op_imm32_reg64_write,
	op_imm64_reg64_write,
	op_imm8_mem_write,
	op_imm16_mem_write,
	op_imm32_mem_write,
	op_imm64_mem_write,
	op_mem_reg8_write,
	op_mem_reg16_write,
	op_mem_reg32_write,
	op_mem_reg64_write,
	lea_r1r2sc8_reg_write,
	lea_r1r2sc16_reg_write,
	lea_r1r2sc32_reg_write,
	lea_r1r2sc64_reg_write,
	lea_r1r2s_reg_write,
	lea_r1r2c8_reg_write,
	lea_r1r2c16_reg_write,
	lea_r1r2c32_reg_write,
	lea_r1r2c64_reg_write,
	lea_r1r2_reg_write,
	lea_r1c8_reg_write,
	lea_r1c16_reg_write,
	lea_r1c32_reg_write,
	lea_r1c64_reg_write,
	lea_r2sc8_reg_write,
	lea_r2sc16_reg_write,
	lea_r2sc32_reg_write,
	lea_r2sc64_reg_write,
	lea_r2s_reg_write,
	lea_r1_reg_write,
	lea_c8_reg_write,
	lea_c16_reg_write,
	lea_c32_reg_write,
	lea_c64_reg_write,
	set_reg_write,
	set_mem_write
};

#endif