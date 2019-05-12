/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:43:18 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/11 14:22:24 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.h"

int	n_pieces(char board[EDGE][EDGE], int r, int c, char player)
{
	int	count;

	count = 0;
	for (r = r - 1; r >= 0 && board[r][c] == player; r--)
		count++;
	return (count);
}

int	s_pieces(char board[EDGE][EDGE], int r, int c, char player)
{
	int	count;

	count = 0;
	for (r = r + 1; r < EDGE && board[r][c] == player; r++)
		count++;
	return (count);
}

int	w_pieces(char board[EDGE][EDGE], int r, int c, char player)
{
	int	count;

	count = 0;
	for (c = c - 1; c >= 0 && board[r][c] == player; c--)
		count++;
	return (0);
}

int	e_pieces(char board[EDGE][EDGE], int r, int c, char player)
{
	int	count;

	count = 0;
	for (c = c + 1; c < EDGE && board[r][c] == player; c++)
		count++;
	return (count);
}

int	nw_pieces(char board[EDGE][EDGE], int r, int c, char player)
{
	int	count;

	count = 0;
	for (r = r - 1, c = c - 1; r >= 0 && c >= 0 && board[r][c] == player;
			r--, c--)
		count++;
	return (count);
}

int	ne_pieces(char board[EDGE][EDGE], int r, int c, char player)
{
	int	count;

	count = 0;
	for (r = r - 1, c = c + 1; r >= 0 && c < EDGE && board[r][c] == player;
			r--, c++)
		count++;
	return (count);
}

int sw_pieces(char board[EDGE][EDGE], int r, int c, char player)
{
	int	count;

	count = 0;
	for (r = r + 1, c = c - 1; r < EDGE && c >= 0 && board[r][c] == player;
			r++, c--)
		count++;
	return (count);
}

int	se_pieces(char board[EDGE][EDGE], int r, int c, char player)
{
	int	count;

	count = 0;
	for (r = r + 1, c = c + 1; r < EDGE && c < EDGE && board[r][c] == player;
			r++, c++)
		count++;
	return (count);
}
