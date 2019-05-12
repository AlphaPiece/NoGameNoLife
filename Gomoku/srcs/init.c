/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:30:10 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/11 20:27:22 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.h"

void	game_loop(char board[EDGE][EDGE], char x_mode, char o_mode)
{
	char	player;

	ft_printf("\nGame starts!\n");
	player = 'X';
	while (true)
	{
		game_status(board);
		player_move(board, player, (player == 'X') ? x_mode : o_mode);
		if (is_over(board))
			break ;
		player = (player == 'X') ? 'O' : 'X';
	}
	game_status(board);
	ft_printf("\nGame over.\n");
	ft_printf("Player %c won!\n", player);
}

void	prepare_game(char board[EDGE][EDGE], char *x_mode, char *o_mode)
{
	int	i, j;

	for (i = 0; i < EDGE; i++)
		for (j = 0; j < EDGE; j++)
			board[i][j] = '.';
	do
	{
		ft_printf("Humam/Computer mode for 'X' (h/c): ");
		*x_mode = ft_getonechar();
	} while (*x_mode != 'h' && *x_mode != 'c');
	do
	{
		ft_printf("Humam/Computer mode for 'X' (h/c): ");
		*o_mode = ft_getonechar();
	} while (*o_mode != 'h' && *o_mode != 'c');
}

int		main(void)
{
	char	board[EDGE][EDGE];
	char	x_mode, o_mode;

	prepare_game(board, &x_mode, &o_mode);
	game_loop(board, x_mode, o_mode);
	return (0);
}
