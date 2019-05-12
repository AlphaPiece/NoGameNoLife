/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 10:10:22 by zwang             #+#    #+#             */
/*   Updated: 2018/09/14 10:54:13 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	act(t_box_stacks *box_stacks, t_command **cmd_queue, char *cmd_code)
{
	if (MATCH(cmd_code, "sa"))
		swap(box_stacks, 'a');
	else if (MATCH(cmd_code, "sb"))
		swap(box_stacks, 'b');
	else if (MATCH(cmd_code, "pa"))
		push(box_stacks, 'a');
	else if (MATCH(cmd_code, "pb"))
		push(box_stacks, 'b');
	else if (MATCH(cmd_code, "ra"))
		rotate(box_stacks, 'a');
	else if (MATCH(cmd_code, "rb"))
		rotate(box_stacks, 'b');
	else if (MATCH(cmd_code, "rra"))
		reverse_rotate(box_stacks, 'a');
	else if (MATCH(cmd_code, "rrb"))
		reverse_rotate(box_stacks, 'b');
	append_command(cmd_queue, create_command(cmd_code));
}
