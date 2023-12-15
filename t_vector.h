/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vector.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:31:31 by poss              #+#    #+#             */
/*   Updated: 2023/12/15 21:12:44 by poss             ###   ########.fr       */
/*   Updated: 2023/12/15 20:48:19 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_VECTOR_H
# define T_VECTOR_H

# include <stdbool.h>
# include <stddef.h>

typedef struct s_vector
{
	void	**data;
	size_t	size;
	size_t	capacity;
	size_t	element_size;
}			t_vector;

// Allocation/Destruction
t_vector	*vec_new(size_t element_size);
t_vector	*vec_new_with_size(size_t element_size, size_t size);
t_vector	*vec_new_init(size_t element_size, size_t size, const void *value);
t_vector	*vec_new_from_array(size_t element_size, const void *array,
				size_t size);
void		vec_delete(t_vector *v, void (*del)(void *));

// Capacity management
void		vec_reserve(size_t capacity);
void		vec_resize(size_t capacity);
void		vec_shrink_to_fit(void);

// Mutators
void		vec_push_back(t_vector *v, int value);
void		vec_insert(t_vector *v, int value, size_t position);
void		vec_pop_back(t_vector *v);
void		vec_erase(t_vector *v, size_t position);
void		vec_clear(t_vector *v);

// Accessors
void		*vec_at(t_vector *v, size_t position);
void		*vec_front(t_vector *v);
void		*vec_back(t_vector *v);

// Properties
bool		vec_is_empty(t_vector *v);
bool		vec_is_sorted(t_vector *v);

// Algorithms
void		vec_sort(t_vector *v);
void		vec_rotate(t_vector *v);

void		vec_sort_with(t_vector *v, bool (*pred)(int a, int b));

#endif
