/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 10:54:50 by zwang             #+#    #+#             */
/*   Updated: 2018/09/15 21:29:53 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_min_num(t_box *box_stack)
{
	int		min;
	t_box	*box;

	box = get_end_box(box_stack, true);
	min = box->num;
	while (box)
	{
		if (box->num < min)
			min = box->num;
		box = box->next;
	}
	return (min);
}

size_t	get_distance_to_end(t_box *box_stack, int num, t_bool is_upper_end)
{
	t_box	*box;
	size_t	distance;

	distance = 0;
	if (is_upper_end)
	{
		box = get_end_box(box_stack, true);
		while (box && box->num != num)
		{
			distance++;
			box = box->next;
		}
		return (distance);
	}
	else
	{
		box = get_end_box(box_stack, false);
		while (box && box->num != num)
		{
			distance++;
			box = box->prev;
		}
		return (distance);
	}
}
