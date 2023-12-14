#include "t_vector.h"

#include <stdlib.h>

t_vector* vector_new(void)
{
	t_vector* new = malloc(sizeof(*new));
	new->data = NULL;
	new->len = 0;
	new->capacity = 0;
	return new;
}
