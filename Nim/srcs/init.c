/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:21:55 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/08 17:24:42 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nim.h"

void	game_loop(t_note *note)
{
	char	player;
	int		pick;

	ft_printf("Game starts!\n");
	player = 'A';
	while (!is_over(note))
	{
		game_status(note);
		ft_printf("Player %c's turn:\n", player);
		pick = player_pick(note);
		player = (player == 'A') ? 'B' : 'A';
	}
	game_status(note);
	ft_printf("Since player %c has to\npick the last stone,\n", player);
	ft_printf("player %c won!\n", (player == 'A') ? 'B' : 'A');
}

int		main(void)
{
	t_note	note;

	note.piles_no = 3;
	note.piles = ft_randintarr(2, 4, note.piles_no);
	note.min_pick = 1;
	note.max_pick = 3;
	game_loop(&note);
	return (0);
}
