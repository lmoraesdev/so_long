/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:16:04 by lbatista          #+#    #+#             */
/*   Updated: 2022/06/28 23:48:16 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * It sets up the images for the game
 *
 * @param game the data structure that holds all the information about the game
 */
void	img_setup(t_data *game)
{
	game->img_width = 50;
	game->img_height = 50;
	game->img_free_space = mlx_xpm_file_to_image(game->mlx_ptr,
			FREE_SPACE, &game->img_width, &game->img_height);
	game->img_collectable = mlx_xpm_file_to_image(game->mlx_ptr,
			COLLECTABLE, &game->img_width, &game->img_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx_ptr,
			WALL, &game->img_width, &game->img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr,
			EXIT, &game->img_width, &game->img_height);
	game->img_player = mlx_xpm_file_to_image(game->mlx_ptr,
			PLAYER, &game->img_width, &game->img_height);
}
