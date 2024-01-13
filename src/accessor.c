/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accessor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:08:51 by poss              #+#    #+#             */
/*   Updated: 2024/01/13 19:58:19 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_vector.h"

t_opt_TYPE	vec_at(t_vector *v, size_t position)
{
	if (position >= v->size)
		return (opt_TYPE_get_none());
	return (opt_TYPE_get_some(v->data[position]));
}
