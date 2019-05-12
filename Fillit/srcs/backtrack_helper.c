/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 10:26:18 by zwang             #+#    #+#             */
/*   Updated: 2018/08/07 15:04:48 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Function get_tetro_list creates a linked list which is composed by all the
** tetro_structs.
*/

t_tetro		**get_tetro_list(char **tetro_strings, int tetro_cnt)
{
	t_tetro		**tetro_list;
	int			i;

	if (!(tetro_list = (t_tetro **)malloc(sizeof(t_tetro *) * (tetro_cnt + 1))))
		return (NULL);
	i = -1;
	while (++i < tetro_cnt)
		tetro_list[i] = get_tetro_struct(tetro_strings[i]);
	tetro_list[i] = NULL;
	return (tetro_list);
}

/*
** Function create_board initializes a board (square) for filling tetrominoes.
** The board_state is a 2-D array.
*/

t_board		*create_board(t_tetro **tetro_list, int tetro_amt)
{
	int			i;
	int			j;
	t_board		*board;
	char		**board_state;

	if (!(board = (t_board *)malloc(sizeof(t_board))))
		return (NULL);
	board->tetro_amt = tetro_amt;
	board->sq_len = (int)ft_sqrt(tetro_amt * 4);
	board->tetro_list = tetro_list;
	if (!(board_state = (char **)malloc(sizeof(char *) * (board->sq_len + 1))))
		return (NULL);
	i = -1;
	while (++i < board->sq_len)
	{
		if (!(board_state[i] = ft_strnew(board->sq_len + 1)))
			return (NULL);
		j = -1;
		while (++j < board->sq_len)
			board_state[i][j] = '.';
	}
	board_state[i] = NULL;
	board->board_state = board_state;
	return (board);
}

/*
** Function delete_board_state is used when the current board_state cannot
** contain all tetrominoes.
*/

void		delete_board_state(t_board *board)
{
	char	**prev;
	char	**curr;

	prev = board->board_state;
	while (*prev)
	{
		curr = prev + 1;
		ft_strdel(prev);
		prev = curr;
	}
	free(board->board_state);
	board->board_state = NULL;
}

/*
** Function increment_board_state increment the size of board_state by 1.
*/

int			increment_board_state(t_board *board)
{
	char	**new_state;
	int		i;
	int		j;

	delete_board_state(board);
	board->sq_len += 1;
	if (!(new_state = (char **)malloc(sizeof(char *) * (board->sq_len + 1))))
		return (0);
	i = 0;
	while (i < board->sq_len)
	{
		if (!(new_state[i] = ft_strnew(board->sq_len + 1)))
			return (0);
		j = 0;
		while (j < board->sq_len)
			new_state[i][j++] = '.';
		i++;
	}
	new_state[i] = NULL;
	board->board_state = new_state;
	return (1);
}

/*
** Function is_safe checks if a position in a board_state is safe or not.
** A position is 'safe' means it allows all the tetromino sharp stay inside
** the boundary of the current board_state, as well as there is no other
** tetrominoes occupying this position.
** Although it's said 'a' position, it's actually 4 position. This function
** adds the coordinate position (x, y) to the coordinate position of each
** tetromino sharp and check if the final coordinate is 'safe' or not.
*/

int			is_safe(t_board *board, t_tetro *tetro_struct, t_point pos)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (tetro_struct->points[i].x + pos.x >= board->sq_len ||
					tetro_struct->points[i].y + pos.y >= board->sq_len ||
					(board->board_state[tetro_struct->points[i].x + pos.x]
						[tetro_struct->points[i].y + pos.y] != '.'))
			return (0);
		i++;
	}
	return (1);
}
