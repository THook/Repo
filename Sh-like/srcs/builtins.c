#include <builtins.h>

int		ft_exit(t_cmd *cmd)
{
	cmd = (void*)cmd;
	exit(0);
	return (0);
}
