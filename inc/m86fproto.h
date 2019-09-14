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
m86_word_t m86_instr_halt_fetch(const uint8_t* *in, struct m86_fetch_output_t *out);

struct m86_decode_output_t {
    
};
m86_word_t m86_instr_halt_decode(const struct m86_fetch_output_t *in, struct m86_decode_output_t *out);

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
m86_word_t m86_instr_op_fetch(const uint8_t* *in, struct m86_fetch_output_t *out);

struct m86_decode_output_t {
    
};
m86_word_t m86_instr_op_decode(const struct m86_fetch_output_t *in, struct m86_decode_output_t *out);

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
m86_word_t m86_instr_lea_fetch(const uint8_t* *in, struct m86_fetch_output_t *out);

struct m86_decode_output_t {
    
};
m86_word_t m86_instr_lea_decode(const struct m86_fetch_output_t *in, struct m86_decode_output_t *out);

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
m86_word_t m86_instr_set_fetch(const uint8_t* *in, struct m86_fetch_output_t *out);

struct m86_decode_output_t {
    
};
m86_word_t m86_instr_set_decode(const struct m86_fetch_output_t *in, struct m86_decode_output_t *out);

#endif