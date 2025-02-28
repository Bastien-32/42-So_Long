/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:17:19 by badal-la          #+#    #+#             */
/*   Updated: 2025/02/28 17:46:33 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx(t_mlx *mlx, t_map *map)
{
	int	screen_width;
	int	screen_height;

	ft_bzero(mlx, sizeof(t_mlx));
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		error("MiniLibX initialization failed!");
	mlx_get_screen_size(mlx->mlx_ptr, &screen_width, &screen_height);
	mlx->tile_size = TILE_SIZE;
	mlx->width_win = (map->width - 1) * mlx->tile_size;
	mlx->height_win = map->height * mlx->tile_size;
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, \
								mlx->width_win, mlx->height_win, "So Long");
	if (!mlx->win_ptr)
		error("Window creation failed!");
	mlx->map = map;
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
