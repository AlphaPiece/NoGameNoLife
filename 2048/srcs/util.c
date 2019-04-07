/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 12:01:55 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/07 12:51:54 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"

void	is_full(int board[EDGE][EDGE])
{
	int	i, j;

	for (i = 0; i < EDGE; i++)
		for (j = 0; j < EDGE; j++)
			if (board[i][j] != 0)
				return (false);
	return (true);
}

void	random_pop(int board[EDGE][EDGE])
{
	static int	*arr = NULL;
	static int	len = EDGE * 100;
	static int	i = 0;
	static int	j = len / 2;

	if (!arr)
		arr = ft_randintarr(0, EDGE - 1, len);
	while (true)
	{
		if (i == len / 2 || j == len)
		{
			free(arr);
			arr = ft_randintarr(0, EDGE - 1, len);
			i = 0;
			j = len / 2;
		}
		if (board[arr[i]][arr[j]] == 0)
		{
			board[arr[i]][arr[j]] = 2;
			break ;
		}
		i++;
		j++;
	}
}

void	board_status(int board[EDGE][EDGE])
{
	ft_putnchar('-', 21);
	ft_printf("|%4d|%4d|%4d|%4d|\n",
				board[0][0], board[0][1], board[0][2], board[0][3]);
	ft_putnchar('-', 21);
	ft_printf("|%4d|%4d|%4d|%4d|\n",
				board[1][0], board[1][1], board[1][2], board[1][3]);
	ft_putnchar('-', 21);
	ft_printf("|%4d|%4d|%4d|%4d|\n",
				board[2][0], board[2][1], board[2][2], board[2][3]);
	ft_putnchar('-', 21);
	ft_printf("|%4d|%4d|%4d|%4d|\n",
				board[3][0], board[3][1], board[3][2], board[3][3]);
	ft_putnchar('-', 21);
}

