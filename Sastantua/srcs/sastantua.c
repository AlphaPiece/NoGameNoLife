/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:25:13 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/10 10:16:45 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define INIT_LAYER	3

int		get_layer_stars(int level, int layer)
{
	int	stars;
	int	i, j;

	stars = 1;
	for (i = 0; i <= level; i++)
	{
		if (i < level)
		{
			for (j = 0; j < INIT_LAYER + i - 1; j++)
				stars += 2;
			stars += (INIT_LAYER + i / 2) * 2;
		}
		else
			for (j = 0; j < layer; j++)
				stars += 2;
	}
	return (stars);
}
	
void	print_level(int size, int level, int bottom_len)
{
	int	layer;
	int	spaces, stars;
	int	door_len;

	door_len = 1 + (level / 2) * 2;
	for (layer = 0; layer < INIT_LAYER + level; layer++)
	{
		stars = get_layer_stars(level, layer);
		spaces = (bottom_len - stars - 2) / 2;
		ft_putnchar(' ', spaces - 1);
		ft_putchar('/');
		if (level == size - 1 && layer >= INIT_LAYER + level - door_len)
		{
			ft_putnchar('*', (stars - door_len) / 2);
			if (door_len > 3 && 
					layer == INIT_LAYER + level - door_len / 2 - 1)
			{
				ft_putnchar('|', door_len - 2);
				ft_putchar('$');
				ft_putchar('|');
			}
			else
				ft_putnchar('|', door_len);
			ft_putnchar('*', (stars - door_len) / 2);
			ft_putchar('\\');
			ft_putchar('\n');
		}
		else
		{
			ft_putnchar('*', stars);
			ft_putchar('\\');
			ft_putchar('\n');
		}
	}
}

void	sastantua(int size)
{
	int	level;
	int	bottom_len;
	
	bottom_len = get_layer_stars(size - 1, INIT_LAYER + size - 1) + 2;
	for (level = 0; level < size; level++)
		print_level(size, level, bottom_len);
}
