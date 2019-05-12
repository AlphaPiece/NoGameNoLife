/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 09:28:48 by zwang             #+#    #+#             */
/*   Updated: 2018/09/15 21:59:49 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_box	*start_swap(t_box *box, int last, int **tmp)
{
	if (box && box->next)
	{
		(*tmp)[1] = box->next->num;
		box->next->num = box->num;
		box->num = last;
		(*tmp)[0] = (*tmp)[1];
	}
	return (box->next);
}

static void		middle_swap(t_box *box, int **tmp)
{
	while (box && box->next)
	{
		(*tmp)[1] = box->next->num;
		box->next->num = (*tmp)[0];
		(*tmp)[0] = (*tmp)[1];
		box = box->next;
	}
}

void			reverse_rotate(t_box_stacks *box_stacks, char stack_code)
{
	t_box	*box;
	int		last;
	int		*tmp;

	if (!(tmp = (int *)malloc(sizeof(int) * 2)))
		return ;
	box = (stack_code == 'a') ? box_stacks->a : box_stacks->b;
	while (box->next)
		box = box->next;
	last = (!box->is_empty) ? box->num : 0;
	box = (stack_code == 'a') ? box_stacks->a : box_stacks->b;
	while (box && box->is_empty)
		box = box->next;
	if (box)
	{
		box = start_swap(box, last, &tmp);
		middle_swap(box, &tmp);
	}
	free(tmp);
}

void			reverse_rotate_both(t_box_stacks *box_stacks)
{
	reverse_rotate(box_stacks, 'a');
	reverse_rotate(box_stacks, 'b');
}
