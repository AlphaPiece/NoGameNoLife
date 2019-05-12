/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:20:06 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/11 20:45:40 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.h"

int		eval_line_score(char board[EDGE][EDGE], char player, char line[10])
{
	if (player == 'X')
	{
		if (ft_strstr(line, "XXXXX"))
			return (50000);
		if (ft_strstr(line, ".XXXX."))
			return (4320);
		if (ft_strstr(line, ".XXX..") || ft_strstr(line, "..XXX.") ||
				ft_strstr(line, ".XX.X.") || ft_strstr(line, ".X.XX.") ||
				ft_strstr(line, "XXXX.") || ft_strstr(line, ".XXXX") ||
				ft_strstr(line, "XX.XX") || ft_strstr(line, "X.XXX") ||
				ft_strstr(line, "XXX.X"))
			return (720);
		if (ft_strstr(line, "..XX..") || ft_strstr(line, "..X.X.") ||
					ft_strstr(line, ".X.X.."))
			return (120);
		if (ft_strstr(line, "...X..") || ft_strstr(line, "..X..."))
			return (20);
	}
	else
	{
		if (ft_strstr(line, "OOOOO"))
			return (50000);
		if (ft_strstr(line, ".OOOO."))
			return (4320);
		if (ft_strstr(line, ".OOO..") || ft_strstr(line, "..OOO.") ||
				ft_strstr(line, ".OO.O.") || ft_strstr(line, ".O.OO.") ||
				ft_strstr(line, "OOOO.") || ft_strstr(line, ".OOOO") ||
				ft_strstr(line, "OO.OO") || ft_strstr(line, "O.OOO") ||
				ft_strstr(line, "OOO.O"))
			return (720);
		if (ft_strstr(line, "..OO..") || ft_strstr(line, "..O.O.") ||
					ft_strstr(line, ".O.O.."))
			return (120);
		if (ft_strstr(line, "...O..") || ft_strstr(line, "..O..."))
			return (20);
	}
	return (0);
}

int		eval_place_score(char board[EDGE][EDGE], int r, int c, char player)
{
	char	line[10];
	int		scores[4];

	get_ns_form(board, r, c, player, line);
	scores[0] = eval_line_score(board, player, line);
	get_we_form(board, r, c, player, line);
	scores[1] = eval_line_score(board, player, line);
	get_nwse_form(board, r, c, player, line);
	scores[2] = eval_line_score(board, player, line);
	get_nesw_form(board, r, c, player, line);
	scores[3] = eval_line_score(board, player, line);
	return (ft_intarrsum(scores, 4));
}
