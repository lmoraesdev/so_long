/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:03:38 by lbatista          #+#    #+#             */
/*   Updated: 2022/06/22 13:08:01 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "libft.h"
# include <stdio.h>
# include <fcntl.h>

# define FREE_SPACE		"./img/free_space.xpm"
# define COLLECTABLE	"./img/collectable_blue.xpm"
# define WALL			"./img/wall.xpm"
# define EXIT			"./img/exit.xpm"
# define PLAYER			"./img/player.xpm"

# define KEY_ESC		65307
# define KEY_W			119
# define KEY_S			115
# define KEY_A			97
# define KEY_D			100
# define KEY_UP			65362
# define KEY_DOWN		65364
# define KEY_LEFT		65361
# define KEY_RIGHT		65363

typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		mlx_win_width;
	int		mlx_win_height;
	char	**map;
	int		map_fd;
	int		map_e_count;
	int		map_s_count;
	int		map_c_count;
	int		map_p_count;
	int		map_width;
	int		map_height;
	void	*img_free_space;
	void	*img_collectable;
	void	*img_wall;
	void	*img_exit;
	void	*img_player;
	int		img_width;
	int		img_height;
	int		player_x;
	int		player_y;
	int		moviments;

}			t_data;

char	**map_built(t_data *game, char *file_path);

int		map_validation(t_data *game);

int		map_to_win(t_data *game);

int		key_events(int key, t_data *game);

void	img_setup(t_data *game);

void	game_setup(t_data *game);

int		win_events(t_data *game);

int		game_exit(t_data *game);

int		extension_validation(char *file);

void	ft_clear_split(char **ptr);

int		map_square(t_data *game);

#endif
