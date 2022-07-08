/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:17:28 by lbatista          #+#    #+#             */
/*   Updated: 2022/06/24 11:17:35 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	position_validation(t_data *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map_line)
	{
		y = 0;
		while (y < game->map_col)
		{
			if (game->map[x][y] == 'E')
				game->map_e_count++;
			if (game->map[x][y] == 'P')
				game->map_p_count++;
			if (game->map[x][y] == 'C')
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

static int	wall_validation(t_data *game)
{
	int	x;
	int	y;

	x = 1;
	while (x < game->map_line)
	{
		y = 0;
		while (y < game->map_col)
		{
			if (game->map[1][y] != '1'
				|| game->map[game->map_line - 1][y] != '1'
				|| game->map[x][0] != '1'
				|| game->map[x][game->map_col - 1] != '1')
				return (1);
			y++;
		}
		if (y != game->map_col)
			return (1);
		x++;
	}
	return (0);
}

static int	characters_validation(t_data *game)
{
	int	x;
	int	y;

	x = 1;
	while (x < game->map_line)
	{
		y = 0;
		while (y < game->map_col)
		{
			if (game->map[x][y] != '0' && game->map[x][y] != '1'
				&& game->map[x][y] != 'C' && game->map[x][y] != 'E'
				&& game->map[x][y] != 'P' && game->map[x][y] != 'V')
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

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

int	map_validation_bonus(t_data *game)
{
	int	a;
	int	b;
	int	c;

	game->map_e_count = 0;
	game->map_s_count = 0;
	game->map_c_count = 0;
	game->map_p_count = 0;
	game->map_line = 0;
	game->map_col = (int)ft_strlen(game->map[0]);
	if (map_square(game) == 1)
	{
		printf("Error\nMAP VALIDATION PROBLEM\n");
		return (1);
	}
	while (game->map[game->map_line])
		game->map_line++;
	a = position_validation(game);
	b = wall_validation(game);
	c = characters_validation(game);
	if (a == 0 && b == 0 && c == 0)
		return (0);
	printf("Error\nMAP VALIDATION PROBLEM\n");
	return (1);
}
