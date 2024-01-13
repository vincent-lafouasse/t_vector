/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_optional.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:46:30 by poss              #+#    #+#             */
/*   Updated: 2024/01/13 20:44:13 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_OPTIONAL_H
# define T_OPTIONAL_H

# include "t_type.h"
# include <stdbool.h>

typedef struct s_opt_TYPE
{
	bool	is_some;
	TYPE	value;
}			t_opt_TYPE;

t_opt_TYPE	opt_TYPE_make_some(TYPE value);
t_opt_TYPE	opt_TYPE_make_none(void);
TYPE		opt_TYPE_unwrap_or(const t_opt_TYPE *opt, TYPE value);

#endif
