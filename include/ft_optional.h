/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optional.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:46:30 by poss              #+#    #+#             */
/*   Updated: 2024/01/13 19:48:52 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPTIONAL_H
# define FT_OPTIONAL_H

# include "t_type.h"
# include <stdbool.h>

typedef struct s_opt_TYPE
{
	bool	is_none;
	TYPE	value;
}			t_opt_TYPE;

bool		opt_TYPE_is_none(const t_opt_TYPE *opt);
bool		opt_TYPE_is_some(const t_opt_TYPE *opt);
TYPE		opt_TYPE_unwrap_or(const t_opt_TYPE *opt, TYPE value);

#endif
