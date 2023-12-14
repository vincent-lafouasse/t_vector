#ifndef T_VECTOR_H_
#define T_VECTOR_H_

#include <stddef.h>

typedef struct s_vector
{
	int* data;
	size_t len;
	size_t capacity;
} t_vector;

t_vector* vector_new(void);

#endif
