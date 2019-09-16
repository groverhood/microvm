
#include <m86def.h>

struct m86_cpu_state_t {
    m86_word_t registers[M86_REGCOUNT];
};

m86_word_t getrval(const struct m86_cpu_state_t *state, int reg);


