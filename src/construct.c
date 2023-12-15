#include "t_vector.h"

#include <stdlib.h>

t_vector* vector_new(void)
{
	t_vector* new = malloc(sizeof(*new));
	if (!new)
		return NULL;
	new->data = NULL;
	new->len = 0;
	new->capacity = 0;
	return new;
}

t_vector* 	vector_new_with_capacity(size_t capacity__)
{
	t_vector* new = vector_new();
	if (!new)
		return NULL;
	new->capacity = capacity__;
	new->data = malloc(capacity__ * sizeof(int));
	if (!new->data)
		return free(new), NULL;
	return new;
}
