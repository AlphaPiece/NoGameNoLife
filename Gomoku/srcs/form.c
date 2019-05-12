/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:52:57 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/11 20:46:36 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.h"

void	get_ns_form(char board[EDGE][EDGE], int r, int c, char player,
					char ns_form[10])
{
	int	i, j;

	for (i = r - 4, j = 0; i <= r + 4; i++)
		if (i == r)
			ns_form[j++] = player;
		else if (i >= 0 && i < EDGE)
			ns_form[j++] = board[i][c];
	ns_form[j] = '\0';
}

void	get_we_form(char board[EDGE][EDGE], int r, int c, char player,
					char we_form[10])
{
	int	i, j;

	for (i = c - 4, j = 0; i <= c + 4; i++)
		if (i == r)
			we_form[j++] = player;
		else if (i >= 0 && i < EDGE)
			we_form[j++] = board[r][i];
	we_form[j] = '\0';
}

void	get_nwse_form(char board[EDGE][EDGE], int r, int c, char player,
						char nwse_form[10])
{
	int	i, j, k;

	for (i = r - 4, j = c - 4, k = 0; i <= r + 4 && j <= c + 4; i++, j++)
		if (i == r && j == c)
			nwse_form[k++] = player;
		else if (i >= 0 && i < EDGE && j >= 0 && j < EDGE)
			nwse_form[k++] = board[i][j];
	nwse_form[k] = '\0';
}

void	get_nesw_form(char board[EDGE][EDGE], int r, int c, char player,
						char nesw_form[10])
{
	int	i, j, k;

	for (i = r + 4, j = c - 4, k = 0; i >= r - 4 && j <= c + 4; i--, j++)
		if (i == r && j == c)
			nesw_form[k++] = player;
		else if (i >= 0 && i < EDGE && j >= 0 && j < EDGE)
			nesw_form[k++] = board[i][j];
	nesw_form[k] = '\0';
}
