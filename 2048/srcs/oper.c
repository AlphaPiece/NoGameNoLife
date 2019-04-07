/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 12:52:13 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/07 17:59:17 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void	move_up(int board[EDGE][EDGE])
{
	int	i, j, k;

	for (j = 0; j < EDGE; j++)
	{
		i = 0;
		k = 1;
		while (i < EDGE && k < EDGE)
			if (board[i][j] == 0)
				k = ft_max(2, ++i + 1, k);
			else if (board[k][j] == 0)
				k++;
			else if (board[i][j] == board[k][j])
			{
				board[i][j] += board[k][j];
				board[k][j] = 0;
				i = k + 1;
				k = i + 1;
			}
			else
			{
				i++;
				k++;
			}
	}
	for (j = 0; j < EDGE; j++)
	{
		i = 0;
		k = 1;
		while (i < EDGE && k < EDGE)
			if (board[i][j] != 0)
				k = ft_max(2, ++i + 1, k);
			else if (board[k][j] == 0)
				k++;
			else
				ft_swap(&board[i][j], &board[k][j]);
	}
}

void	move_down(int board[EDGE][EDGE])
{
	int	i, j, k;

	for (j = 0; j < EDGE; j++)
	{
		i = EDGE - 1;
		k = i - 1;
		while (i >= 0 && k >= 0)
			if (board[i][j] == 0)
				k = ft_min(2, --i - 1, k);
			else if (board[k][j] == 0)
				k--;
			else if (board[i][j] == board[k][j])
			{
				board[i][j] += board[k][j];
				board[k][j] = 0;
				i = k - 1;
				k = i - 1;
			}
			else
			{
				i--;
				k--;
			}
	}
	for (j = 0; j < EDGE; j++)
	{
		i = EDGE - 1;
		k = i - 1;
		while (i >= 0 && k >= 0)
			if (board[i][j] != 0)
				k = ft_min(2, --i - 1, k);
			else if (board[k][j] == 0)
				k--;
			else
				ft_swap(&board[i][j], &board[k][j]);
	}
}

void	move_left(int board[EDGE][EDGE])
{
	int	i, j, k;

	for (i = 0; i < EDGE; i++)
	{
		j = 0;
		k = 1;
		while (j < EDGE && k < EDGE)
			if (board[i][j] == 0)
				k = ft_max(2, ++j + 1, k);
			else if (board[i][k] == 0)
				k++;
			else if (board[i][j] == board[i][k])
			{
				board[i][j] += board[i][k];
				board[i][k] = 0;
				j = k + 1;
				k = j + 1;
			}
			else
			{
				j++;
				k++;
			}
	}
	for (i = 0; i < EDGE; i++)
	{
		j = 0;
		k = 1;
		while (j < EDGE && k < EDGE)
			if (board[i][j] != 0)
				k = ft_max(2, ++j + 1, k);
			else if (board[i][k] == 0)
				k++;
			else
				ft_swap(&board[i][j], &board[i][k]);
	}
}

void	move_right(int board[EDGE][EDGE])
{
	int	i, j, k;

	for (i = 0; i < EDGE; i++)
	{
		j = EDGE - 1;
		k = j - 1;
		while (j >= 0 && k >= 0)
			if (board[i][j] == 0)
				k = ft_min(2, --j - 1, k);
			else if (board[i][k] == 0)
				k--;
			else if (board[i][j] == board[i][k])
			{
				board[i][j] += board[i][k];
				board[i][k] = 0;
				j = k - 1;
				k = j - 1;
			}
			else
			{
				j--;
				k--;
			}
	}
	for (i = 0; i < EDGE; i++)
	{
		j = EDGE - 1;
		k = j - 1;
		while (j >= 0 && k >= 0)
			if (board[i][j] != 0)
				k = ft_min(2, --j - 1, k);
			else if (board[i][k] == 0)
				k--;
			else
				ft_swap(&board[i][j], &board[i][k]);
	}
}
