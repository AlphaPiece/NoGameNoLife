/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 15:37:16 by zwang             #+#    #+#             */
/*   Updated: 2019/04/08 21:06:38 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** RETURN 0: The program finishes beautifully.
**
** RETURN 1: There are not enough memory in disks (malloc failed), or
** the user input invalid option.
**
** RETURN 2: Some arguments are not integers, or some arguments are
** bigger than an integer, or there are duplicates, or an instruction
** don’t exist and/or is incorrectly formatted.
*/

static int	check_result(t_room *room)
{
	if (is_sorted(room->box_stacks))
		ft_printf(GREEN "%s\nOK\n" RESET, SEP);
	else
		ft_printf(RED "%s\nKO\n" RESET, SEP);
	return (0);
}

int			main(int argc, char **argv)
{
	t_room	*room;
	int		flag;
	char	*tmp;

	if (argc == 2 && (!argv[1][0] || !((tmp = ft_strtrim(argv[1]))[0])))
		return (0);
	if (argc >= 2)
	{
		if (!(room = (t_room *)malloc(sizeof(t_room))))
			return (1);
		room->argc = argc;
		room->argv = argv;
		room->program_index = 1;
		flag = prepare_behind_curtain(room);
		if (flag)
			return (flag);
		execute_actions(room->box_stacks, room->cmd_queue, room->options);
		return (check_result(room));
	}
	return (0);
}
