/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_optional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:51:45 by poss              #+#    #+#             */
/*   Updated: 2024/01/13 20:44:33 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_optional.h"

t_opt_TYPE	opt_TYPE_make_some(TYPE value)
{
	t_opt_TYPE	out;

	out.is_some = true;
	out.value = value;
	return (out);
}
t_opt_TYPE	opt_TYPE_make_none(void)
{
	t_opt_TYPE	out;

	out.is_some = false;
	return (out);
}

TYPE	opt_TYPE_unwrap_or(const t_opt_TYPE *opt, TYPE value)
{
	if (opt->is_some)
		return (opt->value);
	else
		return (value);
}
