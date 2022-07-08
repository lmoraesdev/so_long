/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_anime.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:15:00 by lbatista          #+#    #+#             */
/*   Updated: 2022/06/24 11:15:10 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//Called by map_to_win function when put 'C' image.
void	img_anime(t_data *game, int x, int y)
{
	static int	flag;
	static int	i;

	i++;
	if (i > 30)
	{
		if (flag == 0)
		{
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->img_collectable, y * game->img_width,
				x * game->img_height);
			flag = 1;
		}
		else if (flag == 1)
		{
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->img_collectable_2, y * game->img_width,
				x * game->img_height);
			flag = 0;
		}
		i = 0;
	}
}
