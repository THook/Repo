
#include "libft.h"
#include <stdlib.h>

void		*ft_realloc(void *ptr, size_t size)
{
	void		*new;
	void		*tmp;
	int			i;

	i = -1;
	if (!ptr)
	{
		if (!(new = ft_memalloc(sizeof(size))))
			return (NULL);
		return (new);
	}
	tmp = ptr;
	if (!(ptr = ft_memalloc(sizeof(size))))
		return (NULL);
	while (tmp)
	{
		*ptr = *tmp;
		tmp++;
		ptr++;
	}
	return (ptr);
}

