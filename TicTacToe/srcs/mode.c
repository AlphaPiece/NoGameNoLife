/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 09:55:57 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/08 20:21:20 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tic_tac_toe.h"

void	human_mode(char board[EDGE][EDGE], char player)
{
	char	*buf;
	char	**coor;
	int		r, c;

	while (true)
	{
		ft_printf("Place (row, column): ");
		ft_nextline(0, &buf);
		coor = ft_strsplit(buf, " \t\n,()");
		free(buf);
		if (ft_strarrlen((const char **)coor) < 2)
		{
			ft_strarrdel(coor);
			continue ;
		}
		r = ft_atoi(coor[0]) - 1;
		c = ft_atoi(coor[1]) - 1;
		ft_strarrdel(coor);
		if (is_valid_place(board, r, c))
		{
			board[r][c] = player;
			break ;
		}
	}
	ft_putchar('\n');
}

void	computer_mode(char board[EDGE][EDGE], char player)
{
	int	i, j;
	int	score, best_score, best_pos[2];

	best_score = -2;
	for (i = 0; i < EDGE; i++)
		for (j = 0; j < EDGE; j++)
			if (is_valid_place(board, i, j))
			{
				score = minimax(board, i, j, player, 1);
				if (score > best_score)
				{
					best_score = score;
					best_pos[0] = i;
					best_pos[1] = j;
				}
			}
	board[best_pos[0]][best_pos[1]] = player;
	ft_printf("Place (row, column): (%d, %d)\n\n",
				best_pos[0] + 1, best_pos[1] + 1);
}
