/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tic_tac_toe.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 22:16:57 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/07 23:32:39 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIC_TAC_TOE_H
# define TIC_TAC_TOE_H

# include "libft.h"

# define EDGE	3

t_bool	is_full(char board[EDGE][EDGE]);
void	board_status(char board[EDGE][EDGE]);
void	next_place(char board[EDGE][EDGE], char player);
t_bool	player_won(char board[EDGE][EDGE], char player);

#endif
