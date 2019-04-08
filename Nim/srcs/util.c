/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:51:28 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/08 17:12:40 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nim.h"

t_bool	is_over(t_note *note)
{
	int	i;
	int	sum;
	
	for (sum = i = 0; i < note->piles_no; i++)
		sum += note->piles[i];
	return (sum == 1);
}

void	game_status(t_note *note)
{
	int	i;

	ft_putchar('\n');
	ft_putncharln('=', 18);
	for (i = 0; i < note->piles_no; i++)
		ft_printf("pile %d: %d stone(s)\n", i + 1, note->piles[i]);
	ft_printf("\nmin pick: %d\nmax pick: %d\n", note->min_pick, note->max_pick);
	ft_putncharln('=', 18);
	ft_putchar('\n');
}

int		player_pick(t_note *note)
{
	int		pile;
	int		stone;
	char	*buf;

	do
	{
		ft_printf("pile: ");
		ft_nextline(0, &buf);
		pile = ft_atoi(buf);
		free(buf);
	} while (pile < 1 || pile > note->piles_no || note->piles[pile - 1] == 0);
	do
	{
		ft_printf("stone: ");
		ft_nextline(0, &buf);
		stone = ft_atoi(buf);
		free(buf);
	} while (stone < note->min_pick ||
				stone > ft_min(2, note->max_pick, note->piles[pile - 1]));
	note->piles[pile - 1] -= stone;
	return (stone);
}
