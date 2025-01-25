/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:16:51 by stetrel           #+#    #+#             */
/*   Updated: 2025/01/25 01:49:46 by vboxuser         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	static t_map		map = {0};
	t_mlx				mlx;
	int					err;

	static t_camera	camera = {.matrix = {{1.0, 0.0, 0.0, 0.0},
										{0.0, 1.0, 0.0, 0.0},
										{0.0, 0.0, 1.0, 0.0},
										{0.0, 0.0, 0.0, 1.0}}};

	static float	scale = 1;
	static float	x = 1;
	static float	y = 1;
	if (check_args(argv[1]) || argc != 2)
		return (write(2, "No or Too Much Files Provided\n", 30));
	err = fdf_map_parse(argv[1], &map, &err);
	if (err)
		fdf_handle_error(err);
	if (map.col == 1 || map.row == 1)
		fdf_handle_error(ONE_LINE);
	mlx.mlx = mlx_init();
	mlx.map = &map;
	mlx.data = map.data;
	mlx.win = mlx_new_window(mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "fdf");
	mlx.camera = &camera;
	mlx.scale = &scale;
	mlx.teta_x = &x;
	mlx.teta_y = &y;
	fdf_point_print(&mlx);
	mlx_on_event(mlx.mlx, mlx.win, MLX_WINDOW_EVENT, window_hook, &mlx);
	mlx_on_event(mlx.mlx, mlx.win, MLX_KEYDOWN, key_hook, &mlx);
	mlx_on_event(mlx.mlx, mlx.win, MLX_MOUSEWHEEL, mouse_wheel_hook, &mlx);
	mlx_loop(mlx.mlx);
	mlx_destroy_window(mlx.mlx, mlx.win);
	mlx_destroy_display(mlx.mlx);
}
