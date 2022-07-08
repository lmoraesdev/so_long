/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:13:29 by lbatista          #+#    #+#             */
/*   Updated: 2022/07/08 16:07:08 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	game_over(t_data *game)
{
	printf("GAME OVER!!!");
	game_exit_bonus(game);
}

static void	map_upper(t_data *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map_line)
	{
		y = 0;
		while (y < game->map_col)
		{
			if (game->map[x][y] == 'v')
			{
				game->map[x][y] = 'V';
			}
			y++;
		}
		x++;
	}
}

static void	patrol_decision(t_data *game)
{
	int	x;
	int	y;

	x = game->player_line - game->patrol_line;
	y = game->player_col - game->patrol_col;
	if (x < 0)
		x = x * -1;
	if (y < 0)
		y = y * -1;
	if (x < y)
		patrol_mov_x(game);
	else if (x > y)
		patrol_mov_y(game);
	else if (x == y)
		patrol_mov_xy(game);
}

static int	patrol_position(t_data *game, int speed)
{
	int	x;
	int	y;

	x = 0;
	if (speed == 200)
	{
		while (x < game->map_line)
		{
			y = 0;
			while (y < game->map_col)
			{
				if (game->map[x][y] == 'V')
				{
					game->patrol_line = x;
					game->patrol_col = y;
					patrol_decision(game);
				}
				y++;
			}
			x++;
		}
		speed = 0;
	}
	return (speed);
}

int	animation(t_data *game)
{
	static int	speed;

	speed++;
	speed = patrol_position(game, speed);
	map_upper(game);
	map_to_win_bonus(game);
	return (0);
}
