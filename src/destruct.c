/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:31:27 by poss              #+#    #+#             */
/*   Updated: 2023/12/15 21:42:17 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_vector.h"
#include <stdlib.h>

void	vec_delete__(t_vector *v, void (*del)(void *))
{
	size_t	i;

	if (!v)
		return ;
	i = 0;
	if (del)
	{
		while (i < v->size - 1)
		{
		}
	}
	free(v->data);
	free(v);
}
