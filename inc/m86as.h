#ifndef M86AS_H
#define M86AS_H

#include <stddef.h>

struct mas_error_t {
	size_t ln, col;
	const char *unexpected;

	int what;
};

#define MAS_ERROR_INCOMPOPR 0
#define MAS_ERROR_DINDIRECT 1
#define MAS_ERROR_UNRECOGNZ	2

#endif
