/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 11:26:10 by zwang             #+#    #+#             */
/*   Updated: 2018/09/20 10:00:49 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		basic_match_call(t_box_stacks *box_stacks, char *cmd_code)
{
	if (MATCH(cmd_code, "sa") || MATCH(cmd_code, "sb"))
		swap(box_stacks, cmd_code[1]);
	else if (MATCH(cmd_code, "pa") || MATCH(cmd_code, "pb"))
		push(box_stacks, cmd_code[1]);
	else if (MATCH(cmd_code, "ra") || MATCH(cmd_code, "rb"))
		rotate(box_stacks, cmd_code[1]);
	else if (MATCH(cmd_code, "rra") || MATCH(cmd_code, "rrb"))
		reverse_rotate(box_stacks, cmd_code[2]);
	else if (MATCH(cmd_code, "ss"))
		swap_both(box_stacks);
	else if (MATCH(cmd_code, "rr"))
		rotate_both(box_stacks);
	else if (MATCH(cmd_code, "rrr"))
		reverse_rotate_both(box_stacks);
}

void		execute_actions(t_box_stacks *box_stacks, t_command *cmd_queue,
							t_options *options)
{
	t_command	*cmd;

	if (options->v_option || options->d_option)
		perform_with_pictures(box_stacks, cmd_queue, options);
	else
	{
		cmd = cmd_queue;
		while (cmd)
		{
			basic_match_call(box_stacks, cmd->cmd_code);
			cmd = cmd->next;
		}
	}
	if (options->n_option)
	{
		ft_printf(WHITE "%s\n", SEP);
		ft_printf("\tNumber of Step(s): %zd\n", count_cmd_num(cmd_queue));
	}
}
