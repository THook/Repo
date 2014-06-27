#include "../includes/add_var.h"

int			assign_variable(t_sh *sh, t_node *node)
{
	t_cmd		*cmd;
	char		*name;
	char		*value;
	char		**tmp;

	cmd = ((t_cmd*)node->value);
	if (cmd->args[1] != NULL)
		return (ft_cmd_not_found(cmd->args[1]));
	else
	{
		tmp = ft_strsplit(cmd->cmd, '=');
		name = ft_strdup(tmp[0]);
		value = ft_strdup(tmp[1]);
		add_var_to_env(sh, name, value, 0);
	}
	return (0);
}

void		add_var_to_env(t_sh *sh, char *name, void *value, int array)
{
	t_var		*var;

	var = ft_memalloc(sizeof(t_var *) * 2);
	var->name = ft_strdup(name);
	var->value = value;
	var->array = array;
	ft_list_add(sh->var, ft_list_new(var, (sizeof(t_var *) * 2)));
}
