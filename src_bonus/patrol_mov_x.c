/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol_mov_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:18:25 by lbatista          #+#    #+#             */
/*   Updated: 2022/06/24 11:18:37 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	y_neg_free(t_data *game)
{
	if (game->map[game->patrol_line][game->patrol_col - 1] != '1'
		&& game->map[game->patrol_line][game->patrol_col - 1] != 'C'
		&& game->map[game->patrol_line][game->patrol_col - 1] != 'v'
		&& game->map[game->patrol_line][game->patrol_col - 1] != 'V'
		&& game->map[game->patrol_line][game->patrol_col - 1] != 'E')
	{
		if (game->map[game->patrol_line][game->patrol_col - 1] == 'P')
			game_over(game);
		game->map[game->patrol_line][game->patrol_col] = '0';
		game->map[game->patrol_line][game->patrol_col - 1] = 'v';
		return (0);
	}
	else if (game->map[game->patrol_line][game->patrol_col - 2] != '1'
		&& (game->map[game->patrol_line][game->patrol_col - 1] == 'C'
		|| game->map[game->patrol_line][game->patrol_col - 1] == 'E')
		&& (game->map[game->patrol_line][game->patrol_col - 2] == '0'
		|| game->map[game->patrol_line][game->patrol_col - 2] == 'P'))
	{
		if (game->map[game->patrol_line][game->patrol_col - 2] == 'P')
			game_over(game);
		game->map[game->patrol_line][game->patrol_col] = '0';
		game->map[game->patrol_line][game->patrol_col - 2] = 'v';
		return (0);
	}
	return (1);
}

static int	y_neg_wall(t_data *game)
{
	if (game->map[game->patrol_line][game->patrol_col - 1] == '1'
		&& game->map[game->patrol_line + 1][game->patrol_col] != 'E'
		&& (game->map[game->patrol_line + 1][game->patrol_col] == '0'
		|| game->map[game->patrol_line + 1][game->patrol_col] == 'P'))
	{
		if (game->map[game->patrol_line + 1][game->patrol_col] == 'P')
			game_over(game);
		game->map[game->patrol_line][game->patrol_col] = '0';
		game->map[game->patrol_line + 1][game->patrol_col] = 'v';
		return (0);
	}
	else if (game->map[game->patrol_line][game->patrol_col - 1] == '1'
		&& game->map[game->patrol_line - 1][game->patrol_col] != 'E'
		&& (game->map[game->patrol_line - 1][game->patrol_col] == '0'
		|| game->map[game->patrol_line - 1][game->patrol_col] == 'P'))
	{
		if (game->map[game->patrol_line - 1][game->patrol_col] == 'P')
			game_over(game);
		game->map[game->patrol_line][game->patrol_col] = '0';
		game->map[game->patrol_line - 1][game->patrol_col] = 'v';
		return (0);
	}
	return (1);
}

static int	y_pos_free(t_data *game)
{
	if (game->map[game->patrol_line][game->patrol_col + 1] != '1'
		&& game->map[game->patrol_line][game->patrol_col + 1] != 'C'
		&& game->map[game->patrol_line][game->patrol_col + 1] != 'v'
		&& game->map[game->patrol_line][game->patrol_col + 1] != 'V'
		&& game->map[game->patrol_line][game->patrol_col + 1] != 'E')
	{
		if (game->map[game->patrol_line][game->patrol_col + 1] == 'P')
			game_over(game);
		game->map[game->patrol_line][game->patrol_col] = '0';
		game->map[game->patrol_line][game->patrol_col + 1] = 'v';
		return (0);
	}
	else if (game->map[game->patrol_line][game->patrol_col + 1] != '1'
		&& (game->map[game->patrol_line][game->patrol_col + 1] == 'C'
		|| game->map[game->patrol_line][game->patrol_col + 1] == 'E')
		&& (game->map[game->patrol_line][game->patrol_col + 2] == '0'
		|| game->map[game->patrol_line][game->patrol_col + 2] == 'P'))
	{
		if (game->map[game->patrol_line][game->patrol_col + 2] == 'P')
			game_over(game);
		game->map[game->patrol_line][game->patrol_col] = '0';
		game->map[game->patrol_line][game->patrol_col + 2] = 'v';
		return (0);
	}
	return (1);
}

static int	y_pos_wall(t_data *game)
{
	if (game->map[game->patrol_line][game->patrol_col + 1] == '1'
		&& game->map[game->patrol_line + 1][game->patrol_col] != 'E'
		&& (game->map[game->patrol_line + 1][game->patrol_col] == '0'
		|| game->map[game->patrol_line + 1][game->patrol_col] == 'P'))
	{
		if (game->map[game->patrol_line + 1][game->patrol_col] == 'P')
			game_over(game);
		game->map[game->patrol_line][game->patrol_col] = '0';
		game->map[game->patrol_line + 1][game->patrol_col] = 'v';
		return (0);
	}
	else if (game->map[game->patrol_line][game->patrol_col + 1] == '1'
		&& game->map[game->patrol_line - 1][game->patrol_col] != 'E'
		&& (game->map[game->patrol_line - 1][game->patrol_col] == '0'
		|| game->map[game->patrol_line - 1][game->patrol_col] == 'P'))
	{
		if (game->map[game->patrol_line - 1][game->patrol_col] == 'P')
			game_over(game);
		game->map[game->patrol_line][game->patrol_col] = '0';
		game->map[game->patrol_line - 1][game->patrol_col] = 'v';
		return (0);
	}
	return (1);
}

void	patrol_mov_x(t_data *game)
{
	int	y;

	y = game->player_col - game->patrol_col;
	if (y < 0)
	{
		if (y_neg_free(game))
			y_neg_wall(game);
	}
	if (y > 0)
	{
		if (y_pos_free(game))
			y_pos_wall(game);
	}
}
