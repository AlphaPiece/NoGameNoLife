/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 15:21:22 by zwang             #+#    #+#             */
/*   Updated: 2018/09/15 21:58:15 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	is_valid_command(char *cmd_code)
{
	if (ft_strcmp(cmd_code, "sa") == 0 || ft_strcmp(cmd_code, "sb") == 0 ||
		ft_strcmp(cmd_code, "ss") == 0 || ft_strcmp(cmd_code, "pa") == 0 ||
		ft_strcmp(cmd_code, "pb") == 0 || ft_strcmp(cmd_code, "ra") == 0 ||
		ft_strcmp(cmd_code, "rb") == 0 || ft_strcmp(cmd_code, "rr") == 0 ||
		ft_strcmp(cmd_code, "rra") == 0 || ft_strcmp(cmd_code, "rrb") == 0 ||
		ft_strcmp(cmd_code, "rrr") == 0)
		return (true);
	return (false);
}

t_command		*create_command(char *cmd_code)
{
	t_command	*cmd;

	if (!(cmd = (t_command *)malloc(sizeof(t_command))))
		return (NULL);
	cmd->cmd_code = cmd_code;
	cmd->prev = NULL;
	cmd->next = NULL;
	return (cmd);
}

void			append_command(t_command **cmd_queue, t_command *new_cmd)
{
	t_command	*cmd;

	if (!*cmd_queue)
		*cmd_queue = new_cmd;
	else if (new_cmd)
	{
		cmd = *cmd_queue;
		while (cmd->next)
			cmd = cmd->next;
		cmd->next = new_cmd;
		new_cmd->prev = cmd;
	}
}

int				create_command_queue(t_command **cmd_queue)
{
	char		*cmd_code;
	int			flag;

	*cmd_queue = NULL;
	while ((flag = ft_nextline(0, &cmd_code)) > 0)
	{
		if (is_valid_command(cmd_code))
			append_command(cmd_queue, create_command(cmd_code));
		else
			return (2);
	}
	if (flag < 0)
		return (2);
	return (0);
}
