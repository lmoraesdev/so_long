/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_setup_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:15:36 by lbatista          #+#    #+#             */
/*   Updated: 2022/06/24 11:15:48 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	img_score_num(t_data *game)
{
	game->score_0 = mlx_xpm_file_to_image(game->mlx_ptr,
			SCORE_0, &game->img_width, &game->img_height);
	game->score_1 = mlx_xpm_file_to_image(game->mlx_ptr,
			SCORE_1, &game->img_width, &game->img_height);
	game->score_2 = mlx_xpm_file_to_image(game->mlx_ptr,
			SCORE_2, &game->img_width, &game->img_height);
	game->score_3 = mlx_xpm_file_to_image(game->mlx_ptr,
			SCORE_3, &game->img_width, &game->img_height);
	game->score_4 = mlx_xpm_file_to_image(game->mlx_ptr,
			SCORE_4, &game->img_width, &game->img_height);
	game->score_5 = mlx_xpm_file_to_image(game->mlx_ptr,
			SCORE_5, &game->img_width, &game->img_height);
	game->score_6 = mlx_xpm_file_to_image(game->mlx_ptr,
			SCORE_6, &game->img_width, &game->img_height);
	game->score_7 = mlx_xpm_file_to_image(game->mlx_ptr,
			SCORE_7, &game->img_width, &game->img_height);
	game->score_8 = mlx_xpm_file_to_image(game->mlx_ptr,
			SCORE_8, &game->img_width, &game->img_height);
	game->score_9 = mlx_xpm_file_to_image(game->mlx_ptr,
			SCORE_9, &game->img_width, &game->img_height);
}

static void	img_score(t_data *game)
{
	game->score_s = mlx_xpm_file_to_image(game->mlx_ptr,
			SCORE_S, &game->img_width, &game->img_height);
	game->score_c = mlx_xpm_file_to_image(game->mlx_ptr,
			SCORE_C, &game->img_width, &game->img_height);
	game->score_o = mlx_xpm_file_to_image(game->mlx_ptr,
			SCORE_O, &game->img_width, &game->img_height);
	game->score_r = mlx_xpm_file_to_image(game->mlx_ptr,
			SCORE_R, &game->img_width, &game->img_height);
	game->score_e = mlx_xpm_file_to_image(game->mlx_ptr,
			SCORE_E, &game->img_width, &game->img_height);
	img_score_num(game);
}

void	img_setup_bonus(t_data *game)
{
	img_score(game);
	game->img_width = 50;
	game->img_height = 50;
	game->img_free_space = mlx_xpm_file_to_image(game->mlx_ptr,
			FREE_SPACE, &game->img_width, &game->img_height);
	game->img_collectable = mlx_xpm_file_to_image(game->mlx_ptr,
			COLLECTABLE, &game->img_width, &game->img_height);
	game->img_collectable_2 = mlx_xpm_file_to_image(game->mlx_ptr,
			COLLECTABLE_2, &game->img_width, &game->img_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx_ptr,
			WALL, &game->img_width, &game->img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr,
			EXIT, &game->img_width, &game->img_height);
	game->img_player = mlx_xpm_file_to_image(game->mlx_ptr,
			PLAYER, &game->img_width, &game->img_height);
	game->img_patrol = mlx_xpm_file_to_image(game->mlx_ptr,
			PATROL, &game->img_width, &game->img_height);
}
