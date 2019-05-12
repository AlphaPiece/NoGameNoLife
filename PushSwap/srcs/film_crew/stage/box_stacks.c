/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_stacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 10:40:25 by zwang             #+#    #+#             */
/*   Updated: 2018/09/15 21:58:43 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_box	*create_box(t_bool is_empty, int num)
{
	t_box	*box;

	if (!(box = (t_box *)malloc(sizeof(t_box))))
		return (NULL);
	box->num = num;
	box->is_empty = is_empty;
	box->prev = NULL;
	box->next = NULL;
	return (box);
}

static void		append_box(t_box **head, t_box *new_box)
{
	t_box	*box;

	if (!*head)
		*head = new_box;
	else
	{
		box = *head;
		while (box->next)
			box = box->next;
		box->next = new_box;
		new_box->prev = box;
	}
}

t_box_stacks	*create_box_stacks(int *int_list, size_t len)
{
	size_t			i;
	t_box			*box;
	t_box_stacks	*box_stacks;

	if (!(box_stacks = (t_box_stacks *)malloc(sizeof(t_box_stacks))))
		return (NULL);
	box_stacks->a = NULL;
	box_stacks->b = NULL;
	box_stacks->len = len;
	i = 0;
	while (i < len)
	{
		box = create_box(false, int_list[i++]);
		append_box(&(box_stacks->a), box);
		box = create_box(true, 0);
		append_box(&(box_stacks->b), box);
	}
	return (box_stacks);
}
