/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 13:39:28 by zwang             #+#    #+#             */
/*   Updated: 2018/08/07 15:00:24 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef	struct		s_tetro
{
	t_point			points[4];
}					t_tetro;

typedef struct		s_board
{
	t_tetro			**tetro_list;
	char			**board_state;
	int				sq_len;
	int				tetro_amt;
}					t_board;

char				*get_whole_string(char *file_name, char *whole_string);
int					basic_validate(char *whole_string);
char				**get_tetro_strings(char *whole_string,
										char **tetro_strings, int tetro_amt);

int					advanced_validate(char **tetro_strings);
t_tetro				*get_tetro_struct(char *tetro_string);
t_tetro				**get_tetro_list(char **tetro_strings, int tetro_amt);

t_tetro				**get_tetro_list(char **tetro_strings, int tetro_cnt);
t_board				*create_board(t_tetro **tetro_list, int tetro_amt);
void				delete_board_state(t_board *board);
int					increment_board_state(t_board *board);
int					is_safe(t_board *board, t_tetro *tetro_struct, t_point pos);

int					backtrack_map(t_board *board, int tetro_index);
t_board				*fill_square(char **tetro_strings, int tetro_amt);
void				free_all_data(t_board *board);

#endif
