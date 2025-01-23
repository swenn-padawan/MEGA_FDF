/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:02:52 by stetrel           #+#    #+#             */
/*   Updated: 2025/01/21 20:51:20 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_scancode.h>
#include <fdf.h>

static void	rotation_hook(int key, t_mlx *mlx)
{
	if (key == SDL_SCANCODE_UP)
	{
		mlx->transfo->x += 1;
		mlx_clear_window(mlx->mlx, mlx->win);
		fdf_point_print(mlx, mlx->transfo);
	}
	else if (key == SDL_SCANCODE_DOWN)
	{
		mlx->transfo->x -= 1;
		mlx_clear_window(mlx->mlx, mlx->win);
		fdf_point_print(mlx, mlx->transfo);
	}
	else if (key == SDL_SCANCODE_RIGHT)
	{
		mlx->transfo->y += 1;
		mlx_clear_window(mlx->mlx, mlx->win);
		fdf_point_print(mlx, mlx->transfo);
	}
	else if (key == SDL_SCANCODE_LEFT)
	{
		mlx->transfo->y -= 1;
		mlx_clear_window(mlx->mlx, mlx->win);
		fdf_point_print(mlx, mlx->transfo);
	}
}

static void	other_hook(int key, t_mlx *mlx)
{
	if (key == 41)
		mlx_loop_end(mlx->mlx);
	else if (key == SDL_SCANCODE_R)
	{
		mlx->transfo->x = 30;
		mlx->transfo->z = -10;
		mlx->transfo->zoom = 1;
		mlx->transfo->x = 0;
		mlx->transfo->y = 0;
		mlx_clear_window(mlx->mlx, mlx->win);
		fdf_point_print(mlx, mlx->transfo);
	}
}

int	key_hook(int key, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (mlx->transfo->zoom <= 1)
		mlx->transfo->zoom = 1;
	rotation_hook(key, mlx);
	other_hook(key, mlx);
	return (0);
}
int	window_hook(int event, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (event == 0)
		mlx_loop_end(mlx->mlx);
	return (0);
}
