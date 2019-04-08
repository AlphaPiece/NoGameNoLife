/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nim.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:25:58 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/08 17:09:36 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIM_H
# define NIM_H

# include "libft.h"

typedef struct	s_note
{
	int			*piles;
	int			piles_no;
	int			min_pick;
	int			max_pick;
}				t_note;

t_bool			is_over(t_note *note);
void			game_status(t_note *note);
int				player_pick(t_note *note);

#endif
