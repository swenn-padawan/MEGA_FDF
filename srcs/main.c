/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:05:34 by stetrel           #+#    #+#             */
/*   Updated: 2025/01/21 01:51:52 by swenntetrel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main()
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();

	mlx.info.title = "Super Traceur de Rayons";
	mlx.info.width = 500;
	mlx.info.height = 500;
	mlx.win = mlx_new_window(mlx.mlx, &mlx.info);
	mlx_on_event(mlx.mlx, mlx.win, MLX_KEYDOWN, key_hook, &mlx);
	mlx_loop(mlx.mlx);
	mlx_destroy_window(mlx.mlx, mlx.win);
	mlx_destroy_context(mlx.mlx);
} 
