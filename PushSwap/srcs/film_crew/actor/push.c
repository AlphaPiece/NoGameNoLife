/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 16:12:43 by zwang             #+#    #+#             */
/*   Updated: 2018/09/14 10:54:28 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_box_stacks *box_stacks, char dst_stack_code)
{
	t_box	*src;
	t_box	*dst;

	src = (dst_stack_code == 'a') ? box_stacks->b : box_stacks->a;
	dst = (dst_stack_code == 'a') ? box_stacks->a : box_stacks->b;
	while (src && src->is_empty)
		src = src->next;
	if (src)
	{
		while (dst && dst->next && dst->next->is_empty)
			dst = dst->next;
		dst->num = src->num;
		dst->is_empty = false;
		src->is_empty = true;
	}
}
