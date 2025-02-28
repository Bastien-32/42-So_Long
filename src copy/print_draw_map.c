/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_draw_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:22:05 by student           #+#    #+#             */
/*   Updated: 2025/02/28 17:50:05 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

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

void	print_map(t_mlx *mlx, t_map *map)
{
	load_images(mlx);
	draw_background(mlx);
	draw_map(mlx, map);
	find_player(mlx, map);
}

