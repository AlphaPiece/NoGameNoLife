/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:36:25 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/09 19:27:48 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minesweeper.h"

void	set_mines(t_info *info)
{
	int	*arr;
	int	i, j;

	arr = ft_randintarr(0, info->edge - 1, info->mines_no * 2);
	info->mines_r = (int *)malloc(sizeof(int) * info->mines_no);
	info->mines_c = (int *)malloc(sizeof(int) * info->mines_no);
	i = 0;
	for (j = 0; j < info->mines_no; j++)
		info->mines_r[j] = arr[i++];
	for (j = 0; j < info->mines_no; j++)
		info->mines_c[j] = arr[i++];
	free(arr);
}

void	set_board(t_info *info)
{
	char	chr;
	int		i, j;

	do
	{
		ft_printf("Difficulty level (0/1/2): ");
		chr = ft_getonechar();
	} while (chr < '0' && chr > '2');
	switch (chr)
	{
		case '0':
			info->edge = EDGE_0;
			info->mines_no = MINES_0;
			break ;
		case '1':
			info->edge = EDGE_1;
			info->mines_no = MINES_1;
			break ;
		case '2':
			info->edge = EDGE_2;
			info->mines_no = MINES_2;
			break ;
	}
	info->board = (char **)malloc(sizeof(char *) * (info->edge + 1));
	for (i = 0; i < info->edge; i++)
	{
		info->board[i] = (char *)malloc(sizeof(char) * (info->edge + 1));
		for (j = 0; j < info->edge; j++)
			info->board[i][j] = UNKNOWN;
		info->board[i][j] = '\0';
	}
	info->board[i] = NULL;
	set_mines(info);
}

void	game_loop(t_info *info)
{
	ft_printf("\nGame starts!\n");
	while (!info->is_dead)
	{
		game_status(info);
		pick_place(info);
		if (is_clear(info))
		{
			clear_mines(info);
			break ;
		}
	}
	game_status(info);
	if (info->is_dead)
		ft_printf("\nYou died.\n");
	else
		ft_printf("\nYou survived.\n");
	ft_printf("Game over.\n");
}

int		main(void)
{
	t_info	info;

	info.is_dead = false;
	set_board(&info);
	game_loop(&info);
	return (0);
}
