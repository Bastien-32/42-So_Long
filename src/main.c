/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:17:19 by badal-la          #+#    #+#             */
/*   Updated: 2025/02/27 17:56:39 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4)
		error("File name too short\n");
	if (file[len - 1] != 'r' || file[len - 2] != 'e' || file[len - 3] != 'b' \
													|| file[len - 4] != '.')
		error("File extension must be .ber\n");
}

void	fill_width_and_height(t_map *map, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_fd("Opening file failed!", map);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		error_fd("Map file is empty!", map);
	}
	map->width = ft_strlen(line);
	while (line)
	{
		map->height++;
		if ((int)ft_strlen(line) != map->width)
			error_fd_open("Map is not rectangle", fd, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	fill_lines_map(t_map *map, char *file)
{
	int		i;
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_fd("Opening file failed!", map);
	map->line = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->line)
		error("Malloc map->line failed\n");
	map->line[map->height] = NULL;
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map->line[i] = line;
		i++;
		line = get_next_line(fd);
	}
	close(fd);
}

t_map	*parse_map(char *file)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		error("Malloc map failed\n");
	ft_bzero(map, sizeof(t_map));
	fill_width_and_height(map, file);
	fill_lines_map(map, file);
	return (map);
}

void	check_walls(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < map->width - 1)
	{
		if (map->line[0][x] != '1' || map->line[map->height - 1][x] != '1')
			free_args_and_exit(map, \
									"The map isn't closed unically by walls!");
		x++;
	}
	while (y < map->height - 1)
	{
		if (map->line[y][0] != '1' && map->line[y][map->width -1] != '1')
			free_args_and_exit(map, \
									"The map isn't closed unically by walls!");
		y++;
	}
}

void	check_inside_map(t_map *map)
{
	int	x;
	int	y;

	y = 1;
	while (y < (map->height - 1))
	{
		x = 1;
		while (x < (map->width - 2))
		{
			if (map->line[y][x] != '0' && map->line[y][x] != '1' \
				&& map->line[y][x] != 'C' && map->line[y][x] != 'E' \
				&& map->line[y][x] != 'P')
				free_args_and_exit(map, "Invalid character in map");
			if (map->line[y][x] == 'E')
				map->e++;
			if (map->line[y][x] == 'P')
				map->p++;
			if (map->line[y][x] == 'C')
				map->c++;
			x++;
		}
		y++;
	}
	if (map->e != 1 || map->p != 1 || map->c < 1)
		free_args_and_exit(map, "Invalid number of elements");
}

char	**duplicate_map(t_map *map)
{
	int		y;
	char	**copy;

	copy = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!copy)
		free_args_and_exit(map, "Malloc failed for map_copy");
	y = 0;
	while (y < map->height)
	{
		copy[y] = ft_strdup(map->line[y]);
		if (!copy[y])
		{
			while (--y >= 0)
				free(copy[y]);
			free(copy);
			free_args_and_exit(map, "Malloc failed for map copy line");
		}
		y++;
	}
	copy[y] = NULL;
	return (copy);
}

void	flood_fill(char **map_copy, int x, int y, t_map *map)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
		return ;
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'V')
		return ;
	if (map_copy[y][x] == 'E')
		map->p_to_e = 1;
	map_copy[y][x] = 'V';
	flood_fill(map_copy, x + 1, y, map);
	flood_fill(map_copy, x - 1, y, map);
	flood_fill(map_copy, x, y + 1, map);
	flood_fill(map_copy, x, y - 1, map);
}

void	free_map_copy(char **map_copy, int height)
{
	int	y;

	if (!map_copy)
		return ;
	y = 0;
	while (y < height)
	{
		if (map_copy[y])
			free(map_copy[y]);
		y++;
	}
	free(map_copy);
}

void	check_all_c_collected(char **map_copy, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map_copy[y][x] == 'C')
			{
				free_map_copy(map_copy, map->height);
				free_args_and_exit(map, \
						"Invalid map! Not all collectibles are accessible");
			}
			x++;
		}
		y++;
	}
}

void	check_road_p_to_e(t_map *map)
{
	int		x;
	int		y;
	char	**map_copy;

	y = 1;
	while (y < map->height - 1)
	{
		x = 1;
		while (x < map->width - 1)
		{
			if (map->line [y][x] == 'P')
				break ;
			x++;
		}
		if (map->line[y][x] == 'P')
			break ;
		y++;
	}
	map_copy = duplicate_map(map);
	flood_fill(map_copy, x, y, map);
	check_all_c_collected(map_copy, map);
	free_map_copy(map_copy, map->height);
	if (!map->p_to_e)
		free_args_and_exit(map, "Invalid map! Exit is not accessible");
}

void	check_map(t_map *map)
{
	check_walls(map);
	check_inside_map(map);
	check_road_p_to_e(map);
}

void	init_mlx(t_mlx *mlx, t_map *map)
{
	int	screen_width;
	int	screen_height;

	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		error("MiniLibX initialization failed!");
	mlx_get_screen_size(mlx->mlx_ptr, &screen_width, &screen_height);
	mlx->tile_size = TILE_SIZE;
	mlx->width_win = (map->width - 1) * mlx->tile_size;
	mlx->height_win = map->height * mlx->tile_size;
	if (mlx->width_win > screen_width || mlx->height_win > screen_height)
	{
		mlx->tile_size = screen_width / (map->width - 1);
		if (mlx->tile_size > screen_height / map->height)
			mlx->tile_size = screen_height / map->height;
		if (mlx->tile_size < 32)
			mlx->tile_size = 32;
		mlx->width_win = (map->width - 1) * mlx->tile_size;
		mlx->height_win = map->height * mlx->tile_size;
	}
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, \
								mlx->width_win, mlx->height_win, "So Long");
	if (!mlx->win_ptr)
		error("Window creation failed!");
	mlx->map = map;
	mlx->move_count = 0;
}

void	load_images_2(t_mlx *mlx)
{
	if (!mlx->img_collectible)
		error("Failed to load collectible image!");
	mlx->img_door_open = mlx_xpm_file_to_image(mlx->mlx_ptr, \
						"img/door_open.xpm", &mlx->img_width, &mlx->img_height);
	if (!mlx->img_door_open)
		error("Failed to load door open image!");
	mlx->img_door_closed = mlx_xpm_file_to_image(mlx->mlx_ptr, \
					"img/door_closed.xpm", &mlx->img_width, &mlx->img_height);
	if (!mlx->img_door_closed)
		error("Failed to load door closed image!");
	mlx->img_door_closed_player = mlx_xpm_file_to_image(mlx->mlx_ptr, \
			"img/door_closed_miner.xpm", &mlx->img_width, &mlx->img_height);
	if (!mlx->img_door_closed_player)
		error("Failed to load door closed player image!");
}

// Fonction pour charger une image XPM
void	load_images(t_mlx *mlx)
{
	mlx->img_bg = mlx_xpm_file_to_image(mlx->mlx_ptr, \
						"img/white_BG.xpm", &mlx->img_width, &mlx->img_height);
	if (!mlx->img_bg)
		error("Failed to load background image!");
	mlx->img_player = mlx_xpm_file_to_image(mlx->mlx_ptr, \
							"img/miner.xpm", &mlx->img_width, &mlx->img_height);
	if (!mlx->img_player)
		error("Failed to load miner image!");
	mlx->img_wall = mlx_xpm_file_to_image(mlx->mlx_ptr, \
							"img/wall.xpm", &mlx->img_width, &mlx->img_height);
	if (!mlx->img_wall)
		error("Failed to load wall image!");
	mlx->img_collectible = mlx_xpm_file_to_image(mlx->mlx_ptr, \
						"img/diamond.xpm", &mlx->img_width, &mlx->img_height);
	load_images_2(mlx);
}

void	draw_background(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < mlx->height_win)
	{
		x = 0;
		while (x < mlx->width_win)
		{
			mlx_put_image_to_window(mlx->mlx_ptr, \
											mlx->win_ptr, mlx->img_bg, x, y);
			x += TILE_SIZE;
		}
		y += TILE_SIZE;
	}
}

void	put_img_to_win(t_mlx *mlx, t_map *map, int x, int y)
{
	if (map->line[y][x] == '1')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
								mlx->img_wall, x * TILE_SIZE, y * TILE_SIZE);
	else if (map->line[y][x] == 'C')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
						mlx->img_collectible, x * TILE_SIZE, y * TILE_SIZE);
	else if (map->line[y][x] == 'E')
	{
		if (mlx->player_x == x && mlx->player_y == y && map->c > 0)
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
					mlx->img_door_closed_player, x * TILE_SIZE, y * TILE_SIZE);
		else if (map->c == 0)
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
							mlx->img_door_open, x * TILE_SIZE, y * TILE_SIZE);
		else
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
						mlx->img_door_closed, x * TILE_SIZE, y * TILE_SIZE);
	}
	else if (map->line[y][x] == 'P' && \
				!(mlx->player_x == x && mlx->player_y == y && map->c > 0))
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
								mlx->img_player, x * TILE_SIZE, y * TILE_SIZE);
}

void	draw_map(t_mlx *mlx, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			put_img_to_win(mlx, map, x, y);
			x++;
		}
		y++;
	}
}

void	find_player(t_mlx *mlx, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->line[y][x] == 'P')
			{
				mlx->player_x = x;
				mlx->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	draw_level_done(t_mlx *mlx)
{
	char	*move_count_str;
	char	*message;

	draw_background(mlx);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, mlx->width_win / 2 - 50,
		mlx->height_win / 2 - 10, 0x000000, "LEVEL DONE");
	move_count_str = ft_itoa(mlx->move_count);
	if (!move_count_str)
		return ;
	message = ft_strjoin("Moves : ", move_count_str);
	free(move_count_str);
	if (!message)
		return ;
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, mlx->width_win / 2 - 50,
		mlx->height_win / 2 + 10, 0x000000, message);
	free(message);
}

void	print_player_and_count_moves(t_mlx *mlx, int x, int y, int move)
{
	if (mlx->map->line[y][x] == 'E' && mlx->map->c > 0)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
					mlx->img_door_closed_player, x * TILE_SIZE, y * TILE_SIZE);
	else
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
								mlx->img_player, x * TILE_SIZE, y * TILE_SIZE);
	if (move)
	{
		mlx->move_count++;
		ft_printf("Moves : %d\n", mlx->move_count);
	}
}

void	move_player(t_mlx *mlx, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = mlx->player_x + dx;
	new_y = mlx->player_y + dy;
	if (mlx->map->line[new_y][new_x] == '1')
		return ;
	if (mlx->map->line[new_y][new_x] == 'C')
	{
		mlx->map->line[new_y][new_x] = '0';
		mlx->map->c--;
	}
	if (mlx->map->line[new_y][new_x] == 'E' && mlx->map->c == 0)
	{
		draw_level_done(mlx);
		return ;
	}
	if (mlx->map->line[mlx->player_y][mlx->player_x] != 'E')
		mlx->map->line[mlx->player_y][mlx->player_x] = '0';
	mlx->player_x = new_x;
	mlx->player_y = new_y;
	if (mlx->map->line[new_y][new_x] != 'E')
		mlx->map->line[new_y][new_x] = 'P';
	print_map(mlx, mlx->map);
	print_player_and_count_moves(mlx, new_x, new_y, 1);
}

void	init_keymap(t_keymap *keys)
{
	keys->up = KEY_UP;
	keys->down = KEY_DOWN;
	keys->left = KEY_LEFT;
	keys->right = KEY_RIGHT;
}

int	keypress(int keycode, t_mlx *mlx)
{
	static t_keymap	keys;

	if (keys.up == 0)
		init_keymap(&keys);
	if (keycode == 65307)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		exit(0);
	}
	else if (keycode == keys.up)
		move_player(mlx, 0, -1);
	else if (keycode == keys.down)
		move_player(mlx, 0, 1);
	else if (keycode == keys.left)
		move_player(mlx, -1, 0);
	else if (keycode == keys.right)
		move_player(mlx, 1, 0);
	return (0);
}

int	close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit(0);
	return (0);
}

int	reduce_window(t_mlx *mlx)
{
	print_map(mlx, mlx->map);
	print_player_and_count_moves(mlx, mlx->player_x, mlx->player_y, 0);
	return (0);
}

void	print_map(t_mlx *mlx, t_map *map)
{
	load_images(mlx);
	draw_background(mlx);
	draw_map(mlx, map);
	find_player(mlx, map);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	t_mlx	mlx;

	if (argc != 2)
		error("Usage : ./so_long [nameofmap.ber]\n");
	check_file(argv[1]);
	map = parse_map(argv[1]);
	check_map(map);
	init_mlx(&mlx, map);
	print_map(&mlx, map);
	mlx_hook(mlx.win_ptr, 2, 1L << 0, keypress, &mlx);
	mlx_hook(mlx.win_ptr, 17, 1L << 17, close_window, &mlx);
	mlx_hook(mlx.win_ptr, 12, 1L << 15, reduce_window, &mlx);
	mlx_loop(mlx.mlx_ptr);
	free(map);
	return (0);
}
