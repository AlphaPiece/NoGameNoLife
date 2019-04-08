/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 22:30:07 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/07 23:06:27 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tic_tac_toe.h"

t_bool	is_full(char board[EDGE][EDGE])
{
	int	i, j;

	for (i = 0; i < EDGE; i++)
		for (j = 0; j < EDGE; j++)
			if (board[i][j] == 'E')
				return (false);
	return (true);
}

void	board_status(char board[EDGE][EDGE], char player)
{
	ft_printf("Player %c's turn:\n\n", player);
	ft_printf("|   | 1 | 2 | 3 |\n");
	ft_putnchar('-', 16);
	ft_printf("\n| 1 | %c | %c | %c |\n",
				board[0][0], board[0][1], board[0][2]);
	ft_putnchar('-', 16);
	ft_printf("\n| 2 | %c | %c | %c |\n",
				board[1][0], board[1][1], board[1][2]);
	ft_putnchar('-', 16);
	ft_printf("\n| 3 | %c | %c | %c |\n",
				board[2][0], board[2][1], board[2][2]);
	ft_putnchar('-', 16);
	ft_printf("\n\n");
}

t_bool	is_valid_place(char board[EDGE][EDGE], int x, int y)
{
	return (x > 0 && x <= EDGE && y > 0 && y <= EDGE &&
			board[x - 1][y - 1] == 'E');
}

void	next_place(char board[EDGE][EDGE], char player)
{
	char	*buf;
	char	**coor;

	while (true)
	{
		ft_printf("Place (e.g. 1 2):\n");
		ft_nextline(0, &buf);
		coor = ft_strsplit(buf);
		if (ft_strarrlen(coor) < 2)
		{
			free(buf);
			ft_strarrdel(coor);
			continue ;
		}
		if (is_valid_place(board, ft_atoi(coor[0]), ft_atoi(coor[1])))
		{	
			free(buf);
			ft_strarrdel(coor);
			break ;
		}
	}
	ft_putchar('\n');
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

