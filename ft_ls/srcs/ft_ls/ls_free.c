#include <stdlib.h>

void	free_lst(void *d, size_t s)
{
	if (d)
		free(d);
	(void) s;
}
