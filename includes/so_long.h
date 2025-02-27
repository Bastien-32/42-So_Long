/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:32:48 by badal-la          #+#    #+#             */
/*   Updated: 2025/02/27 17:51:34 by badal-la         ###   ########.fr       */
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

#ifdef __APPLE__
	# define KEY_UP 65362
	# define KEY_DOWN 65364
	# define KEY_LEFT 65361
	# define KEY_RIGHT 65363
#else
	# define KEY_UP 119
	# define KEY_DOWN 115
	# define KEY_LEFT 97
	# define KEY_RIGHT 100
#endif

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

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		img_width;
	int		img_height;
	void	*img_door_closed;
	void	*img_door_closed_player;
	void	*img_door_open;
	void	*img_player;
	void	*img_wall;
	void	*img_collectible;
	void	*img_bg;
	int		width_win;
	int		height_win;
	int		tile_size;
	int		player_x;
	int		player_y;
	int		move_count;
	t_map	*map;
}			t_mlx;

typedef struct s_keymap
{
	int	up;
	int	down;
	int	left;
	int	right;
}	t_keymap;

/* ****************************************************************************
								  errors
**************************************************************************** */

void	error(char *msg);
void	error_fd_open(char *msg, int fd, char *line);
void	error_fd(char *msg, t_map *map);
void	free_args_and_exit(t_map *map, char *msg);

void	print_map(t_mlx *mlx, t_map *map);

#endif