/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 22:07:09 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/05/10 17:36:21 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tic_tac_toe.h"

void	game_loop(char board[EDGE][EDGE], char o_mode, char x_mode)
{
	int		turn_no;
	char	player;

	turn_no = 0;
	ft_printf("Game starts!\n\n");
	while (!is_full(board))
	{
		player = (turn_no++ % 2 == 0) ? 'O' : 'X';
		ft_printf("Player %c's turn:\n\n", player);
		board_status(board);			
		next_place(board, player, (player == 'O') ? o_mode : x_mode);
		if (player_won(board, player))
		{
			board_status(board);
			ft_printf("Player %c won!\n", player);
			ft_printf("Game over.\n");
			return ;
		}
	}
	board_status(board);
	ft_printf("It's a draw.\n");	
	ft_printf("Game over.\n");
}

char	set_mode(char player)
{
	char	chr;

	do
	{
		ft_printf("Human/Computer mode for '%c' (h/c): ", player);
		chr = ft_getonechar();
	} while (chr != 'h' && chr != 'c');
	return (chr);
}

int		main(void)
{
	char	board[EDGE][EDGE];
	int		i, j;
	char	o_mode, x_mode;

	for (i = 0; i < EDGE; i++)
		for (j = 0; j < EDGE; j++)
			board[i][j] = ' ';
	o_mode = set_mode('O');
	x_mode = set_mode('X');
	ft_putchar('\n');
	game_loop(board, o_mode, x_mode);
	return (0);
}
