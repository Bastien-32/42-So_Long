/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:21:21 by badal-la          #+#    #+#             */
/*   Updated: 2025/02/25 15:52:07 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *msg)
{
	ft_printf("Error!\n");
	ft_printf("%s\n", msg);
	exit (1);
}

void	error_fd_open(char *msg, int fd, char *line)
{
	ft_printf("Error\n");
	ft_printf("%s\n", msg);
	free(line);
	close(fd);
	exit (1);
}

void	error_fd(char *msg, t_map *map)
{
		free(map);
		error(msg);
}

void	free_args_and_exit(t_map *map, char *msg)
{
	int	i;

	if (!map->line)
		return ;
	i = 0;
	while (i < map->height)
		free(map->line[i++]);
	printf("uhu\n");
	free(map->line);
	free(map);
	error(msg);
	exit(1);
}