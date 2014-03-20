
#include <stdlib.h>
#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*tmp;
	t_list		*cur;

	cur = *alst;
	while (cur)
	{
		tmp = cur->next;
		ft_lstdelone(alst, del);
		cur = tmp;
	}
}

