/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 21:26:37 by zwang             #+#    #+#             */
/*   Updated: 2019/02/18 11:50:26 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static struct timespec	delay = {0, 100000000};

void	collect_options(int argc, char **argv, t_options *options)
{
	int		i;
	int		j;

	i = 1;
	options->flag = 2;
	while (i < argc && argv[i][0] == '-')
	{
		j = 0;
		while (argv[i][++j])
			if (argv[i][j] != 'n' && argv[i][j] != 'v' &&
				argv[i][j] != 'd' && argv[i][j] != 'o')
				return ;
		if (ft_strchr(argv[i], 'v'))
			options->v_option = true;
		if (ft_strchr(argv[i], 'n'))
			options->n_option = true;
		if (ft_strchr(argv[i], 'd'))
			options->d_option = true;
		if (ft_strchr(argv[i], 'o'))
			options->o_option = true;
		i++;
	}
	options->arg_index = i;
	options->flag = 0;
}

void	perform_with_pictures(t_box_stacks *box_stacks, t_command *cmd_queue,
								t_options *options)
{
	t_command	*cmd;

	if (options->d_option)
		system("clear");
	print_init_or_cmd(box_stacks, NULL, NULL, true);
	cmd = cmd_queue;
	while (cmd)
	{
		if (options->d_option)
		{
			if (box_stacks->len <= 10)
				sleep(3);
			else if (box_stacks->len <= 30)
				sleep(1);
			else
				nanosleep(&delay, 0);
			system("clear");
		}
		cmd = print_init_or_cmd(box_stacks, cmd, options, false);
	}
}

size_t	count_cmd_num(t_command *cmd_queue)
{
	size_t		i;
	t_command	*cmd;

	i = 0;
	cmd = cmd_queue;
	while (cmd)
	{
		i++;
		cmd = cmd->next;
	}
	return (i);
}
