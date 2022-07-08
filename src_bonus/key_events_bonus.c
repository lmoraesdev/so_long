/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:15:59 by lbatista          #+#    #+#             */
/*   Updated: 2022/06/24 11:16:06 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	key_up(t_data *game)
{
	if (game->map[game->player_line - 1][game->player_col] != '1')
	{
		if (game->map[game->player_line - 1][game->player_col] == 'V')
			game_over(game);
		if (game->map[game->player_line - 1][game->player_col] == 'C')
			game->map_c_count--;
		if (game->map[game->player_line - 1][game->player_col] == 'E'
			&& game->map_c_count == 0)
		{
			printf("Game Finished!!");
			game_exit_bonus(game);
		}
		if (game->map[game->player_line - 1][game->player_col] != 'E'
			|| game->map_c_count == 0)
		{
			game->map[game->player_line][game->player_col] = '0';
			game->map[game->player_line - 1][game->player_col] = 'P';
			game->player_line = game->player_line - 1;
			game->moviments++;
			map_to_win_bonus(game);
		}
	}
}

static void	key_down(t_data *game)
{
	if (game->map[game->player_line + 1][game->player_col] != '1')
	{
		if (game->map[game->player_line + 1][game->player_col] == 'V')
			game_over(game);
		if (game->map[game->player_line + 1][game->player_col] == 'C')
			game->map_c_count--;
		if (game->map[game->player_line + 1][game->player_col] == 'E'
			&& game->map_c_count == 0)
		{
			printf("Game Finished!!");
			game_exit_bonus(game);
		}
		if (game->map[game->player_line + 1][game->player_col] != 'E'
			|| game->map_c_count == 0)
		{
			game->map[game->player_line][game->player_col] = '0';
			game->map[game->player_line + 1][game->player_col] = 'P';
			game->player_line = game->player_line + 1;
			game->moviments++;
			map_to_win_bonus(game);
		}
	}
}

static void	key_left(t_data *game)
{
	if (game->map[game->player_line][game->player_col - 1] != '1')
	{
		if (game->map[game->player_line][game->player_col - 1] == 'V')
			game_over(game);
		if (game->map[game->player_line][game->player_col - 1] == 'C')
			game->map_c_count--;
		if (game->map[game->player_line][game->player_col - 1] == 'E'
			&& game->map_c_count == 0)
		{
			printf("Game Finished!!");
			game_exit_bonus(game);
		}
		if (game->map[game->player_line][game->player_col - 1] != 'E'
			|| game->map_c_count == 0)
		{
			game->map[game->player_line][game->player_col] = '0';
			game->map[game->player_line][game->player_col - 1] = 'P';
			game->player_col = game->player_col - 1;
			game->moviments++;
			map_to_win_bonus(game);
		}
	}
}

static void	key_right(t_data *game)
{
	if (game->map[game->player_line][game->player_col + 1] != '1')
	{
		if (game->map[game->player_line][game->player_col + 1] == 'V')
			game_exit_bonus(game);
		if (game->map[game->player_line][game->player_col + 1] == 'C')
			game->map_c_count--;
		if (game->map[game->player_line][game->player_col + 1] != 'E'
			|| game->map_c_count == 0)
		{
			game->map[game->player_line][game->player_col] = '0';
			game->map[game->player_line][game->player_col + 1] = 'P';
			game->player_col = game->player_col + 1;
			game->moviments++;
			map_to_win_bonus(game);
		}
	}
}

int	key_events_bonus(int key, t_data *game)
{
	if (key == KEY_ESC)
		game_exit_bonus(game);
	else if (key == KEY_UP || key == KEY_W)
		key_up(game);
	else if (key == KEY_DOWN || key == KEY_S)
		key_down(game);
	else if (key == KEY_LEFT || key == KEY_A)
		key_left(game);
	else if (key == KEY_RIGHT || key == KEY_D)
		key_right(game);
	return (0);
}
