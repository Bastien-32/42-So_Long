/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:41:06 by student           #+#    #+#             */
/*   Updated: 2025/02/28 15:49:48 by student          ###   ########.fr       */
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
