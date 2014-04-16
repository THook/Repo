#include "ft_ls.h"

void	ls_print_short(t_list *entries, t_options *options)
{
	char	*entry;

	while (entries)
	{
		entry = entries->content;
		if (!is_hidden(entry) || options->a)
			ft_putendl(entry);
		entries = entries->next;
	}
}
