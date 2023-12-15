#include "t_vector.h"
#include <stdlib.h>

void	vec_delete(t_vector *v, void (*del)(void *))
{
	size_t	i;

	if (!v)
		return ;
	i = 0;
	if (del)
	{
		while (i < v->size - 1)
		{
			(*del)(v->data[i++]);
		}
	}
	free(v->data);
	free(v);
}
