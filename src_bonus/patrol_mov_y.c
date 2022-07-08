/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol_mov_y.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:19:51 by lbatista          #+#    #+#             */
/*   Updated: 2022/06/24 11:20:02 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	x_neg_free(t_data *game)
{
	if (game->map[game->patrol_line - 1][game->patrol_col] != '1'
		&& game->map[game->patrol_line - 1][game->patrol_col] != 'C'
		&& game->map[game->patrol_line - 1][game->patrol_col] != 'v'
		&& game->map[game->patrol_line - 1][game->patrol_col] != 'V'
		&& game->map[game->patrol_line - 1][game->patrol_col] != 'E')
	{
		if (game->map[game->patrol_line - 1][game->patrol_col] == 'P')
			game_over(game);
		game->map[game->patrol_line][game->patrol_col] = '0';
		game->map[game->patrol_line - 1][game->patrol_col] = 'v';
		return (0);
	}
	else if (game->map[game->patrol_line - 2][game->patrol_col] != '1'
		&& (game->map[game->patrol_line - 1][game->patrol_col] == 'C'
		|| game->map[game->patrol_line - 1][game->patrol_col] == 'E')
		&& (game->map[game->patrol_line - 2][game->patrol_col] == '0'
		|| game->map[game->patrol_line - 2][game->patrol_col] == 'P'))
	{
		if (game->map[game->patrol_line - 2][game->patrol_col] == 'P')
			game_over(game);
		game->map[game->patrol_line][game->patrol_col] = '0';
		game->map[game->patrol_line - 2][game->patrol_col] = 'v';
		return (0);
	}
	return (1);
}

static int	x_neg_wall(t_data *game)
{
	if (game->map[game->patrol_line - 1][game->patrol_col] == '1'
		&& game->map[game->patrol_line][game->patrol_col + 1] != 'E'
		&& (game->map[game->patrol_line][game->patrol_col + 1] == '0'
		|| game->map[game->patrol_line][game->patrol_col + 1] == 'P'))
	{
		if (game->map[game->patrol_line][game->patrol_col + 1] == 'P')
			game_over(game);
		game->map[game->patrol_line][game->patrol_col] = '0';
		game->map[game->patrol_line][game->patrol_col + 1] = 'v';
		return (0);
	}
	else if (game->map[game->patrol_line - 1][game->patrol_col] == '1'
		&& game->map[game->patrol_line][game->patrol_col - 1] != 'E'
		&& (game->map[game->patrol_line][game->patrol_col - 1] == '0'
		|| game->map[game->patrol_line][game->patrol_col - 1] == 'P'))
	{
		if (game->map[game->patrol_line][game->patrol_col - 1] == 'P')
			game_over(game);
		game->map[game->patrol_line][game->patrol_col] = '0';
		game->map[game->patrol_line][game->patrol_col - 1] = 'v';
		return (0);
	}
	return (1);
}

static int	x_pos_free(t_data *game)
{
	if (game->map[game->patrol_line + 1][game->patrol_col] != '1'
		&& game->map[game->patrol_line + 1][game->patrol_col] != 'C'
		&& game->map[game->patrol_line + 1][game->patrol_col] != 'v'
		&& game->map[game->patrol_line + 1][game->patrol_col] != 'V'
		&& game->map[game->patrol_line + 1][game->patrol_col] != 'E')
	{
		if (game->map[game->patrol_line + 1][game->patrol_col] == 'P')
			game_over(game);
		game->map[game->patrol_line][game->patrol_col] = '0';
		game->map[game->patrol_line + 1][game->patrol_col] = 'v';
		return (0);
	}
	else if (game->map[game->patrol_line + 2][game->patrol_col] != '1'
		&& (game->map[game->patrol_line + 1][game->patrol_col] == 'C'
		|| game->map[game->patrol_line + 1][game->patrol_col] == 'E')
		&& (game->map[game->patrol_line + 2][game->patrol_col] == '0'
		|| game->map[game->patrol_line + 2][game->patrol_col] == 'P'))
	{
		if (game->map[game->patrol_line + 2][game->patrol_col] == 'P')
			game_over(game);
		game->map[game->patrol_line][game->patrol_col] = '0';
		game->map[game->patrol_line + 2][game->patrol_col] = 'v';
		return (0);
	}
	return (1);
}

static int	x_pos_wall(t_data *game)
{
	if (game->map[game->patrol_line + 1][game->patrol_col] == '1'
		&& game->map[game->patrol_line][game->patrol_col + 1] != 'E'
		&& (game->map[game->patrol_line][game->patrol_col + 1] == '0'
		|| game->map[game->patrol_line][game->patrol_col + 1] == 'P'))
	{
		if (game->map[game->patrol_line][game->patrol_col + 1] == 'P')
			game_over(game);
		game->map[game->patrol_line][game->patrol_col] = '0';
		game->map[game->patrol_line][game->patrol_col + 1] = 'v';
		return (0);
	}
	else if (game->map[game->patrol_line + 1][game->patrol_col] == '1'
		&& game->map[game->patrol_line][game->patrol_col - 1] != 'E'
		&& (game->map[game->patrol_line][game->patrol_col - 1] == '0'
		|| game->map[game->patrol_line][game->patrol_col - 1] == 'P'))
	{
		if (game->map[game->patrol_line][game->patrol_col - 1] == 'P')
			game_over(game);
		game->map[game->patrol_line][game->patrol_col] = '0';
		game->map[game->patrol_line][game->patrol_col - 1] = 'v';
		return (0);
	}
	return (1);
}

void	patrol_mov_y(t_data *game)
{
	int	x;

	x = game->player_line - game->patrol_line;
	if (x < 0)
	{
		if (x_neg_free(game))
			x_neg_wall(game);
	}
	if (x > 0)
	{
		if (x_pos_free(game))
			x_pos_wall(game);
	}
}
