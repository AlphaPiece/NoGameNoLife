/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:53:32 by zwang             #+#    #+#             */
/*   Updated: 2019/04/08 21:06:30 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** The program index of push_swap is 2.
*/

static int	receive_result(t_room *room)
{
	t_command	*cmd;

	cmd = room->cmd_queue;
	while (cmd)
	{
		ft_putendl(cmd->cmd_code);
		cmd = cmd->next;
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_room		*room;
	int			flag;
	char		*tmp;

	if (argc == 2 && (!argv[1][0] || !((tmp = ft_strtrim(argv[1]))[0])))
		return (0);
	if (argc >= 2)
	{
		if (!(room = (t_room *)malloc(sizeof(t_room))))
			return (1);
		room->argc = argc;
		room->argv = argv;
		room->program_index = 2;
		flag = prepare_behind_curtain(room);
		if (flag)
			return (flag);
		room->cmd_queue = design_actions(room->box_stacks);
		return (receive_result(room));
	}
	return (0);
}
