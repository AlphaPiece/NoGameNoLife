/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 07:10:17 by Zexi Wang         #+#    #+#             */
/*   Updated: 2020/01/22 08:26:16 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "life.h"

void swap_state(int **state1, int **state2)
{
	int	*tmp;

	tmp = *state1;
	*state1 = *state2;
	*state2 = tmp;
}

int main(int argc, char **argv)
{
	FILE	*fptr;
	int		rows, cols, state_num;
	int		*curr_state, *next_state;
	int		i, n;

	if (argc == 4)
		fptr = stdin;
	else if (argc == 5)
		fptr = fopen(argv[4], "r");
	else
	{
		fprintf(stderr, "usage: life2D rows cols states [seed_file]\n");
		return (1);
	}
	rows = strtol(argv[1], NULL, 10);
	cols = strtol(argv[2], NULL, 10);
	state_num = strtol(argv[3], NULL, 10);
	curr_state = malloc(sizeof(int) * rows * cols);
	next_state = malloc(sizeof(int) * rows * cols);
	for (i = 0; fscanf(fptr, "%d", &n) == 1; i++)
		curr_state[i] = next_state[i] = n;
	print_state(curr_state, rows, cols, state_num);
	for (int i = 0; i < state_num - 1; i++)
	{
		update_state(curr_state, next_state, rows, cols);
		swap_state(&curr_state, &next_state);
		print_state(curr_state, rows, cols, state_num);
	}
	if (argc == 5)
		fclose(fptr);
	return (0);
}
