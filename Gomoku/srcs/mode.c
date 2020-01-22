/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 22:05:27 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/05/25 19:49:25 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.h"

void	human_mode(char board[EDGE][EDGE], char player)
{
	char	*buf, **coor;
	int		r, c;

	do
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
	} while (!is_empty_place(board, r, c));
	board[r][c] = player;
}

void	computer_mode(char board[EDGE][EDGE], char player)
{
	int	i, j;
	int	scores[EDGE][EDGE];
	int	max_score, place[2];

	for (i = 0; i < EDGE; i++)
		for (j = 0; j < EDGE; j++)
			if (is_empty_place(board, i, j))
				scores[i][j] = eval_place_score(board, i, j, board[i][j]);
			else
				scores[i][j] = 0;
	max_score = -100000;
	for (i = 0; i < EDGE; i++)
		for (j = 0; j < EDGE; j++)
			if (board[i][j] == '.' && scores[i][j] > max_score)
			{
				max_score = scores[i][j];
				place[0] = i;
				place[1] = j;
			}
	board[place[0]][place[1]] = player;
	ft_printf("Place (row, column): (%d, %d)\n", place[0] + 1, place[1] + 1);
}
