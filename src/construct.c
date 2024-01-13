/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:31:23 by poss              #+#    #+#             */
/*   Updated: 2024/01/13 19:30:00 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_vector.h"
#include <stdlib.h>
#include <string.h>

t_vector	*vec_new(void)
{
	t_vector	*new;

	new = malloc(sizeof(t_vector));
	if (!new)
		return (NULL);
	new->data = NULL;
	new->size = 0;
	new->capacity = 0;
	return (new);
}

t_vector	*vec_new_with_size(size_t size)
{
	t_vector	*new;

	new = vec_new();
	if (!new)
		return (NULL);
	new->data = malloc(sizeof(TYPE) * size);
	if (!new->data)
		return (free(new), NULL);
	new->size = size;
	new->capacity = size;
	return (new);
}

t_vector	*vec_new_init(size_t size, TYPE value)
{
	t_vector	*new;
	size_t		i;

	new = vec_new_with_size(size);
	if (!new)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new->data[i] = value;
		++i;
	}
	return (new);
}

t_vector	*vec_new_from_array(const TYPE *array, size_t size)
{
	t_vector	*new;

	if (!array)
		return (NULL);
	new = vec_new_with_size(size);
	if (!new)
		return (NULL);
	memcpy(new->data, array, size * sizeof(TYPE));
	return (new);
}
