/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 12:01:55 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/05/10 17:18:44 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

t_bool	is_full(int board[EDGE][EDGE])
{
	int	i;
	int	j;

	for (i = 0; i < EDGE; i++)
		for (j = 0; j < EDGE; j++)
			if (board[i][j] == 0)
				return (false);
	return (true);
}

t_bool	game_won(int board[EDGE][EDGE])
{
	int	i;
	int	j;

	for (i = 0; i < EDGE; i++)
		for (j = 0; j < EDGE; j++)
			if (board[i][j] == 2048)
				return (true);
	return (false);
}

void	random_pop(int board[EDGE][EDGE])
{
	int	i, j;

	while (true)
	{
		i = ft_randint(0, EDGE - 1);
		j = ft_randint(0, EDGE - 1);
		if (board[i][j] == 0)
		{
			board[i][j] = 2;
			break ;
		}
	}
}

void	board_status(int board[EDGE][EDGE])
{
	ft_printf("\n");
	ft_putnchar('-', 21);
	ft_printf("\n|%4.d|%4.d|%4.d|%4.d|\n",
				board[0][0], board[0][1], board[0][2], board[0][3]);
	ft_putnchar('-', 21);
	ft_printf("\n|%4.d|%4.d|%4.d|%4.d|\n",
				board[1][0], board[1][1], board[1][2], board[1][3]);
	ft_putnchar('-', 21);
	ft_printf("\n|%4.d|%4.d|%4.d|%4.d|\n",
				board[2][0], board[2][1], board[2][2], board[2][3]);
	ft_putnchar('-', 21);
	ft_printf("\n|%4.d|%4.d|%4.d|%4.d|\n",
				board[3][0], board[3][1], board[3][2], board[3][3]);
	ft_putnchar('-', 21);
	ft_printf("\n\n");
}

