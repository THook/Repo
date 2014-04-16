#include "libft.h"
#include <stdio.h>

void	ls_error(char *path)
{
	ft_putstr("ls: ");
	ft_putstr(path);
	ft_putstr(": ");
	perror("");
}
