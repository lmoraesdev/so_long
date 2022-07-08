/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:16:44 by lbatista          #+#    #+#             */
/*   Updated: 2022/07/08 16:03:03 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * It checks if the player can move up, if it can, it
 * checks if the player is on a
 * box, if it is, it checks if the box is on a destination,
 * if it is, it checks if
 * all the boxes are on the destinations, if they are, it prints a message and
 * exits the game, if not, it checks if the player is
 * on a destination, if it is,
 * it moves the player up, if not, it moves the player up
 *
 * @param game the game data structure
 */
static void	key_up(t_data *game)
{
	if (game->map[game->player_y - 1][game->player_x] != '1')
	{
		if (game->map[game->player_y - 1][game->player_x] == 'C')
			game->map_c_count--;
		if (game->map[game->player_y - 1][game->player_x] == 'E'
			&& game->map_c_count == 0)
		{
			printf("Game Finished!!");
			game_exit(game);
		}
		if (game->map[game->player_y - 1][game->player_x] != 'E'
			|| game->map_c_count == 0)
		{
			game->map[game->player_y][game->player_x] = '0';
			game->map[game->player_y - 1][game->player_x] = 'P';
			map_to_win(game);
			game->player_y = game->player_y - 1;
			game->moviments++;
			printf("Movements: %d\n", game->moviments);
		}
	}
}

/**
 * It checks if the player is not trying to
 * move into a wall, if the player is not
 * trying to move into a wall, it checks if the player is trying to move into a
 * box, if the player is trying to move into a box, it checks if the player has
 * moved all the boxes to the goal, if the player has moved all the boxes to the
 * goal, it prints "Game Finished!!" and exits the game, if the player has not
 * moved all the boxes to the goal,
 * it checks if the player is trying to move into
 * the goal, if the player is trying to move into the goal,
 * it checks if the player
 * has moved all the boxes to the goal, if the player has moved all the boxes to
 * the goal, it prints "Game Finished!!" and exits the game,
 * if the player has not
 * moved all the boxes to the goal,
 * it sets the current player position to 0, sets
 * the new player position to P, updates the window, sets the
 *
 * @param game the game data structure
 */
static void	key_down(t_data *game)
{
	if (game->map[game->player_y + 1][game->player_x] != '1')
	{
		if (game->map[game->player_y + 1][game->player_x] == 'C')
			game->map_c_count--;
		if (game->map[game->player_y + 1][game->player_x] == 'E'
			&& game->map_c_count == 0)
		{
			printf("Game Finished!!");
			game_exit(game);
		}
		if (game->map[game->player_y + 1][game->player_x] != 'E'
			|| game->map_c_count == 0)
		{
			game->map[game->player_y][game->player_x] = '0';
			game->map[game->player_y + 1][game->player_x] = 'P';
			map_to_win(game);
			game->player_y = game->player_y + 1;
			game->moviments++;
			printf("Movements: %d\n", game->moviments);
		}
	}
}

/**
 * It checks if the player can move left, if it can, it moves the player and
 * updates the map
 *
 * @param game the game data structure
 */
static void	key_left(t_data *game)
{
	if (game->map[game->player_y][game->player_x - 1] != '1')
	{
		if (game->map[game->player_y][game->player_x - 1] == 'C')
			game->map_c_count--;
		if (game->map[game->player_y][game->player_x - 1] == 'E'
			&& game->map_c_count == 0)
		{
			printf("Game Finished!!");
			game_exit(game);
		}
		if (game->map[game->player_y][game->player_x - 1] != 'E'
			|| game->map_c_count == 0)
		{
			game->map[game->player_y][game->player_x] = '0';
			game->map[game->player_y][game->player_x - 1] = 'P';
			map_to_win(game);
			game->player_x = game->player_x - 1;
			game->moviments++;
			printf("Movements: %d\n", game->moviments);
		}
	}
}

/**
 * It checks if the player can move to the right,
 * if it can, it moves the player to
 * the right
 *
 * @param game the game data structure
 */
static void	key_right(t_data *game)
{
	if (game->map[game->player_y][game->player_x + 1] != '1')
	{
		if (game->map[game->player_y][game->player_x + 1] == 'C')
			game->map_c_count--;
		if (game->map[game->player_y][game->player_x + 1] == 'E'
			&& game->map_c_count == 0)
		{
			printf("Game Finished!!");
			game_exit(game);
		}
		if (game->map[game->player_y][game->player_x + 1] != 'E'
			|| game->map_c_count == 0)
		{
			game->map[game->player_y][game->player_x] = '0';
			game->map[game->player_y][game->player_x + 1] = 'P';
			map_to_win(game);
			game->player_x = game->player_x + 1;
			game->moviments++;
			printf("Movements: %d\n", game->moviments);
		}
	}
}

/**
 * It takes a key and a game struct, and if the key is one of the arrow keys or
 * WASD, it calls the appropriate function to move the player
 *
 * @param key the key that was pressed
 * @param game the game data structure
 *
 * @return 0
 */
int	key_events(int key, t_data *game)
{
	if (key == KEY_ESC)
		game_exit(game);
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
