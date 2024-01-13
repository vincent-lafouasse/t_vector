/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_optional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:51:45 by poss              #+#    #+#             */
/*   Updated: 2024/01/13 19:56:04 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_optional.h"

t_opt_TYPE	opt_TYPE_get_some(TYPE value)
{
	t_opt_TYPE	out;

	out.is_none = false;
	out.value = value;
	return (out);
}
t_opt_TYPE	opt_TYPE_get_none(void)
{
	t_opt_TYPE	out;

	out.is_none = true;
	return (out);
}

bool	opt_TYPE_is_none(const t_opt_TYPE *opt)
{
	return (opt->is_none);
}

bool	opt_TYPE_is_some(const t_opt_TYPE *opt)
{
	return (!opt_TYPE_is_none(opt));
}

TYPE	opt_TYPE_unwrap_or(const t_opt_TYPE *opt, TYPE value)
{
	if (opt->is_none)
		return (value);
	else
		return (opt->value);
}
