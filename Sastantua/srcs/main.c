/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 10:12:08 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/10 10:13:22 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	sastantua(int size);

int		main(int argc, char **argv)
{
	if (argc == 2)
		sastantua(ft_atoi(argv[1]));
	return (0);
}
