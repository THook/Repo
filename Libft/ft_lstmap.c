
#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list * (*f)(t_list *elem))
{
	t_list		*new;
	t_list		*tmp;

	if (!(new = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	tmp = new;
	while (tmp)
	{
		f(tmp);
		tmp = tmp->next;
	}
	return (new);
}
