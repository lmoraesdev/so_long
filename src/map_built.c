/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_built.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:17:27 by lbatista          #+#    #+#             */
/*   Updated: 2022/07/08 16:01:09 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * This function checks if there are any empty lines in the map
 *
 * @param temp the string that contains the map
 *
 * @return the number of lines in the file.
 */
int	empty_line( char *temp)
{
	int	i;

	i = 0;
	if (temp[0] == '\n')
	{
		printf("ERROR\nMAP VALIDATION PROBLEM\n");
		free(temp);
		return (1);
	}
	while (temp[i] != '\0')
	{
		if (temp[i] == '\n')
		{
			if (temp[i + 1] == '\n' && temp [i + 2] == '1')
			{
				printf("ERROR\nMAP VALIDATION PROBLEM\n");
				free(temp);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

/**
 * It opens the file, reads it, and returns a 2D array of the map
 *
 * @param game a pointer to the data structure that holds
 * all the information about
 * the game.
 * @param file_path the path to the map file
 *
 * @return A 2D array of characters.
 */
char	**map_built(t_data *game, char *file_path)
{
	char	**map;
	char	*swap;
	char	*line;
	char	*temp;

	game->map_fd = open(file_path, O_RDONLY);
	if (game->map_fd == -1)
		return (NULL);
	temp = ft_strdup("");
	while (1)
	{
		line = ft_get_next_line(game->map_fd);
		if (!line)
			break ;
		swap = temp;
		temp = ft_strjoin(swap, line);
		free(swap);
		free(line);
	}
	if (empty_line(temp) == 1)
		return (NULL);
	map = ft_split(temp, '\n');
	free(temp);
	close(game->map_fd);
	return (map);
}
