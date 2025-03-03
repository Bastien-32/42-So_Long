/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:50:36 by student           #+#    #+#             */
/*   Updated: 2025/03/03 11:52:58 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images_2(t_mlx *mlx)
{
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
	if (!mlx->img_collectible)
		error("Failed to load collectible image!");
	load_images_2(mlx);
}

void	put_img_to_win(t_mlx *mlx, t_map *map, int x, int y)
{
	if (map->line[y][x] == '1')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
								mlx->img_wall, x * TILE_SIZE, y * TILE_SIZE);
	if (map->line[y][x] == '0')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
								mlx->img_bg, x * TILE_SIZE, y * TILE_SIZE);
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
