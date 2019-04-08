/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 22:07:09 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/07 23:47:02 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tic_tac_toe.h"

void	game_over_result(char board[EDGE][EDGE])
{
	ft_putnchar('=', 15);
	ft_printf("\n   Game Over\n");
	ft_putnchar('=', 15);
	ft_printf("\n\n");
	board_status(board);
}

void	game_loop(char board[EDGE][EDGE])
{
	int		turn_no;
	char	player;

	turn_no = 0;
	while (!is_full(board))
	{
		player = (turn_no++ % 2 == 0) ? 'O' : 'X';
		ft_printf("Player %c's turn:\n\n", player);
		board_status(board);
		next_place(board, player);
		if (player_won(board, player))
		{
			game_over_result(board);
			ft_printf("Player %c won!\n", player);
			return ;
		}
	}
	game_over_result(board);
	ft_printf("It's a draw.\n");	
}

int		main(void)
{
	char	board[EDGE][EDGE];
	int		i, j;

	for (i = 0; i < EDGE; i++)
		for (j = 0; j < EDGE; j++)
			board[i][j] = ' ';
	game_loop(board);
	return (0);
}
