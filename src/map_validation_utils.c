/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:19:04 by lbatista          #+#    #+#             */
/*   Updated: 2022/06/28 23:51:07 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * It checks if the map is square
 *
 * @param game the structure that holds all the data for the game
 *
 * @return the length of the string.
 */
int	map_square(t_data *game)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
	{
		if ((int)ft_strlen(game->map[i]) != game->map_width)
			return (1);
		i++;
	}
	return (0);
}
