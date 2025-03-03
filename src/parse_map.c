/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:42:04 by student           #+#    #+#             */
/*   Updated: 2025/03/03 14:06:04 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			error_fd_open("Map is not rectangle", fd, line, map);
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
