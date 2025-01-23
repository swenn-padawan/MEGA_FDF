/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:52:40 by stetrel           #+#    #+#             */
/*   Updated: 2025/01/21 21:54:31 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	mouse_down_wheel_hook(void *params)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)params;
	if (mlx->transfo->zoom - 1 > 0)
		mlx->transfo->zoom--;
	mlx_clear_window(mlx->mlx, mlx->win);
	fdf_point_print(mlx, mlx->transfo);
	return (0);
}

static int	mouse_up_wheel_hook(void *params)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)params;
	if (mlx->transfo->zoom + 1 < 10)
		mlx->transfo->zoom++;
	mlx_clear_window(mlx->mlx, mlx->win);
	fdf_point_print(mlx, mlx->transfo);
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
