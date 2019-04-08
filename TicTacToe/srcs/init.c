/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 22:07:09 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/07 22:33:18 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tic_tac_toe.h"

void	game_loop(char board[EDGE][EDGE])
{
	int		turn_no;
	char	player;

	turn_no = 0;
	while (!is_full(board))
	{
		player = (turn_no % 2 == 0) ? 'O' : 'X';
		board_status(board, player);
		next_place(board, player);
		if (player_won(board, player))
		{
			ft_printf("Player %c won!\n", player);
			break ;
		}
	}
}

int		main(void)
{
	char	board[EDGE][EDGE];
	int		i, j;

	for (i = 0; i < EDGE; i++)
		for (j = 0; j < EDGE; j++)
			board[i][j] = 'E';
	game_loop(board);
	return (0);
}
