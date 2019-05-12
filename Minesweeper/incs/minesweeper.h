/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minesweeper.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:38:39 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/09 19:28:47 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINESWEEPER_H
# define MINESWEEPER_H

# include "libft.h"

# define EDGE_0		9
# define MINES_0	10
# define EDGE_1		16
# define MINES_1	40
# define EDGE_2		25
# define MINES_2	100
# define UNKNOWN	'.'

typedef struct	s_info
{
	char		**board;
	int			edge;
	int			*mines_r;
	int			*mines_c;
	int			mines_no;
	t_bool		is_dead;
}				t_info;

t_bool			is_clear(t_info *info);
void			clear_mines(t_info *info);
void			game_status(t_info *info);
t_bool			is_valid_place(t_info *info, int r, int c);
void			pick_place(t_info *info);

t_bool			is_mine(t_info *info, int r, int c);
void			explode_all_mines(t_info *info);
void			explore_area(t_info *info, int r, int c);

#endif
