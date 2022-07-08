/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:15:32 by lbatista          #+#    #+#             */
/*   Updated: 2022/06/28 23:47:55 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * It sets the player's position on the map
 *
 * @param game The game data structure.
 */
void	game_setup(t_data *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map_width)
	{
		y = 0;
		while (y < game->map_height)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				break ;
			}
			y++;
		}
		x++;
	}
	game->moviments = 0;
}
