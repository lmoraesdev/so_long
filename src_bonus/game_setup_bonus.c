/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:14:24 by lbatista          #+#    #+#             */
/*   Updated: 2022/06/24 11:14:34 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	game_setup_bonus(t_data *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map_line)
	{
		y = 0;
		while (y < game->map_col)
		{
			if (game->map[x][y] == 'P')
			{
				game->player_line = x;
				game->player_col = y;
				break ;
			}
			y++;
		}
		x++;
	}
	game->moviments = 0;
}
