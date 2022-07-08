/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:06:26 by lbatista          #+#    #+#             */
/*   Updated: 2022/07/08 00:13:16 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "mlx.h"
# include "libft.h"
# include <stdio.h>
# include <fcntl.h>

# define FREE_SPACE		"./img/free_space.xpm"
# define COLLECTABLE	"./img/collectable_blue.xpm"
# define COLLECTABLE_2	"./img/collectable_red.xpm"
# define WALL			"./img/wall.xpm"
# define EXIT			"./img/exit.xpm"
# define PLAYER			"./img/player.xpm"
# define PATROL			"./img/patrol.xpm"
# define SCORE_S		"./img/score_s.xpm"
# define SCORE_C		"./img/score_c.xpm"
# define SCORE_O		"./img/score_o.xpm"
# define SCORE_R		"./img/score_r.xpm"
# define SCORE_E		"./img/score_e.xpm"
# define SCORE_0		"./img/score_0.xpm"
# define SCORE_1		"./img/score_1.xpm"
# define SCORE_2		"./img/score_2.xpm"
# define SCORE_3		"./img/score_3.xpm"
# define SCORE_4		"./img/score_4.xpm"
# define SCORE_5		"./img/score_5.xpm"
# define SCORE_6		"./img/score_6.xpm"
# define SCORE_7		"./img/score_7.xpm"
# define SCORE_8		"./img/score_8.xpm"
# define SCORE_9		"./img/score_9.xpm"

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
	int		map_col;
	int		map_line;
	void	*img_free_space;
	void	*img_collectable;
	void	*img_collectable_2;
	void	*img_wall;
	void	*img_exit;
	void	*img_player;
	void	*img_patrol;
	int		img_width;
	int		img_height;
	void	*score_s;
	void	*score_c;
	void	*score_o;
	void	*score_r;
	void	*score_e;
	void	*score_0;
	void	*score_1;
	void	*score_2;
	void	*score_3;
	void	*score_4;
	void	*score_5;
	void	*score_6;
	void	*score_7;
	void	*score_8;
	void	*score_9;
	int		player_line;
	int		player_col;
	int		moviments;
	int		patrol_line;
	int		patrol_col;
}			t_data;

char	**map_built_bonus(t_data *game, char *file_path);

int		map_validation_bonus(t_data *game);

int		map_to_win_bonus(t_data *game);

void	img_setup_bonus(t_data *game);

void	game_setup_bonus(t_data *game);

int		key_events_bonus(int key, t_data *game);

int		game_exit_bonus(t_data *game);

int		animation(t_data *game);

void	patrol_mov_x(t_data *game);

void	patrol_mov_y(t_data *game);

void	patrol_mov_xy(t_data *game);

void	score_bonus(t_data *game);

void	img_anime(t_data *game, int x, int y);

void	game_over(t_data *game);

int		extension_validation(char *file);

void	ft_clear_split(char **ptr);

int		map_square(t_data *game);

#endif
