/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:02:52 by stetrel           #+#    #+#             */
/*   Updated: 2025/01/25 01:57:52 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_scancode.h>
#include <fdf.h>

static void	rotation_hook(int key, t_mlx *mlx)
{
	*(mlx->teta_x) = *(mlx->teta_x) *(M_PI / 180);
	*(mlx->teta_y) = *(mlx->teta_y) *(M_PI / 180);
	if (key == SDL_SCANCODE_SPACE)
	{
		mlx_clear_window(mlx->mlx, mlx->win);
		mlx->camera = camera_mult(*(mlx->camera), camera_scale(*(mlx->scale)));
		fdf_point_print(mlx);
	}
	if (key == SDL_SCANCODE_UP)
	{
		*(mlx->teta_x) -= 0.1;
		mlx->camera = camera_mult(*(mlx->camera), cam_rotate_x(*(mlx->teta_x)));
		mlx_clear_window(mlx->mlx, mlx->win);
		fdf_point_print(mlx);
	}
	else if (key == SDL_SCANCODE_DOWN)
	{
		*(mlx->teta_x) += 0.1;
		mlx->camera = camera_mult(*(mlx->camera), cam_rotate_x(*(mlx->teta_x)));
		mlx_clear_window(mlx->mlx, mlx->win);
		fdf_point_print(mlx);
	}
	else if (key == SDL_SCANCODE_RIGHT)
	{
		(*mlx->teta_y) -= 0.1;
		mlx->camera = camera_mult(*(mlx->camera), cam_rotate_y(*(mlx->teta_y)));
		mlx_clear_window(mlx->mlx, mlx->win);
		fdf_point_print(mlx);
	}
	else if (key == SDL_SCANCODE_LEFT)
	{
		*(mlx->teta_y) += 0.1;
		mlx->camera = camera_mult(*(mlx->camera), cam_rotate_y(*(mlx->teta_y)));
		mlx_clear_window(mlx->mlx, mlx->win);
		fdf_point_print(mlx);
	}
}

static void	other_hook(int key, t_mlx *mlx)
{
	if (key == 41)
		mlx_loop_end(mlx->mlx);
	else if (key == SDL_SCANCODE_R)
	{
		mlx_clear_window(mlx->mlx, mlx->win);
		fdf_point_print(mlx);
	}
}

int	key_hook(int key, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
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
