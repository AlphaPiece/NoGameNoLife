/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 11:41:43 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/05/10 17:26:59 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void	game_loop(int board[EDGE][EDGE])
{
	char	chr;

	ft_printf("Game starts!\n");
	while (!is_full(board) && !game_won(board))
	{
		random_pop(board);
		board_status(board);
		ft_printf("w: move up\ns: down\na: left\nd: right\nq: quit\n\n");
		do
		{
			ft_printf("Enter: ");
			chr = ft_getonechar();
		} while (chr != 'w' && chr != 's' && chr != 'a' && chr != 'd' &&
					chr != 'q');
		if (chr == 'q')
			break ;
		switch (chr)
		{
			case 'w':
				move_up(board);
				break ;
			case 's':
				move_down(board);
				break ;
			case 'a':
				move_left(board);
				break ;
			case 'd':
				move_right(board);
				break ;
		}
	}
	ft_printf("\nGame over.\n");	
}

int		main(void)
{
	int	board[EDGE][EDGE] = {0};

	game_loop(board);
	return (0);
}
