/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:25:26 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/05/10 17:53:21 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minesweeper.h"

t_bool	is_clear(t_info *info)
{
	int	i, j;

	for (i = 0; i < info->edge; i++)
		for (j = 0; j < info->edge; j++)
			if (info->board[i][j] == UNKNOWN && !is_mine(info, i, j))
				return (false);
	return (true);
}

void	clear_mines(t_info *info)
{
	int	i;

	for (i = 0; i < info->mines_no; i++)
		info->board[info->mines_r[i]][info->mines_c[i]] = 'O';
}

void	game_status(t_info *info)
{
	int	i, j;

	ft_putchar('\n');
	ft_putnchar(' ', 6);
	for (i = 1; i < info->edge / 10 + 1; i++)
	{
		ft_putnchar(' ', 19);
		ft_putchar('0' + i % 10);
	}
	ft_printf("\n   0 |");
	for (i = 1; i <= info->edge; i++)
		ft_printf(" %d", i % 10);
	ft_putchar('\n');
	ft_putnchar(' ', 3);
	ft_putncharln('-', 3 + info->edge * 2);
	for (i = 1; i <= info->edge; i++)
	{
		if (i % 10 == 0)
			ft_printf("%2.d %d |", i / 10, i % 10);
		else
			ft_printf("   %d |", i % 10);
		for (j = 0; j < info->edge; j++)
			ft_printf(" %c", info->board[i - 1][j]);
		ft_putchar('\n');
	}
	ft_putchar('\n');
}

t_bool	is_valid_place(t_info *info, int r, int c)
{
	return (r >= 0 && r < info->edge && c >= 0 && c < info->edge &&
			info->board[r][c] == UNKNOWN);
}

void	pick_place(t_info *info)
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
	} while (!is_valid_place(info, r, c));
	if (is_mine(info, r, c))
	{
		info->is_dead = true;
		explode_all_mines(info);
	}
	else
		explore_area(info, r, c);
}
