/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 07:23:53 by Zexi Wang         #+#    #+#             */
/*   Updated: 2020/01/22 08:12:36 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFE_H
# define LIFE_H

void update_state(int *curr_state, int *next_state, int rows, int cols);
void print_state(int *state, int rows, int cols, int state_num);

#endif
