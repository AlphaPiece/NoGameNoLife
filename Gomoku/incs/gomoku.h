/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gomoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:33:26 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/11 20:44:49 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GOMOKU_H
# define GOMOKU_H

# include "libft.h"

# define PL		5
# define EDGE	15
# define EMPTY	'.'

int	nw_pieces(char board[EDGE][EDGE], int r, int c, char player);
int	ne_pieces(char board[EDGE][EDGE], int r, int c, char player);
int sw_pieces(char board[EDGE][EDGE], int r, int c, char player);
int se_pieces(char board[EDGE][EDGE], int r, int c, char player);

void	get_ns_form(char board[EDGE][EDGE], int r, int c, char player,
					char ns_form[10]);
void	get_we_form(char board[EDGE][EDGE], int r, int c, char player,
					char we_form[10]);
void	get_nwse_form(char board[EDGE][EDGE], int r, int c, char player,
						char nwse_form[10]);
void	get_nesw_form(char board[EDGE][EDGE], int r, int c, char player,
						char nesw_form[10]);

int     eval_line_score(char board[EDGE][EDGE], char player, char line[10]);
int     eval_place_score(char board[EDGE][EDGE], int r, int c, char player);

t_bool	is_over(char board[EDGE][EDGE]);
void	game_status(char board[EDGE][EDGE]);
t_bool	is_empty_place(char board[EDGE][EDGE], int r, int c);
void	player_move(char board[EDGE][EDGE], char player, char player_mode);

void	human_mode(char board[EDGE][EDGE], char player);
void	computer_mode(char board[EDGE][EDGE], char player);

#endif
