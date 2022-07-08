/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:14:00 by lbatista          #+#    #+#             */
/*   Updated: 2022/06/24 11:14:09 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	destroy_img(t_data *game)
{
	mlx_destroy_image(game->mlx_ptr, game->img_free_space);
	mlx_destroy_image(game->mlx_ptr, game->img_wall);
	mlx_destroy_image(game->mlx_ptr, game->img_collectable);
	mlx_destroy_image(game->mlx_ptr, game->img_collectable_2);
	mlx_destroy_image(game->mlx_ptr, game->img_exit);
	mlx_destroy_image(game->mlx_ptr, game->img_player);
	mlx_destroy_image(game->mlx_ptr, game->img_patrol);
	mlx_destroy_image(game->mlx_ptr, game->score_s);
	mlx_destroy_image(game->mlx_ptr, game->score_c);
	mlx_destroy_image(game->mlx_ptr, game->score_o);
	mlx_destroy_image(game->mlx_ptr, game->score_r);
	mlx_destroy_image(game->mlx_ptr, game->score_e);
	mlx_destroy_image(game->mlx_ptr, game->score_0);
	mlx_destroy_image(game->mlx_ptr, game->score_1);
	mlx_destroy_image(game->mlx_ptr, game->score_2);
	mlx_destroy_image(game->mlx_ptr, game->score_3);
	mlx_destroy_image(game->mlx_ptr, game->score_4);
	mlx_destroy_image(game->mlx_ptr, game->score_5);
	mlx_destroy_image(game->mlx_ptr, game->score_6);
	mlx_destroy_image(game->mlx_ptr, game->score_7);
	mlx_destroy_image(game->mlx_ptr, game->score_8);
	mlx_destroy_image(game->mlx_ptr, game->score_9);
}

void	ft_clear_split(char **ptr)
{
	int	i;

	if (ptr != NULL)
	{
		i = -1;
		while (ptr[++i])
			free(ptr[i]);
	}
	free(ptr);
}

int	game_exit_bonus(t_data *game)
{
	destroy_img(game);
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	ft_clear_split(game->map);
	exit(0);
}
