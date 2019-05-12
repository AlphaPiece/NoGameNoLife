/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 16:36:28 by zwang             #+#    #+#             */
/*   Updated: 2018/09/14 13:18:46 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	merge(t_box_stacks *box_stacks, t_command **cmd_queue,
					size_t i, size_t j)
{
	t_box	*box_1;
	t_box	*box_2;

	i = find_bottom_sorted_part(box_stacks->a, 'a');
	j = find_top_sorted_part(box_stacks->b, 'b');
	while (i > 0 && j > 0)
	{
		box_1 = get_end_box(box_stacks->a, false);
		if (!(box_2 = get_end_box(box_stacks->b, true)))
			return ;
		if (box_1->num > box_2->num)
		{
			act(box_stacks, cmd_queue, "rra");
			i--;
		}
		else
		{
			act(box_stacks, cmd_queue, "pa");
			j--;
		}
	}
	while (i-- > 0)
		act(box_stacks, cmd_queue, "rra");
	while (j-- > 0)
		act(box_stacks, cmd_queue, "pa");
}

t_command	*merge_sort(t_box_stacks *box_stacks)
{
	t_command	*cmd_queue;
	size_t		sorted_num;
	size_t		len;
	size_t		i;
	size_t		j;

	if (is_sorted(box_stacks))
		return (NULL);
	cmd_queue = NULL;
	while (!is_sorted(box_stacks))
	{
		sorted_num = count_sorted_part(box_stacks, 'a');
		i = 0;
		while (i++ < sorted_num / 2)
		{
			len = find_top_sorted_part(box_stacks->a, 'a');
			j = 0;
			while (j++ < len)
				act(box_stacks, &cmd_queue, "pb");
		}
		while (get_end_box(box_stacks->b, true))
			merge(box_stacks, &cmd_queue, i, j);
	}
	return (cmd_queue);
}
