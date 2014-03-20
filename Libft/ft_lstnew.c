

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*new;

	if (!content)
		content_size = 0;
	if (!(new = (t_list *)ft_memalloc(sizeof(content_size))))
		return (NULL);
	return (new);
}

