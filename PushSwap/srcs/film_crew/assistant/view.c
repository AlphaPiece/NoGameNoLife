/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 14:08:55 by zwang             #+#    #+#             */
/*   Updated: 2018/11/07 10:21:29 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t		get_max_num_length_in_a(t_box_stacks *box_stacks)
{
	t_box			*a;
	static size_t	max_length;

	a = box_stacks->a;
	max_length = ft_numlen(a->num);
	while (a->next)
	{
		max_length = ft_max(2, max_length, ft_numlen(a->next->num));
		a = a->next;
	}
	return (max_length);
}

void				print_status(t_box_stacks *box_stacks)
{
	t_box			*a;
	t_box			*b;
	static size_t	max_length;

	a = box_stacks->a;
	b = box_stacks->b;
	if (max_length == 0)
		max_length = get_max_num_length_in_a(box_stacks);
	while (a && b)
	{
		(a->is_empty) ? ft_printf("%*c", max_length, ' ') :
						ft_printf("%*d", max_length, a->num);
		(b->is_empty) ? ft_printf("%*c\n", max_length + 3, ' ') :
						ft_printf("%*d\n", max_length + 3, b->num);
		a = a->next;
		b = b->next;
	}
	ft_printf(WHITE);
	ft_putnchar('_', max_length);
	ft_putstr("   ");
	ft_putnchar('_', max_length);
	ft_printf(MAGENTA "\n%*c %*c\n" RESET, max_length, 'a',
				max_length + 2, 'b');
}

static t_command	*print_same_cmd(t_box_stacks *box_stacks, t_command *cmd)
{
	ft_printf(CYAN "%s\n", SEP);
	ft_printf("Perform %s ", cmd->cmd_code);
	basic_match_call(box_stacks, cmd->cmd_code);
	cmd = cmd->next;
	while (cmd->next && MATCH(cmd->cmd_code, cmd->next->cmd_code))
	{
		basic_match_call(box_stacks, cmd->cmd_code);
		ft_printf("%s ", cmd->cmd_code);
		cmd = cmd->next;
	}
	basic_match_call(box_stacks, cmd->cmd_code);
	ft_printf("%s:\n" YELLOW, cmd->cmd_code);
	cmd = cmd->next;
	print_status(box_stacks);
	return (cmd);
}

static t_command	*print_comb_cmd(t_box_stacks *box_stacks, t_command *cmd)
{
	if (is_ss(cmd))
	{
		basic_match_call(box_stacks, "ss");
		ft_printf(CYAN "%s\nPerform %s %s (equiv. to rr):\n" YELLOW, SEP,
					cmd->cmd_code, cmd->next->cmd_code);
	}
	else if (is_rr(cmd))
	{
		basic_match_call(box_stacks, "rr");
		ft_printf(CYAN "%s\nPerform %s %s (equiv. to rr):\n" YELLOW, SEP,
					cmd->cmd_code, cmd->next->cmd_code);
	}
	else if (is_rrr(cmd))
	{
		basic_match_call(box_stacks, "rrr");
		ft_printf(CYAN "%s\nPerform %s %s (equiv. to rrr):\n" YELLOW, SEP,
					cmd->cmd_code, cmd->next->cmd_code);
	}
	print_status(box_stacks);
	cmd = cmd->next->next;
	return (cmd);
}

t_command			*print_init_or_cmd(t_box_stacks *box_stacks,
										t_command *cmd,
										t_options *options,
										t_bool is_init)
{
	if (is_init)
	{
		ft_printf(CYAN "%s\n", SEP);
		ft_printf("Initial Status: Raise The Curtain!\n" YELLOW);
		print_status(box_stacks);
		return (NULL);
	}
	else
	{
		if (options->o_option && cmd->next &&
			MATCH(cmd->cmd_code, cmd->next->cmd_code))
			cmd = print_same_cmd(box_stacks, cmd);
		else if (options->o_option && cmd->next &&
					(is_ss(cmd) || is_rr(cmd) || is_rrr(cmd)))
			cmd = print_comb_cmd(box_stacks, cmd);
		else
		{
			basic_match_call(box_stacks, cmd->cmd_code);
			ft_printf(CYAN "%s\nPerform %s:\n" YELLOW, SEP, cmd->cmd_code);
			print_status(box_stacks);
			cmd = cmd->next;
		}
		return (cmd);
	}
}
