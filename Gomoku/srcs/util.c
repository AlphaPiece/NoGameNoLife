/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:45:02 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/11 20:24:47 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.h"

t_bool	is_over(char board[EDGE][EDGE])
{
	int		i, j, k;
	char	player;

	for (i = 0; i < EDGE; i++)
		if (ft_strstr(board[i], "XXXXX") || ft_strstr(board[i], "OOOOO"))
			return (true);
	for (j = 0; j < EDGE; j++)
	{
		i = 0;
		while (i < EDGE)
		{
			while (board[i][j] == '.')
				i++;
			k = 0;
			while (i + k < EDGE && board[i + k][j] == 'X')
				k++;
			if (k >= 5)
				return (true);
			i += k;
			while (board[i][j] == '.')
				i++;
			k = 0;
			while (i + k < EDGE && board[i + k][j] == 'O')
				k++;
			if (k >= 5)
				return (true);
			i += k;
		}
	}
	for (i = 0; i < EDGE; i++)
		for (j = 0; j < EDGE; j++)
		{
			player = board[i][j];
			if (player != '.')
			{
				if (ne_pieces(board, i, j, player) + 
						sw_pieces(board, i, j, player) >= 4)
					return (true);
				if (nw_pieces(board, i, j, player) +
						se_pieces(board, i, j, player) >= 4)
					return (true);
			}
		}
    return (false);
}

void	game_status(char board[EDGE][EDGE])
{
	int	i, j;

	ft_putchar('\n');
	ft_putnchar(' ', 6);
	for (i = 1; i < EDGE / 10 + 1; i++)
	{
		ft_putnchar(' ', 19);
		ft_putchar('0' + i % 10);
	}
	ft_printf("\n   0 |");
	for (i = 1; i <= EDGE; i++)
		ft_printf(" %d", i % 10);
	ft_putchar('\n');
	ft_putnchar(' ', 3);
	ft_putncharln('-', 3 + EDGE * 2);
	for (i = 1; i <= EDGE; i++)
	{
		if (i % 10 == 0)
			ft_printf("%2.d %d |", i / 10, i % 10);
		else
			ft_printf("   %d |", i % 10);
		for (j = 0; j < EDGE; j++)
			ft_printf(" %c", board[i - 1][j]);
		ft_putchar('\n');
	}
	ft_putchar('\n');
}

t_bool	is_empty_place(char board[EDGE][EDGE], int r, int c)
{
	return (r >= 0 && r < EDGE && c >= 0 && c < EDGE && board[r][c] == EMPTY);
}

void	player_move(char board[EDGE][EDGE], char player, char player_mode)
{
	if (player_mode == 'h')
		human_mode(board, player);
	else
		computer_mode(board, player);		
}
