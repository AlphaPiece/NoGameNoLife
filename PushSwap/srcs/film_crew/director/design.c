/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   design.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 11:28:53 by zwang             #+#    #+#             */
/*   Updated: 2018/09/15 12:10:45 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_command	*design_actions(t_box_stacks *box_stacks)
{
	if (box_stacks->len <= 3)
		return (simple_sort(box_stacks, box_stacks->len));
	else if (box_stacks->len <= 30)
		return (selection_sort(box_stacks));
	return (merge_sort(box_stacks));
}
