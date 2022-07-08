/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:17:49 by lbatista          #+#    #+#             */
/*   Updated: 2022/06/24 11:17:55 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	map_square(t_data *game)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
	{
		if ((int)ft_strlen(game->map[i]) != game->map_col)
			return (1);
		i++;
	}
	return (0);
}
