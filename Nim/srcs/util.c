/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:51:28 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/09 11:15:14 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nim.h"

t_bool	is_over(t_note *note)
{
	int	i;
	
	for (i = 0; i < note->piles_no; i++)
		if (note->piles[i] != 0)
			return (false);
	return (true);
}

void	game_status(t_note *note)
{
	int	i;

	ft_putchar('\n');
	ft_putncharln('=', 18);
	if (note->piles_no == 1)
		ft_printf("Stones: %d\n", note->piles[0]);
	else
		for (i = 0; i < note->piles_no; i++)
			ft_printf("Pile %d: %d stone(s)\n", i + 1, note->piles[i]);
	ft_printf("\nMinimum pick: %d\n", note->min_pick);
	ft_printf("Maximum pick: %d\n", note->max_pick);
	ft_putncharln('=', 18);
	ft_putchar('\n');
}

int		player_pick(t_note *note, char player)
{
	if (player == 'A')
	{
		if (note->a_mode == 'c' && note->piles_no == 1 )
			return (computer_mode_single_pile(note));
		else
			return (human_mode(note));

	}
	else
	{
		if (note->b_mode == 'c' && note->piles_no == 1)
			return (computer_mode_single_pile(note));
		else
			return (human_mode(note));

	}
}
