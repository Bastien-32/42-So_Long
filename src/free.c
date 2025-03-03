/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:46:28 by student           #+#    #+#             */
/*   Updated: 2025/03/03 14:05:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_images(t_mlx *mlx)
{
	if (mlx->img_door_closed)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_door_closed);
	if (mlx->img_door_closed_player)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_door_closed_player);
	if (mlx->img_door_open)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_door_open);
	if (mlx->img_player)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_player);
	if (mlx->img_wall)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_wall);
	if (mlx->img_collectible)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_collectible);
	if (mlx->img_bg)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_bg);
}

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->line)
	{
		i = 0;
		while (i < map->height)
		{
			free(map->line[i]);
			i++;
		}
		free(map->line);
	}
	free(map);
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
