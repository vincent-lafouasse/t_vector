#include "t_vector.h"
#include <stdlib.h>

void	vec_delete__(t_vector *v)
{
	if (!v)
		return ;
	free(v->data);
	free(v);
}
