
/**
 * 	This source file contains all of the implementations for the
 * 	functions specified in m86fproto.h and m86cpu.h
 *
 * 	AUTHORED BY
 * 	- Duncan Huntsinger: dbh875@utexas.edu
 **/

#include <m86fproto.h>
#include <m86cpu.h>

/* M86CPU FUNCTION IMPLEMENTATIONS */

m86_word_t getrval(const struct m86_cpu_state *restrict state, int reg, int chunk) {
	union m86_chunk_conv {
		uint64_t qword;
		uint32_t dword;
		uint16_t  word;
		uint8_t   byte;
	} cv = { state->registers[reg] };

	switch (chunk) {
		case 8:  return cv.byte;
		case 16: return cv.word;
		case 32: return cv.dword;
		case 64: return cv.qword;
	}
}

void setrval(struct m86_cpu_state_t *restrict state, int reg, m86_word_t val, int chunk) {
	m86_word_t rval = getrval(state, reg, 64);
	switch (chunk) {
		case 8:  rval = (uint8_t) val | rval; break;
		case 16: rval = (uint16_t)val | rval; break;
		case 32: rval = (uint32_t)val; break;
		case 64: rval = (uint64_t)val; break;
	}
	state->registers[reg] = rval;
}

cpustat_t getcstat(const struct m86_cpu_state_t *restrict state) {
	return state->cstatus;
}


/* M86FPROTO FUNCTION IMPLEMENTATIONS */

m86_word_t halt_fetch(uint8_t *in, struct m86_fetch_output_t *restrict out) {
	out->instr = M86_INSTR_HALT;
	out->predicted_val_p = in + 1;
}

m86_word_t halt_decode(struct m86_fetch_output_t *restrict in, struct m86_decode_output_t *restrict out){
	out->instr = in->instr;
	out->predicted_val_p = in->predicted_val_p;
}

m86_word_t halt_execute(struct m86_decode_output_t *restrict in, struct m86_execute_output_t *restrict out) {
	out->instr = in->instr;
	out->predicted_val_p = in->predicted_val_p;
}

m86_word_t halt_memory(struct m86_execute_output_t *restrict in, struct m86_memory_output_t *restrict out) {
	out->instr = in->instr;
	out->predicted_val_p = in->predicted_val_p;
}

m86_word_t halt_write(struct m86_memory_output_t *restrict in, struct m86_cpu_state_t *restrict out) {
	out->cstatus = CSTATUS_HALT;		
}
