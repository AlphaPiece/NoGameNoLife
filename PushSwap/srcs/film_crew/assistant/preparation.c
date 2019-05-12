/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 10:12:34 by zwang             #+#    #+#             */
/*   Updated: 2018/11/07 10:34:49 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	is_valid_num_list(char **num_list, size_t len)
{
	size_t	i;

	i = -1;
	while (++i < len)
		if (!ft_isnumeric(num_list[i]))
			return (false);
	return (true);
}

static int		form_int_list(char **num_list, size_t len, int **int_list)
{
	size_t	i;
	long	num;

	i = 0;
	if (!(*int_list = (int *)malloc(sizeof(int) * len)))
		return (1);
	while (i < len)
	{
		num = ft_atol(num_list[i]);
		if (num < -2147483648 || num > 2147483647)
		{
			free(*int_list);
			return (2);
		}
		(*int_list)[i++] = (int)num;
	}
	return (0);
}

int				check_input(t_room *room, size_t len, char **num_list)
{
	int		*int_list;
	int		flag;

	if (!is_valid_num_list(num_list, len))
		return (2);
	if ((flag = form_int_list(num_list, len, &int_list)) == 1)
		return (1);
	else if (flag == 2)
		return (2);
	if (duplicates_exist(int_list, len))
	{
		free(int_list);
		return (2);
	}
	if (!(room->box_stacks = create_box_stacks(int_list, len)))
	{
		free(int_list);
		return (1);
	}
	free(int_list);
	if (room->program_index == 1)
		if (create_command_queue(&(room->cmd_queue)) == 2)
			return (2);
	return (0);
}

t_options		*check_options(int argc, char **argv)
{
	t_options	*options;

	if (!(options = (t_options *)malloc(sizeof(t_options))))
		return (NULL);
	options->v_option = false;
	options->n_option = false;
	options->d_option = false;
	options->o_option = false;
	options->arg_index = 1;
	if (argv[1][0] == '-' && !ft_isnumeric(argv[1]))
		collect_options(argc, argv, options);
	return (options);
}

int				prepare_behind_curtain(t_room *room)
{
	int		flag;
	char	**num_list;
	size_t	len;

	flag = 0;
	if (!(room->options = check_options(room->argc, room->argv)))
		flag = 1;
	else if (room->options->flag == 2)
		flag = 2;
	else
	{
		len = room->argc - room->options->arg_index;
		num_list = room->argv + room->options->arg_index;
		if (len == 1)
		{
			num_list = ft_strsplit(num_list[0], " ");
			len = ft_strarrlen((const char **)num_list);
		}
		flag = check_input(room, len, num_list);
		if (len != (size_t)(room->argc - room->options->arg_index))
			ft_strarrdel(num_list);
	}
	if (flag == 2)
		ft_printf(RED "%s\nError\n" RESET, SEP);
	return (flag);
}
