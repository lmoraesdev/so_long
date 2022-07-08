/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:19:27 by lbatista          #+#    #+#             */
/*   Updated: 2022/07/08 16:03:59 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * It counts the number of
 * characters in the map that are 'E', 'P', and 'C'
 *
 * @param game the game data structure
 *
 * @return the number of enemies, players, and chests
 * 		on the map.
 */
static int	position_validation(t_data *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map_width)
	{
		y = 0;
		while (y < game->map_height)
		{
			if (game->map[y][x] == 'E')
				game->map_e_count++;
			if (game->map[y][x] == 'P')
				game->map_p_count++;
			if (game->map[y][x] == 'C')
				game->map_c_count++;
			y++;
		}
		x++;
	}
	if (game->map_e_count != 1 || game->map_p_count != 1
		|| game->map_c_count == 0)
		return (1);
	return (0);
}

/**
 * It checks if the walls are valid
 *
 * @param game a pointer to the data structure that holds
 * all the information about
 * the game.
 *
 * @return an integer.
 */
static int	wall_validation(t_data *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map_width)
	{
		y = 0;
		while (y < game->map_height)
		{
			if (game->map[0][x] != '1'
				|| game->map[game->map_height - 1][x] != '1'
				|| game->map[y][0] != '1' ||
				game->map[y][game->map_width - 1] != '1')
				return (1);
			y++;
		}
		if (y != game->map_height)
			return (1);
		x++;
	}
	return (0);
}

/**
 * It checks if the map contains only valid characters
 *
 * @param game a pointer to the data structure that holds
 * all the information about
 * the game.
 *
 * @return an integer.
 */
static int	characters_validation(t_data *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map_width)
	{
		y = 0;
		while (y < game->map_height)
		{
			if (game->map[y][x] != '0' && game->map[y][x] != '1'
				&& game->map[y][x] != 'C' && game->map[y][x] != 'E'
				&& game->map[y][x] != 'P')
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

/**
 * It checks if the file extension is valid
 *
 * @param file the file name
 *
 * @return the value of the comparison between the extension of the file and the
 * string ".ber".
 */
int	extension_validation(char *file)
{
	char	*ext;

	if (!file)
		return (1);
	ext = ft_strrchr(file, '.');
	if (ext == NULL)
		return (1);
	if (ft_strncmp(ext, ".ber", 5) == 0)
		return (0);
	printf("Error\nextension not ok\n");
	return (1);
}

/**
 * It checks if the map is valid
 *
 * @param game the data structure that holds all the information about the game.
 *
 * @return the value of the function map_validation.
 */
int	map_validation(t_data *game)
{
	int	a;
	int	b;
	int	c;

	game->map_e_count = 0;
	game->map_s_count = 0;
	game->map_c_count = 0;
	game->map_p_count = 0;
	game->map_height = 0;
	game->map_width = (int)ft_strlen(game->map[0]);
	if (map_square(game) == 1)
	{
		printf("Error\nMAP VALIDATION PROBLEM\n");
		return (1);
	}
	while (game->map[game->map_height])
		game->map_height++;
	a = position_validation(game);
	b = wall_validation(game);
	c = characters_validation(game);
	if (a == 0 && b == 0 && c == 0)
		return (0);
	printf("Error\nMAP VALIDATION PROBLEM\n");
	return (1);
}
