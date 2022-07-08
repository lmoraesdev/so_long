/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:18:44 by lbatista          #+#    #+#             */
/*   Updated: 2022/06/28 23:50:53 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * It draws the map
 *
 * @param game the data structure that holds all the information about the game
 * @param x the x coordinate of the map
 */
void	draw_map(t_data *game, int x)
{
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		if (game->map[y][x] == '1')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->img_wall, x * game->img_width, y * game->img_height);
		if (game->map[y][x] == '0')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->img_free_space,
				x * game->img_width, y * game->img_height);
		if (game->map[y][x] == 'C')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->img_collectable,
				x * game->img_width, y * game->img_height);
		if (game->map[y][x] == 'P')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->img_player, x * game->img_width, y * game->img_height);
		if (game->map[y][x] == 'E')
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->img_exit, x * game->img_width, y * game->img_height);
		y++;
	}
}

/**
 * It takes the map and draws it to the window
 *
 * @param game the data structure that holds all the information about the game
 *
 * @return 0.
 */
int	map_to_win(t_data *game)
{
	int	x;

	x = 0;
	while (x < game->map_width)
	{
		draw_map(game, x);
		x++;
	}
	return (0);
}
