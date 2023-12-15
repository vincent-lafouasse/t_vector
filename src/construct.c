#include "t_vector.h"
#include <stdlib.h>

t_vector	*vec_new(void)
{
	t_vector	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->data = NULL;
	new->size = 0;
	new->capacity = 0;
	return (new);
}

t_vector	*vec_new_with_size(size_t size__)
{
	t_vector	*new;

	new = vec_new();
	if (!new)
		return (NULL);
	new->size = size__;
	new->capacity = size__;
	return (new);
}

t_vector	*vec_new_init(size_t size__, void* value)
{
	t_vector	*new;

	new = vec_new_with_size(size__);
	if (!new)
		return (NULL);
	for (size_t i = 0; i < size__; i++)
		new->data[i] = value;
	return (new);
}

t_vector	*vec_new_from_array(void** array, size_t size)
{
	t_vector	*new;

	if (!array)
		return (NULL);
	new = vec_new_with_size(size);
	if (!new)
		return (NULL);
	for (size_t i = 0; i < size; i++)
		new->data[i] = array[i];
	return (new);
}
