/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_solver.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 10:10:43 by zwang             #+#    #+#             */
/*   Updated: 2018/08/13 12:34:55 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Function remove_or_add puts a tetromino on the current board_state. In other
** words, it puts those 4 coordinate position of tetromino sharps on the
** board_state.
*/

static void	remove_or_add(t_board *board, int tetro_index, t_point pos,
							int remove_add)
{
	int			i;
	char		c;
	t_tetro		*tetro_struct;

	tetro_struct = board->tetro_list[tetro_index];
	i = 0;
	c = (remove_add == 1) ? 'A' + tetro_index : '.';
	while (i < 4)
	{
		board->board_state[tetro_struct->points[i].x + pos.x]
							[tetro_struct->points[i].y + pos.y] = c;
		i++;
	}
}

/*
** Function backtrack_map uses the Backtracking Algorithm to check every
** possibility of ways of filling tetrominoes in the current board_state.
*/

int			backtrack_map(t_board *board, int tetro_index)
{
	int			i;
	int			j;
	t_point		pos;

	if (tetro_index >= board->tetro_amt)
		return (1);
	i = -1;
	while (++i < board->sq_len)
	{
		j = -1;
		while (++j < board->sq_len)
		{
			pos.x = i;
			pos.y = j;
			if (is_safe(board, board->tetro_list[tetro_index], pos))
			{
				remove_or_add(board, tetro_index, pos, 1);
				if (backtrack_map(board, tetro_index + 1))
					return (1);
				remove_or_add(board, tetro_index, pos, 0);
			}
		}
	}
	return (0);
}

/*
** Function fill_square apply the function backtrack_map to board_states one
** by one until it finds a board_state which can contain all tetrominoes.
** If the current board_state cannot contain all, it increment the length of
** the board_state by 1.
**
** Since this program uses alphabet to represent each tetromino, it can
** deal with 26 tetrominoes at most.
*/

t_board		*fill_square(char **tetro_strings, int tetro_amt)
{
	int			tetro_index;
	t_board		*board;
	t_tetro		**tetro_list;

	if (!(tetro_list = get_tetro_list(tetro_strings, tetro_amt)))
		return (NULL);
	board = create_board(tetro_list, tetro_amt);
	tetro_index = 0;
	while (!backtrack_map(board, tetro_index))
		increment_board_state(board);
	return (board);
}
