/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 11:42:22 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/07 13:16:20 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048_H
# define GAME_2048_H

# include "libft.h"

# define EDGE	4

t_bool	is_full(int board[EDGE][EDGE]);
t_bool	game_won(int board[EDGE][EDGE]);
void	random_pop(int board[EDGE][EDGE]);
void	board_status(int board[EDGE][EDGE]);

void	move_up(int board[EDGE][EDGE]);
void	move_down(int board[EDGE][EDGE]);
void	move_left(int board[EDGE][EDGE]);
void	move_right(int board[EDGE][EDGE]);

#endif
