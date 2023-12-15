/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:31:23 by poss              #+#    #+#             */
/*   Updated: 2023/12/15 18:44:43 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_vector.h"
#include <stdlib.h>

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
	new->data = malloc(size * sizeof(void *));
	if (!new->data)
		return (free(new), NULL);
	new->size = size;
	new->capacity = size;
	return (new);
}

t_vector	*vec_new_init(size_t size, void *value)
{
	t_vector	*new;
	size_t		i;

	new = vec_new_with_size(size);
	if (!new)
		return (NULL);
	i = 0;
	while (i < size)
		new->data[i++] = value;
	return (new);
}

t_vector	*vec_new_from_array(void **array, size_t size)
{
	t_vector	*new;
	size_t		i;

	if (!array)
		return (NULL);
	new = vec_new_with_size(size);
	if (!new)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new->data[i] = array[i];
		++i;
	}
	return (new);
}
