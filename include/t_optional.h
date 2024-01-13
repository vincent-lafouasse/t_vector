/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optional.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:46:30 by poss              #+#    #+#             */
/*   Updated: 2024/01/13 19:55:12 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_OPTIONAL_H
# define T_OPTIONAL_H

# include "t_type.h"
# include <stdbool.h>

typedef struct s_opt_TYPE
{
	bool	is_none;
	TYPE	value;
}			t_opt_TYPE;

t_opt_TYPE	opt_TYPE_get_some(TYPE value);
t_opt_TYPE	opt_TYPE_get_none(void);
bool		opt_TYPE_is_none(const t_opt_TYPE *opt);
bool		opt_TYPE_is_some(const t_opt_TYPE *opt);
TYPE		opt_TYPE_unwrap_or(const t_opt_TYPE *opt, TYPE value);

#endif
