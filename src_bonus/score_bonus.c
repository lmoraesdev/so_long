/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:20:08 by lbatista          #+#    #+#             */
/*   Updated: 2022/06/24 11:20:19 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	score_print_more(t_data *game, int n, int col)
{
	if (n == 5)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->score_5, col * game->img_width, 0 * game->img_height);
	else if (n == 6)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->score_6, col * game->img_width, 0 * game->img_height);
	else if (n == 7)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->score_7, col * game->img_width, 0 * game->img_height);
	else if (n == 8)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->score_8, col * game->img_width, 0 * game->img_height);
	else if (n == 9)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->score_9, col * game->img_width, 0 * game->img_height);
}

static void	score_print(t_data *game, int n, int col)
{
	if (n == 0)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->score_0, col * game->img_width, 0 * game->img_height);
	else if (n == 1)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->score_1, col * game->img_width, 0 * game->img_height);
	else if (n == 2)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->score_2, col * game->img_width, 0 * game->img_height);
	else if (n == 3)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->score_3, col * game->img_width, 0 * game->img_height);
	else if (n == 4)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->score_4, col * game->img_width, 0 * game->img_height);
	score_print_more(game, n, col);
}

static void	score_start(t_data *game)
{
	int	col;

	col = 9;
	while (col > 5)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->score_0, col * game->img_width, 0 * game->img_height);
		col--;
	}
}

void	score_bonus(t_data *game)
{
	int	n;
	int	dec;
	int	col;

	col = 9;
	if (game->moviments != 0)
	{
		n = game->moviments % 10;
		score_print(game, n, col);
		dec = game->moviments / 10;
		while (dec > 0)
		{
			col--;
			n = dec % 10;
			score_print(game, n, col);
			dec = dec / 10;
		}
	}
	else
		score_start(game);
}
