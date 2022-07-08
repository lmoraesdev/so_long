/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:19:58 by lbatista          #+#    #+#             */
/*   Updated: 2022/06/29 00:07:32 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * It sets up the game window,
 * and then sets up the game loop
 *
 * @param game a pointer to the t_data struct
 */
static void	game_play(t_data *game)
{
	game->mlx_ptr = mlx_init();
	img_setup(game);
	game->mlx_win = mlx_new_window(game->mlx_ptr,
			game->img_width * game->map_width,
			game->img_height * game->map_height, "SO_LONG");
	map_to_win(game);
	game_setup(game);
	mlx_hook(game->mlx_win, 2, 1L << 0, key_events, game);
	mlx_hook(game->mlx_win, 17, 1L << 0, game_exit, game);
	mlx_loop_hook(game->mlx_ptr, map_to_win, game);
	mlx_loop(game->mlx_ptr);
}

/**
 * The main function of the program. It checks the extension of the file, builds
 * the map, validates the map and starts the game.
 *
 * @param argc the number of arguments passed to the program
 * @param argv an array of strings, each string is one of the arguments passed to
 * the program.
 *
 * @return the number of bytes that were written to the file.
 */

int	main(int argc, char **argv)
{
	t_data	game;

	if (extension_validation(argv[1]) == 1)
		return (1);
	if (argc == 2)
	{
		game.map = map_built(&game, argv[1]);
		if (game.map == NULL)
		{
			ft_clear_split(game.map);
			return (1);
		}
		if (map_validation(&game) == 0)
			game_play(&game);
		else
		{
			ft_clear_split(game.map);
			exit(1);
		}
	}
	else
		printf("ERROR\nPath to map not found!\n");
	return (0);
}
