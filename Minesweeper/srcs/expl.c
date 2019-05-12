/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:07:34 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/09 19:05:45 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minesweeper.h"

t_bool	is_mine(t_info *info, int r, int c)
{
	int	i;

	for (i = 0; i < info->mines_no; i++)
		if (info->mines_r[i] == r && info->mines_c[i] == c)
			return (true);
	return (false);
}

void	explode_all_mines(t_info *info)
{
	int	i;

	for (i = 0; i < info->mines_no; i++)
		info->board[info->mines_r[i]][info->mines_c[i]] = 'X';
}

int		count_mines_around(t_info *info, int r, int c)
{
	int	i, j;
	int	count;
	
	count = 0;
	for (i = r - 1; i <= r + 1; i++)
		for (j = c - 1; j <= c + 1; j++)
			if ((i != r || j != c) && is_valid_place(info, i, j) &&
					is_mine(info, i, j))
				count++;
	return (count);
}

void	explore_area(t_info *info, int r, int c)
{
	info->board[r][c] = count_mines_around(info, r, c) + '0';
	if (info->board[r][c] == '0')
	{
		if (is_valid_place(info, r - 1, c))
			explore_area(info, r - 1, c);
		if (is_valid_place(info, r + 1, c))
			explore_area(info, r + 1, c);
		if (is_valid_place(info, r, c - 1))
			explore_area(info, r, c - 1);
		if (is_valid_place(info, r, c + 1))
			explore_area(info, r, c + 1);
	}
}
