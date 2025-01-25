/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:52:40 by stetrel           #+#    #+#             */
/*   Updated: 2025/01/25 01:46:52 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

static int	mouse_down_wheel_hook(void *params)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)params;
	mlx_clear_window(mlx->mlx, mlx->win);
	*(mlx->scale) -= 0.01;
	mlx->camera = camera_mult(*(mlx->camera), camera_scale(*(mlx->scale)));
	fdf_point_print(mlx);
	return (0);
}

static int	mouse_up_wheel_hook(void *params)
{
	t_mlx	*mlx;
	mlx = (t_mlx *)params;
	mlx_clear_window(mlx->mlx, mlx->win);
	*(mlx->scale) += 0.01;
	mlx->camera = camera_mult(*(mlx->camera), camera_scale(*(mlx->scale)));
	fdf_point_print(mlx);
	return (0);
}

int	mouse_wheel_hook(int button, void *params)
{
	if (button == 1)
		mouse_up_wheel_hook(params);
	if (button == 2)
		mouse_down_wheel_hook(params);
	return (0);
}
