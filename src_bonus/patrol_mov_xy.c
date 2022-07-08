/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol_mov_xy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:19:29 by lbatista          #+#    #+#             */
/*   Updated: 2022/06/24 11:19:41 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	xy_neg_free(t_data *game)
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

static int	xy_neg_wall(t_data *game)
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

static int	xy_pos_free(t_data *game)
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
	else if (game->map[game->patrol_line][game->patrol_col + 2] != '1'
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

static int	xy_pos_wall(t_data *game)
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

void	patrol_mov_xy(t_data *game)
{
	static int	flag;

	if (flag == 0)
	{
		if (xy_neg_free(game))
			xy_neg_wall(game);
		flag = 1;
	}
	else if (flag == 1)
	{
		if (xy_pos_free(game))
			xy_pos_wall(game);
		flag = 0;
	}
}
