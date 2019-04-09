/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 23:31:10 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/09 11:16:47 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nim.h"

int	human_mode(t_note *note)
{
	int		pile;
	int		stone;
	char	*buf;

	if (note->piles_no > 1)
		do
		{
			ft_printf("Pile: ");
			ft_nextline(0, &buf);
			pile = ft_atoi(buf);
			free(buf);
		} while (pile < 1 || pile > note->piles_no ||
					note->piles[pile - 1] == 0);
	else
		pile = 1;
	do
	{
		ft_printf("Stone(s): ");
		ft_nextline(0, &buf);
		stone = ft_atoi(buf);
		free(buf);
	} while (stone < note->min_pick ||
				stone > ft_min(2, note->max_pick, note->piles[pile - 1]));
	note->piles[pile - 1] -= stone;
	return (stone);
}

int	computer_mode_single_pile(t_note *note)
{
	int	stones_no;
	int	gap;
	int	i;
	int	pick;

	stones_no = note->piles[0];
	gap = note->max_pick + 1;
	pick = 1;
	for (i = 1; i <= note->max_pick; i++)
		if ((stones_no - i) % gap == 0)
			pick = i;
	note->piles[0] -= pick;
	ft_printf("Stone(s): %d\n", pick);
	return (pick);
}
