#ifndef M86CPU_H
#define M86CPU_H

#include <m86def.h>

typedef int cpustat_t;

struct m86_cpu_state_t {
    m86_word_t registers[M86_REGCOUNT];
    cpustat_t cstatus;
    uint8_t *instruction_ptr;
};

#define CSTATUS_HALT    (0x00)
#define CSTATUS_READY   (0x01)
#define CSTATUS_RUN     (0x02)

#define CSTATUS_IFERROR(cstatus) !(cstatus & 0x40)
#define CSTATUS_IFHALT(cstatus) !(cstatus & 0xFF)
#define CSTATUS_IFEXIT(cstatus) !!(cstatus & 0x40)

/**
 * 	Retrieves an integer from the specified register in 
 * 	the provided CPU state, consisting of <chunk> bits.
 **/
m86_word_t getrval(const struct m86_cpu_state_t *restrict state, int reg, int chunk);

/**
 * 	Set the value of the specified register in the provided
 * 	CPU state to the <chunk> bits-sized integer.
 **/
void setrval(struct m86_cpu_state_t *restrict state, int reg, m86_word_t val, int chunk);

/**
 * 	Retrieves the CPU status from the provided CPU state.
 **/
cpustat_t getcstat(const struct m86_cpu_state_t *restrict state);

/**
 *  Initializes a CPU state object.
 **/
cpustat_t cpuinit(struct m86_cpu_state_t *restrict state);

/**
 *  Transfer state from one CPU state object to another.
 **/
cpustat_t cputrst(const struct m86_cpu_state_t *restrict state, struct m86_cpu_state_t *restrict copy);

/**
 *  Refer an instruction vector to a CPU state object, and
 *  invoke it sequentially or using a pipeline.
 **/
cpustat_t cpuip(struct m86_cpu_state_t *restrict state, uint8_t *ip, int how);

#endif