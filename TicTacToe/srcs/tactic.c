/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tactic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 09:15:18 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/08 12:58:56 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tic_tac_toe.h"

int		minimax(char board[EDGE][EDGE], int r, int c, int player, int val)
{
	int	score, best_score;
	int	i, j;

	board[r][c] = player;
	if (player_won(board, player))
	{
		board[r][c] = ' ';
		return (val);
	}
	else if (is_full(board))
	{
		board[r][c] = ' ';
		return (0);
	}
	best_score = (-val > 0) ? -2 : 2;
	for (i = 0; i < EDGE; i++)
		for (j = 0; j < EDGE; j++)
			if (is_valid_place(board, i, j))
			{
				score = minimax(board, i, j,
								(player == 'O') ? 'X' : 'O', -val);
				if (-val > 0 && score > best_score)
					best_score = score;
				else if (-val < 0 && score < best_score)
					best_score = score;
			}
	board[r][c] = ' ';
	return (best_score);
}
