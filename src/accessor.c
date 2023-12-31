/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accessor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:08:51 by poss              #+#    #+#             */
/*   Updated: 2023/12/15 21:41:30 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_vector.h"

void	*vec_at(t_vector *v, size_t position)
{
	if (!v)
		return (NULL);
	return ((unsigned char *)(v->data) + position * v->element_size);
}
