/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2048.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 11:42:22 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/07 12:05:01 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 2048_H
# define 2048_H

# include "libft.h"

# define EDGE	4

void	is_full(int board[EDGE][EDGE]);
void	random_pop(int board[EDGE][EDGE]);
void	board_status(int board[EDGE][EDGE]);

void	move_up(int board[EDGE][EDGE]);
void	move_down(int board[EDGE][EDGE]);
void	move_left(int board[EDGE][EDGE]);
void	move_right(int board[EDGE][EDGE]);

#endif
