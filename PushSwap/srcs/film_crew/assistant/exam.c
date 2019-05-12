/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 14:15:36 by zwang             #+#    #+#             */
/*   Updated: 2018/09/15 22:18:10 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_sorted(t_box_stacks *box_stacks)
{
	t_box	*a;
	t_box	*b;

	a = box_stacks->a;
	b = box_stacks->b;
	while (a && b)
	{
		if (a->next && a->num > a->next->num)
			return (false);
		if (!b->is_empty)
			return (false);
		a = a->next;
		b = b->next;
	}
	return (true);
}

t_bool	duplicates_exist(int *int_list, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (int_list[i] == int_list[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

t_bool	is_ss(t_command *cmd)
{
	return ((MATCH(cmd->cmd_code, "sa") && MATCH(cmd->next->cmd_code, "sb")) ||
			(MATCH(cmd->cmd_code, "sb") && MATCH(cmd->next->cmd_code, "sa")));
}

t_bool	is_rr(t_command *cmd)
{
	return ((MATCH(cmd->cmd_code, "ra") && MATCH(cmd->next->cmd_code, "rb")) ||
			(MATCH(cmd->cmd_code, "rb") && MATCH(cmd->next->cmd_code, "ra")));
}

t_bool	is_rrr(t_command *cmd)
{
	return ((MATCH(cmd->cmd_code, "rra") &&
			MATCH(cmd->next->cmd_code, "rrb")) ||
			(MATCH(cmd->cmd_code, "rrb") &&
			MATCH(cmd->next->cmd_code, "rra")));
}
