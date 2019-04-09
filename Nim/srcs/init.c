/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:21:55 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/09 11:25:45 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nim.h"

void	game_loop(t_note *note)
{
	char	player;
	int		pick;
	
	ft_putchar('\n');
	ft_putncharln('-', 12);
	ft_printf("Game starts!\n");
	ft_putncharln('-', 12);
	player = 'A';
	while (true)
	{
		game_status(note);
		ft_printf("Player %c's turn:\n", player);
		pick = player_pick(note, player);
		if (is_over(note))
			break ;
		player = (player == 'A') ? 'B' : 'A';
	}
	ft_putchar('\n');
	ft_putncharln('-', 10);
	ft_printf("Game over.\n");
	ft_putncharln('-', 10);
	game_status(note);
	ft_putncharln('-', 21);
	ft_printf("Since player %c picked\nthe last stone,\n", player);
	ft_printf("player %c won!\n", player);
	ft_putncharln('-', 21);
}

void	prepare_note(t_note *note)
{
	char	*buf;
	int		piles_no;
	int		stones_no;

	do
	{
		ft_printf("Number of pile(s): ");
		ft_nextline(0, &buf);
		piles_no = ft_atoi(buf);
		free(buf);
	} while (piles_no <= 0 || piles_no > 5);
	note->piles_no = piles_no;
	note->min_pick = 1;
	note->max_pick = 3;
	stones_no = 30;
	note->piles = ft_randintarr(1, stones_no / piles_no, piles_no);
	if (piles_no == 1)
	{
		do
		{
			ft_printf("Human/Computer mode for 'A' (h/c): ");
			note->a_mode = ft_getonechar();
		} while (note->a_mode != 'c' && note->a_mode != 'h');
		do
		{
			ft_printf("Human/Computer node for 'B' (h/c): ");
			note->b_mode = ft_getonechar();
		} while (note->b_mode != 'c' && note->b_mode != 'h');
	}
	else
	{
		note->a_mode = 'h';
		note->b_mode = 'h';
	}
}
	
int		main(void)
{
	t_note	note;

	prepare_note(&note);
	game_loop(&note);
	return (0);
}
