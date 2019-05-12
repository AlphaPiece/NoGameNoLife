/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   information.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 09:24:32 by zwang             #+#    #+#             */
/*   Updated: 2018/09/14 15:25:50 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_box	*get_end_box(t_box *box_stack, t_bool is_upper_end)
{
	t_box	*box;

	box = box_stack;
	if (is_upper_end)
	{
		while (box && box->is_empty)
			box = box->next;
		return (box);
	}
	else
	{
		while (box->next)
			box = box->next;
		return (box);
	}
}

size_t	count_box_amount(t_box *box_stack)
{
	t_box	*box;
	size_t	count;

	box = get_end_box(box_stack, true);
	count = 0;
	while (box)
	{
		count++;
		box = box->next;
	}
	return (count);
}

size_t	count_sorted_part(t_box_stacks *box_stacks, char stack_code)
{
	size_t	count;
	size_t	len;
	size_t	i;
	t_box	*box;

	count = 0;
	box = (stack_code == 'a') ? box_stacks->a : box_stacks->b;
	while ((len = find_top_sorted_part(box, 'a')) > 0)
	{
		count++;
		i = 0;
		while (i++ < len)
			box = box->next;
	}
	return (count);
}

/*
** For functions find_top_sorted_part and find_bottom_sorted_part,
** order 'a' is ascending order and order 'b' is descending order.
*/

size_t	find_top_sorted_part(t_box *box_stack, char order)
{
	size_t	n;
	t_box	*box;

	box = box_stack;
	while (box && box->is_empty)
		box = box->next;
	if (!box)
		return (0);
	n = 1;
	while (box->next)
	{
		if (order == 'a')
		{
			if (box->num > box->next->num)
				break ;
		}
		else
		{
			if (box->num < box->next->num)
				break ;
		}
		n++;
		box = box->next;
	}
	return (n);
}

size_t	find_bottom_sorted_part(t_box *box_stack, char order)
{
	size_t	n;
	t_box	*box;

	box = box_stack;
	while (box->next)
		box = box->next;
	n = 1;
	while (box->prev && !box->prev->is_empty)
	{
		if (order == 'a')
		{
			if (box->num < box->prev->num)
				break ;
		}
		else
		{
			if (box->num > box->prev->num)
				break ;
		}
		n++;
		box = box->prev;
	}
	return (n);
}
