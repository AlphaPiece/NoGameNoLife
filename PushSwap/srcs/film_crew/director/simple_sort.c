/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 14:48:58 by zwang             #+#    #+#             */
/*   Updated: 2018/09/15 21:46:03 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3_boxes(t_box_stacks *box_stacks, t_command **cmd_queue,
							t_box *first, t_box *second)
{
	t_box	*third;

	third = second->next;
	if (second->num > third->num && third->num > first->num)
	{
		act(box_stacks, cmd_queue, "rra");
		act(box_stacks, cmd_queue, "sa");
	}
	else if (third->num > first->num && first->num > second->num)
		act(box_stacks, cmd_queue, "sa");
	else if (second->num > first->num && first->num > third->num)
		act(box_stacks, cmd_queue, "rra");
	else if (first->num > third->num && third->num > second->num)
		act(box_stacks, cmd_queue, "ra");
	else if (first->num > second->num && second->num > third->num)
	{
		act(box_stacks, cmd_queue, "ra");
		act(box_stacks, cmd_queue, "sa");
	}
}

t_command	*simple_sort(t_box_stacks *box_stacks, size_t box_amount)
{
	t_command	*cmd_queue;
	t_box		*first;
	t_box		*second;

	cmd_queue = NULL;
	first = get_end_box(box_stacks->a, true);
	second = first->next;
	if (box_amount == 2 && first->num > second->num)
		act(box_stacks, &cmd_queue, "sa");
	else if (box_amount == 3)
		sort_3_boxes(box_stacks, &cmd_queue, first, second);
	return (cmd_queue);
}
