/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_get_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 10:25:19 by zwang             #+#    #+#             */
/*   Updated: 2018/08/07 15:04:18 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Function get_whole_string gets the data in the file as a whole string.
*/

char		*get_whole_string(char *file_name, char *whole_string)
{
	int		file_desc;
	size_t	size;
	char	characters[600];

	if ((file_desc = open(file_name, O_RDONLY)) < 1)
		return (NULL);
	size = read(file_desc, characters, 599);
	characters[size] = '\0';
	if (!(whole_string = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	whole_string = ft_strcpy(whole_string, characters);
	return (whole_string);
}

/*
** Function check_block is a helper function of function basic_validate. It
** can check if a tetromino block is correct or not.
*/

static int	check_block(char *whole_string, int *i)
{
	int		j;
	int		k;
	int		sharps;

	j = 0;
	sharps = 0;
	while (j++ < 4)
	{
		k = 0;
		while (k++ < 4)
		{
			if (whole_string[*i] == '#')
				sharps++;
			else if (whole_string[*i] != '.')
				return (0);
			(*i)++;
		}
		if (whole_string[(*i)++] != '\n')
			return (0);
	}
	if (sharps != 4)
		return (0);
	return (1);
}

/*
** Function basic_validate uses the whole string obtained form function
** get_whole_string to check if the format of the file is correct or not.
*/

int			basic_validate(char *whole_string)
{
	int		i;
	int		tetro_amt;

	i = 0;
	tetro_amt = 0;
	while (whole_string[i])
	{
		tetro_amt++;
		if (!check_block(whole_string, &i))
			return (0);
		if (whole_string[i] == '\n' && !whole_string[i + 1])
			return (0);
		else if (whole_string[i] && whole_string[i] != '\n')
			return (0);
		else if (!whole_string[i])
			return (tetro_amt);
		i++;
	}
	if (whole_string[i - 1] == '\n' && whole_string[i - 2] == '\n')
		return (0);
	return (tetro_amt);
}

/*
** Function get_tetro_strings separates whole_string to a 2-D array, and each
** element of the array is the string of a whole tetromino block. Return value
** is the number of tetrominoes in the file.
*/

char		**get_tetro_strings(char *whole_string, char **tetro_strings,
								int tetro_amt)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!(tetro_strings = (char **)malloc(sizeof(char *) * (tetro_amt + 1))))
		return (NULL);
	while (whole_string[j] && i < tetro_amt)
	{
		if (!(tetro_strings[i] = ft_strnew(21)))
			return (NULL);
		ft_strncpy(tetro_strings[i], &whole_string[j], 20);
		i++;
		j = j + 21;
	}
	tetro_strings[i] = NULL;
	return (tetro_strings);
}
