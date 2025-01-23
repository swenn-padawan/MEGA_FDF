/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:16:51 by stetrel           #+#    #+#             */
/*   Updated: 2025/01/21 20:54:21 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_scancode.h>
#include <fdf.h>

int	check_args(char *filename)
{
	int	len;

	if (!filename || !*filename)
		return (1);
	len = ft_strlen(filename);
	if (!ft_strnstr(&filename[len - 4], ".fdf", 4))
		return (1);
	return (0);
}

int	zoom_init(t_map *map)
{
	int	zoom;

	zoom = (fmin((float)WINDOW_HEIGHT / map->row, (float)WINDOW_WIDTH
				/ map->col)) / 2;
	if (zoom > 10)
		zoom = 10;
	else if (zoom <= 0)
		zoom = 1;
	return (zoom);
}

t_transfo	init_transfo(t_map *map)
{
	t_transfo	transfo;

	transfo.x = 30;
	transfo.y = 5;
	transfo.z = -10;
	transfo.zoom = zoom_init(map);
	return (transfo);
}

int	main(int argc, char **argv)
{
	static t_map		map = {0};
	static t_transfo	transfo = {0};
	t_mlx				mlx;
	int					err;

	if (check_args(argv[1]) || argc != 2)
		return (write(2, "No or Too Much Files Provided\n", 30));
	err = fdf_map_parse(argv[1], &map, &err);
	if (err)
		fdf_handle_error(err);
	if (map.col == 1 || map.row == 1)
		fdf_handle_error(ONE_LINE);
	transfo = init_transfo(&map);
	mlx.mlx = mlx_init();
	mlx.map = &map;
	mlx.data = map.data;
	mlx.transfo = &transfo;
	mlx.win = mlx_new_window(mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "fdf");
	fdf_point_print(&mlx, mlx.transfo);
	mlx_on_event(mlx.mlx, mlx.win, MLX_WINDOW_EVENT, window_hook, &mlx);
	mlx_on_event(mlx.mlx, mlx.win, MLX_KEYDOWN, key_hook, &mlx);
	mlx_on_event(mlx.mlx, mlx.win, MLX_MOUSEWHEEL, mouse_wheel_hook, &mlx);
	mlx_loop(mlx.mlx);
	mlx_destroy_window(mlx.mlx, mlx.win);
	mlx_destroy_display(mlx.mlx);
}
