#include "t_vector.h"
#include <stdlib.h>

void	vector_delete(t_vector *v)
{
	if (!v)
		return ;
	free(v->data);
	free(v);
}
