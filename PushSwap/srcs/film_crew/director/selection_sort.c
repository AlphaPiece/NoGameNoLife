/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 14:58:51 by zwang             #+#    #+#             */
/*   Updated: 2018/09/15 21:56:42 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** distance[0]: distance from min to top
** distance[1]: distance from min to bottom
*/

t_command	*selection_sort(t_box_stacks *box_stacks)
{
	t_command	*cmd_queue;
	int			min;
	size_t		distance[2];
	size_t		i;

	if (is_sorted(box_stacks))
		return (NULL);
	cmd_queue = NULL;
	while (count_box_amount(box_stacks->a) > 3 && !(i = 0))
	{
		min = get_min_num(box_stacks->a);
		distance[0] = get_distance_to_end(box_stacks->a, min, true);
		distance[1] = get_distance_to_end(box_stacks->a, min, false);
		if (distance[0] < distance[1] + 1)
			while (i++ < distance[0])
				act(box_stacks, &cmd_queue, "ra");
		else
			while (i++ < distance[1] + 1)
				act(box_stacks, &cmd_queue, "rra");
		act(box_stacks, &cmd_queue, "pb");
	}
	append_command(&cmd_queue, simple_sort(box_stacks, 3));
	while (get_end_box(box_stacks->b, true))
		act(box_stacks, &cmd_queue, "pa");
	return (cmd_queue);
}
