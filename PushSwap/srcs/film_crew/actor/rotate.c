/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 09:20:05 by zwang             #+#    #+#             */
/*   Updated: 2018/09/14 10:55:13 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_box_stacks *box_stacks, char stack_code)
{
	t_box	*box;
	int		first;

	box = (stack_code == 'a') ? box_stacks->a : box_stacks->b;
	while (box && box->is_empty)
		box = box->next;
	if (box)
	{
		first = box->num;
		while (box->next)
		{
			box->num = box->next->num;
			box = box->next;
		}
		box->num = first;
	}
}

void	rotate_both(t_box_stacks *box_stacks)
{
	rotate(box_stacks, 'a');
	rotate(box_stacks, 'b');
}
