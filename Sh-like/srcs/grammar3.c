#include "../includes/grammar.h"
#include "../includes/parser.h"

int			ft_isin(char *lexen)
{
	if (!ft_strcmp(lexen, "<") || !ft_strcmp(lexen, "<<"))
		return (1);
	return (0);
}

int			ft_isout(char *lexen)
{
	if (!ft_strcmp(lexen, ">") || !ft_strcmp(lexen, ">>"))
		return (1);
	return (0);
}
