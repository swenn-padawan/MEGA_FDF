/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_point_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:48:42 by stetrel           #+#    #+#             */
/*   Updated: 2025/01/25 01:51:38 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#define FOV (90 * (M_PI / 180))
#define ASPECT ((float)WINDOW_WIDTH / (float)WINDOW_HEIGHT)
#define FAR 1.0f
#define NEAR 500.0f

#include <fdf.h>

t_camera	camera_scale(float scale)
{
	t_camera camera = {.matrix = {{scale, 0.0, 0.0, 0.0},
								 {0.0, scale, 0.0, 0.0},
								 {0.0, 0.0, scale, 0.0},
								 {0.0, 0.0, 0.0, scale}}};

	return (camera);
}


t_camera	camera_fov(void)
{
	
	t_camera	camera = {.matrix = {   {1/(ASPECT-tan(FOV / 2)), 0.0,			   0.0,							 0.0},
										{0.0,                     1/(tan(FOV/2)),  0.0,							 0.0},
										{0.0,                     0.0,            -(FAR+NEAR) / (FAR-NEAR),		-((2 * FAR * NEAR) / (FAR - NEAR))},
										{0.0,                     0.0,            -1.0,							 0.0}}};
	return (camera);
}

t_camera *camera_mult(t_camera a, t_camera b)
{
	static t_camera	res;
	int	i;
	int	j;
	int	k;

	i = 0;
	ft_memset(&res, 0, sizeof(res));
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				res.matrix[i][j] += a.matrix[i][k] * b.matrix[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (&res);
}

t_camera	cam_translate(float x, float y, float z)
{
	t_camera	camera = {.matrix = {{1.0f, 0.0f, 0.0f, x},
									{0.0f, 1.0, 0.0f, y},
									{0.0f, 0.0, 1.0f, z},
									{0.0f, 0.0, 1.0f, 1.0f}}};
	return (camera);
}

t_camera	cam_rotate_x(float teta)
{
	t_camera	camera = {.matrix = {	{1.0, 0.0, 0.0, 1.0},
										{0.0, cos(teta), -sin(teta), 1.0},
										{0.0, sin(teta), cos(teta), 1.0},
										{0.0, 0.0, 0.0, 1.0}}};
	return (camera);
}

t_camera	cam_rotate_y(float teta)
{
	
	t_camera	res = {.matrix = {		{cos(teta),	0.0, sin(teta), 1.0},
										{0.0,		1.0, 0.0, 1.0},
										{-sin(teta),	0.0, cos(teta), 1.0},
										{0.0, 0.0,  0.0, 1.0}}};
	return (res);
}

t_camera	cam_rotate_z(float teta)
{
	
	t_camera	res = {.matrix = {		{cos(teta), -sin(teta), 0.0, 1.0},
										{sin(teta), cos(teta), 0.0, 1.0},
										{0.0,    0.0,	  0.0, 1.0},
										{0.0,    0.0,	  0.0, 1.0}}};
	return (res);
}

static t_coord	compute_pixels(t_coord coord, t_camera camera)
{
	t_coord res;

	res.matrix[0] = coord.matrix[0] * camera.matrix[0][0] + coord.matrix[1] * camera.matrix[1][0] + coord.matrix[2] * camera.matrix[2][0] + coord.matrix[3] * camera.matrix[3][0];
	res.matrix[1] = coord.matrix[0] * camera.matrix[0][1] + coord.matrix[1] * camera.matrix[1][1] + coord.matrix[2] * camera.matrix[2][1] + coord.matrix[3] * camera.matrix[3][1];
	res.matrix[2] = coord.matrix[0] * camera.matrix[0][2] + coord.matrix[1] * camera.matrix[1][2] + coord.matrix[2] * camera.matrix[2][2] + coord.matrix[3] * camera.matrix[3][2];
	res.matrix[3] = coord.matrix[0] * camera.matrix[0][3] + coord.matrix[1] * camera.matrix[1][3] + coord.matrix[2] * camera.matrix[2][3] + coord.matrix[3] * camera.matrix[3][3];
	return (res);
}

int	fdf_point_print(t_mlx *mlx)
{
	float x = 0;
	float y = 0;
	int	z = 0;;
	t_coord coord;
	int	o = 0;
	for (int i = 0; i < mlx->map->col; i++)
	{
		y = 0;
		for (int j = 0; j < mlx->map->row; j++)
		{
			z = mlx->map->data[o];
			o++;
			coord.matrix[0] = x - mlx->map->col;
			coord.matrix[1] = y - mlx->map->row;
			coord.matrix[2] = z;
			coord.matrix[3] = 1.0f;
			coord = compute_pixels(coord , *(mlx->camera));
			if (coord.matrix[0] > 0 && coord.matrix[0] < WINDOW_WIDTH && coord.matrix[1] > 0 && coord.matrix[1] < WINDOW_HEIGHT)
				mlx_pixel_put(mlx->mlx, mlx->win, coord.matrix[0], coord.matrix[1], 0xFFFF898F);
			y+=2;
		}
		x+=2;
	}
	return (0);
}
