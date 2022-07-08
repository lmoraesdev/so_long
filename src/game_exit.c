/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:11:17 by lbatista          #+#    #+#             */
/*   Updated: 2022/07/08 16:04:30 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * This function frees a 2D array of strings
 *
 * @param ptr The pointer to the array of strings.
 */
void	ft_clear_split(char **ptr)
{
	int	i;

	if (ptr != NULL)
	{
		i = -1;
		while (ptr[++i])
			free(ptr[i]);
		free(ptr);
	}
}

/**
 * It destroys all the images, the window, the display, and the mlx_ptr, and then
 * frees the mlx_ptr and the map
 *
 * @param game the data structure that holds all the information about the game
 */
int	game_exit(t_data *game)
{
	mlx_destroy_image(game->mlx_ptr, game->img_free_space);
	mlx_destroy_image(game->mlx_ptr, game->img_wall);
	mlx_destroy_image(game->mlx_ptr, game->img_collectable);
	mlx_destroy_image(game->mlx_ptr, game->img_exit);
	mlx_destroy_image(game->mlx_ptr, game->img_player);
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	ft_clear_split(game->map);
	exit(0);
}
