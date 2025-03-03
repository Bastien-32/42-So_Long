/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:08:39 by badal-la          #+#    #+#             */
/*   Updated: 2025/03/03 19:08:42 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	draw_map(mlx, mlx->map);
	print_player_and_count_moves(mlx, new_x, new_y, 1);
}
