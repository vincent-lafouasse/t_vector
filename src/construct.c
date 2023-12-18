/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:31:23 by poss              #+#    #+#             */
/*   Updated: 2023/12/18 23:29:50 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_vector.h"
#include <stdlib.h>
#include <string.h>

t_vector	*vec_new(size_t element_size)
{
	t_vector	*new;

	new = malloc(sizeof(t_vector));
	if (!new)
		return (NULL);
	new->data = NULL;
	new->size = 0;
	new->capacity = 0;
	new->element_size = element_size;
	return (new);
}

t_vector	*vec_new_with_size(size_t element_size, size_t size)
{
	t_vector	*new;

	new = vec_new(element_size);
	if (!new)
		return (NULL);
	new->data = malloc(element_size * size);
	if (!new->data)
		return (free(new), NULL);
	new->size = size;
	new->capacity = size;
	return (new);
}

t_vector	*vec_new_init(size_t element_size, size_t size, const void *value)
{
	t_vector	*new;
	size_t		i;

	new = vec_new_with_size(element_size, size);
	if (!new)
		return (NULL);
	i = 0;
	while (i < size)
	{
		memcpy((unsigned char *)new->data + (i * element_size), value,
			element_size);
		++i;
	}
	return (new);
}

t_vector	*vec_new_from_array(size_t element_size, const void *array,
		size_t size)
{
	t_vector	*new;

	if (!array)
		return (NULL);
	new = vec_new_with_size(element_size, size);
	if (!new)
		return (NULL);
	memcpy(new->data, array, size * element_size);
	return (new);
}
