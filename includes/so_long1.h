/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:32:48 by badal-la          #+#    #+#             */
/*   Updated: 2025/03/03 14:16:44 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include "ft_printf.h"
# include "../get_next_line/get_next_line_bonus.h"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>

# define WIDTH_WIN 1600
# define HEIGHT_WIN 1000
# define TILE_SIZE 64
# define BACKGROUND_COLOR 0xFFFFFF

// Init keyboard on apple(french) keyboard or linux(english) keyboard
//apple use arrow cases
//linux use WSAD
/* #ifdef __APPLE__
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
#else */
# define KEY_UP 119
# define KEY_DOWN 115
# define KEY_LEFT 97
# define KEY_RIGHT 100
/* #endif */

typedef struct s_map
{
	int		fd;
	char	**line;
	int		width;
	int		height;
	int		e;
	int		p;
	int		c;
	int		p_to_e;
}			t_map;

typedef struct s_keymap
{
	int	up;
	int	down;
	int	left;
	int	right;
}	t_keymap;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			img_width;
	int			img_height;
	void		*img_door_closed;
	void		*img_door_closed_player;
	void		*img_door_open;
	void		*img_player;
	void		*img_wall;
	void		*img_collectible;
	void		*img_bg;
	int			width_win;
	int			height_win;
	int			tile_size;
	int			player_x;
	int			player_y;
	int			move_count;
	int			input_locked;
	t_keymap	keys;
	t_map		*map;
}				t_mlx;

/* ****************************************************************************
								  check.c
**************************************************************************** */

void	check_all_c_collected(char **map_copy, t_map *map);
void	check_road_p_to_e(t_map *map);
void	check_map(t_map *map);

/* ****************************************************************************
								  check2.c
**************************************************************************** */

void	check_file(char *file);
void	check_walls(t_map *map);
void	check_inside_map(t_map *map);
char	**duplicate_map(t_map *map);
void	flood_fill(char **map_copy, int x, int y, t_map *map);

/* ****************************************************************************
								  errors.c
**************************************************************************** */

void	error(char *msg);
void	error_fd_open(char *msg, int fd, char *line, t_map *map);
void	error_fd(char *msg, t_map *map);
void	free_args_and_exit(t_map *map, char *msg);

/* ****************************************************************************
								  free.c
**************************************************************************** */

void	free_images(t_mlx *mlx);
void	free_map(t_map *map);
void	free_map_copy(char **map_copy, int height);

/* ****************************************************************************
								   img.c
**************************************************************************** */

void	load_images_2(t_mlx *mlx);
void	load_images(t_mlx *mlx);
void	put_img_to_win(t_mlx *mlx, t_map *map, int x, int y);

/* ****************************************************************************
								  keys.c
**************************************************************************** */

void	init_keymap(t_keymap *keys);
int		keypress(int keycode, t_mlx *mlx);
int		close_window(t_mlx *mlx);
int		reduce_window(t_mlx *mlx);
void	exit_program(t_mlx *mlx);

/* ****************************************************************************
								parse_map.c
**************************************************************************** */

void	fill_width_and_height(t_map *map, char *file);
void	fill_lines_map(t_map *map, char *file);
t_map	*parse_map(char *file);

/* ****************************************************************************
								  player.c
**************************************************************************** */

void	find_player(t_mlx *mlx, t_map *map);
void	move_player(t_mlx *mlx, int dx, int dy);

/* ****************************************************************************
							print_draw_map.c
**************************************************************************** */

void	draw_background(t_mlx *mlx);
void	draw_map(t_mlx *mlx, t_map *map);
void	draw_level_done(t_mlx *mlx);
void	print_player_and_count_moves(t_mlx *mlx, int x, int y, int move);
void	print_map(t_mlx *mlx, t_map *map);

#endif