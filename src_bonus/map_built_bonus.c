/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_built_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:16:17 by lbatista          #+#    #+#             */
/*   Updated: 2022/06/24 11:16:27 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	empty_line( char *temp)
{
	int	i;

	i = 0;
	if (temp[0] == '\n')
	{
		printf("Error\nMAP VALIDATION PROBLEM\n");
		free(temp);
		return (1);
	}
	while (temp[i] != '\0')
	{
		if (temp[i] == '\n')
		{
			if (temp[i + 1] == '\n' && temp [i + 2] == '1')
			{
				free(temp);
				printf("Error\nMAP VALIDATION PROBLEM\n");
				return (1);
			}
		}
		i++;
	}
	return (0);
}

static char	*add_line(char **temp)
{
	int		i;
	char	*new;
	char	*swap;

	i = 0;
	while ((*temp)[i] != '\n')
		i++;
	new = ft_calloc((i + 2), sizeof(char));
	if (new == NULL)
		return (NULL);
	new[i] = '\n';
	while (i > 0)
	{
		new[i - 1] = 'S';
		i--;
	}
	swap = *temp;
	*temp = ft_strjoin(new, swap);
	free(new);
	free(swap);
	return (*temp);
}

static char	*parse_map(t_data *game)
{
	char	*line;
	char	*swap;
	char	*temp;

	temp = ft_strdup("");
	while (1)
	{
		line = ft_get_next_line(game->map_fd);
		if (!line)
			break ;
		swap = temp;
		temp = ft_strjoin(swap, line);
		free(line);
		free(swap);
	}
	return (temp);
}

static int	open_map(t_data *game, char *file_path)
{
	game->map_fd = open(file_path, O_RDONLY);
	if (game->map_fd == -1)
		return (1);
	return (0);
}

char	**map_built_bonus(t_data *game, char *file_path)
{
	char	**map;
	char	*swap;
	char	*temp;

	if (open_map(game, file_path) == 1)
		return (NULL);
	temp = parse_map(game);
	if (temp == NULL)
		return (NULL);
	if (empty_line(temp) == 1)
		return (NULL);
	swap = add_line(&temp);
	if (swap == NULL)
		return (NULL);
	map = ft_split(swap, '\n');
	free(swap);
	close(game->map_fd);
	return (map);
}
