/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:01:37 by badal-la          #+#    #+#             */
/*   Updated: 2025/03/03 19:03:05 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
