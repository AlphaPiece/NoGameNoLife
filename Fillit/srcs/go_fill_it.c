/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_fill_it.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 14:55:34 by zwang             #+#    #+#             */
/*   Updated: 2018/08/13 12:42:51 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Function go_fill_it calls all the other functions to fill a smallest square
** using the tetrominoes in the input file.
** It returns 0 when the input file is invalid; 1 when the solution found.
*/

static int	go_fill_it(char *file_name)
{
	char		*whole_string;
	char		**tetro_strings;
	int			i;
	int			tetro_amt;
	t_board		*board;

	whole_string = NULL;
	tetro_strings = NULL;
	if (!(whole_string = get_whole_string(file_name, whole_string)) ||
			!(tetro_amt = basic_validate(whole_string)))
		return (0);
	tetro_strings = get_tetro_strings(whole_string, tetro_strings, tetro_amt);
	if (!advanced_validate(tetro_strings))
		return (0);
	board = fill_square(tetro_strings, tetro_amt);
	i = -1;
	while (board->board_state[++i])
		ft_putendl(board->board_state[i]);
	return (1);
}

int			main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit input_file\n");
		return (1);
	}
	if (!go_fill_it(argv[1]))
	{
		ft_putstr("error\n");
		return (2);
	}
	return (0);
}
