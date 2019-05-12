/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_get_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 21:16:24 by zwang             #+#    #+#             */
/*   Updated: 2018/10/26 13:30:41 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Function check_tetor is a helper function of function advanced_validate.
** It can check if the shape of the tetromino in each tetro_string is correct
** or not. The basic idea is to count the total times the each tetromino sharp
** touches another tetromino sharp. If the total times is equal to or more
** than 6, then it is a valid form of tetrominoes.
*/

static int	check_tetro(char *tetro_string)
{
	int		i;
	int		j;
	int		list[4];

	i = 0;
	while (i < 4)
		list[i++] = 0;
	i = -1;
	j = 0;
	while (j < 4 && tetro_string[++i])
	{
		if (tetro_string[i] == '#' && i - 5 >= 0)
			list[j] += (tetro_string[i - 5] == '#') ? 1 : 0;
		if (tetro_string[i] == '#' && i + 5 <= 19)
			list[j] += (tetro_string[i + 5] == '#') ? 1 : 0;
		if (tetro_string[i] == '#' && i > 0)
			list[j] += (tetro_string[i - 1] == '#') ? 1 : 0;
		if (tetro_string[i] == '#' && i < 19)
			list[j] += (tetro_string[i + 1] == '#') ? 1 : 0;
		if (tetro_string[i] == '#')
			j++;
	}
	if (list[0] + list[1] + list[2] + list[3] >= 6)
		return (1);
	return (0);
}

/*
** Function advanced_validate checks if all the shapes of the tetrominoes
** are valid or not.
*/

int			advanced_validate(char **tetro_strings)
{
	int		i;

	i = -1;
	while (tetro_strings[++i])
		if (!check_tetro(tetro_strings[i]))
			return (0);
	return (i);
}

/*
** Function shift_all_points is a helper function of function create_points.
** It shifts the tetromino to the upper-left corner of
** the 4 x 4 squares in which it holds the form of tetrominoes.
*/

static void	shift_all_points(t_tetro *tetro_struct, int min_row, int min_col)
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		tetro_struct->points[i].x -= min_row;
		tetro_struct->points[i].y -= min_col;
	}
}

/*
** Function create_points is a helper function of function get_tetro_struct.
** It finds out the coordinate position of each tetromino sharps and store
** in a tetro_struct.
** It also calls the function shift_all_points to move the coordinate position
** of a tetromino to the upper-left corner. So at the end the coordinate
** position stored in the tetro_struct is the most upper-left position in
** the 4 x 4 squares in which it holds the form of tetrominoes.
*/

static void	create_points(t_tetro *tetro_struct, char **tetro_split)
{
	int		i;
	int		j;
	int		min_row;
	int		min_col;
	int		point;

	i = -1;
	min_row = 10;
	min_col = 10;
	point = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (tetro_split[i][j] == '#')
			{
				tetro_struct->points[point].x = i;
				tetro_struct->points[point++].y = j;
				min_row = i < min_row ? i : min_row;
				min_col = j < min_col ? j : min_col;
			}
		}
	}
	shift_all_points(tetro_struct, min_row, min_col);
}

/*
** Function get_tetro_struct create a tetro_struct for each tetromino based on
** the string information of that tetromino given as an argument.
** The tetro_struct stores the upper-left coordinate position of a tetromino.
*/

t_tetro		*get_tetro_struct(char *tetro_string)
{
	char		**tetro_split;
	int			i;
	t_tetro		*tetro_struct;

	if (!(tetro_struct = (t_tetro *)malloc(sizeof(t_tetro))))
		return (NULL);
	i = -1;
	while (++i < 4)
	{
		tetro_struct->points[i].x = 0;
		tetro_struct->points[i].y = 0;
	}
	if (!(tetro_split = ft_strsplit(tetro_string, "\n")))
		return (NULL);
	create_points(tetro_struct, tetro_split);
	i = -1;
	while (tetro_split[++i])
		ft_strdel(&tetro_split[i]);
	free(tetro_split);
	return (tetro_struct);
}
