/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 11:41:43 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/07 12:01:18 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"

void	game_loop(int board[EDGE][EDGE])
{
	char	chr;

	while (!is_full(board))
	{
		random_pop(board);
		board_status(board);
		chr = ft_getchar();
		while (chr != 'w' && chr != 's' && chr != 'a' && chr != 'd')
			chr = ft_getchar();
		switch (chr)
		{
			case 'w':
				move_up(borad);
				break ;
			case 's':
				move_down(borad);
				break ;
			case 'a':
				move_left(borad);
				break ;
			case 'd':
				move_right(borad);
				break ;
		}
	}
	board_status(board);
}

int		main(void)
{
	int	board[EDGE][EDGE] = {0};

	game_loop(board);
	return (0);
}
