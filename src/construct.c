#include "t_vector.h"

#include <stdlib.h>

t_vector* vector_new(void)
{
	t_vector* new = malloc(sizeof(*new));
	if (!new)
		return NULL;
	new->data = NULL;
	new->size = 0;
	new->capacity = 0;
	return new;
}

t_vector* 	vector_new_with_size(size_t size__)
{
	t_vector* new = vector_new();
	if (!new)
		return NULL;
	new->capacity = size__;
	new->size = size__;
	new->data = malloc(size__ * sizeof(int));
	if (!new->data)
		return free(new), NULL;
	return new;
}

t_vector* 	vector_new_init(size_t size__, int value)
{
	t_vector* new = vector_new_with_size(size__);
	if (!new)
		return NULL;

	for (size_t i = 0; i < size__; i++)
		new->data[i] = value;

	return new;
}
