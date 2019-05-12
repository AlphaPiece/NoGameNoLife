/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 22:30:07 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/08 09:58:59 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tic_tac_toe.h"

t_bool	is_full(char board[EDGE][EDGE])
{
	int	i, j;

	for (i = 0; i < EDGE; i++)
		for (j = 0; j < EDGE; j++)
			if (board[i][j] == ' ')
				return (false);
	return (true);
}

void	board_status(char board[EDGE][EDGE])
{
	ft_printf(" 0 | 1 | 2 | 3\n");
	ft_putnchar('-', 15);
	ft_printf("\n 1 | %c | %c | %c\n",
				board[0][0], board[0][1], board[0][2]);
	ft_putnchar('-', 15);
	ft_printf("\n 2 | %c | %c | %c\n",
				board[1][0], board[1][1], board[1][2]);
	ft_putnchar('-', 15);
	ft_printf("\n 3 | %c | %c | %c\n",
				board[2][0], board[2][1], board[2][2]);
	ft_printf("\n");
}

t_bool	is_valid_place(char board[EDGE][EDGE], int r, int c)
{
	return (r >= 0 && r < EDGE && c >= 0 && c < EDGE && board[r][c] == ' ');
}

void	next_place(char board[EDGE][EDGE], char player, char mode)
{
	if (mode == 'h')
		human_mode(board, player);
	else
		computer_mode(board, player);
}

t_bool	player_won(char board[EDGE][EDGE], char player)
{
	int	i;

	for (i = 0; i < EDGE; i++)
		if ((board[i][0] == player && board[i][1] == player &&
				board[i][2] == player) || (board[0][i] == player &&
				board[1][i] == player && board[2][i] == player))
			return (true);
	if (board[1][1] == player && ((board[0][0] == player 
			&& board[2][2] == player) || (board[2][0] == player &&
			board[0][2] == player)))
		return (true);
	return (false);
}

