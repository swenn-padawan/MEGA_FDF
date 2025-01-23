/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_point_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:48:42 by stetrel           #+#    #+#             */
/*   Updated: 2025/01/23 12:22:29 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#define FOV (60 * (M_PI / 180))
#define ASPECT ((float)WINDOW_WIDTH / (float)WINDOW_HEIGHT)
#define FAR 1.0f
#define NEAR 500.0f
#define X -10 * (M_PI / 180)
#define Y 0 * (M_PI / 180)
#define Z 90 * (M_PI / 180)
#define SCALE 1.1f
#define DX 100.0f
#define DY 100.0f
#define DZ 100.0f


#include <fdf.h>
#include <stdio.h>
void	scale(t_camera *camera, float scale)
{
	camera->matrix[0][0] *= scale;
	camera->matrix[1][1] *= scale;
	camera->matrix[2][2] *= scale;
}


t_camera	camera_fov(void)
{
	
	t_camera	camera = {.matrix = {   {1/(ASPECT-tan(FOV / 2)), 0.0,			   0.0,							 0.0},
										{0.0,                     1/(tan(FOV/2)),  0.0,							 0.0},
										{0.0,                     0.0,            -(FAR+NEAR) / (FAR-NEAR),		-((2 * FAR * NEAR) / (FAR - NEAR))},
										{0.0,                     0.0,            -1.0,							 0.0}}};
	return (camera);
}

t_camera camera_mult(t_camera a, t_camera b)
{
	t_camera	res = {0};
	int	i;
	int	j;
	int	k;

	i = 0;
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
	return (res);
}

t_camera	cam_translate(void)
{
	t_camera	camera = {.matrix = {{1.0f, 0.0f, 0.0f, DX},
									{0.0f, 1.0, 0.0f, DY},
									{0.0f, 0.0, 1.0f, DZ},
									{0.0f, 0.0, 1.0f, 1.0f}}};
	return (camera);
}

t_camera	cam_rotate_x(void)
{
	t_camera	camera = {.matrix = {	{1.0, 0.0, 0.0, 1.0},
										{0.0, cos(X), -sin(X), 1.0},
										{0.0, sin(X), cos(X), 1.0},
										{0.0, 0.0, 0.0, 1.0}}};
	return (camera);
}

t_camera	cam_rotate_y(void)
{
	
	t_camera	res = {.matrix = {		{cos(Y),	0.0, sin(Y), 1.0},
										{0.0,		1.0, 0.0, 1.0},
										{-sin(Y),	0.0, cos(Y), 1.0},
										{0.0, 0.0,  0.0, 1.0}}};
	return (res);
}

t_camera	cam_rotate_z(void)
{
	
	t_camera	res = {.matrix = {		{cos(Y), -sin(Y), 0.0, 1.0},
										{sin(Z), cos(Z), 0.0, 1.0},
										{0.0,    0.0,	  0.0, 1.0},
										{0.0,    0.0,	  0.0, 1.0}}};
	return (res);
}

t_coord	compute_pixels(t_coord coord)
{
	t_coord res;
	t_camera	camera = {.matrix = {{1.0f, 0.0f, 0.0f, 1.0f},
									{0.0f, 1.0f, 0.0f, 1.0f},
									{0.0f, 0.0f, 1.0f, 1.0f},
									{0.0f, 0.0f, 0.0f, 1.0f}}};

	camera = camera_mult(camera, cam_rotate_x());
//	camera = camera_mult(camera, cam_rotate_y());
//	camera = camera_mult(camera, cam_rotate_z());
//	camera = camera_mult(camera, cam_translate());
	camera = camera_mult(camera, camera_fov());
	scale(&camera, SCALE);
	//camera.matrix[0][3] += DX;
	//camera.matrix[1][3] += DY;
	//camera.matrix[2][3] += DZ;
	res.matrix[0] = coord.matrix[0] * camera.matrix[0][0] + coord.matrix[1] * camera.matrix[1][0] + coord.matrix[2] * camera.matrix[2][0] + coord.matrix[3] * camera.matrix[3][0];
	res.matrix[1] = coord.matrix[0] * camera.matrix[0][1] + coord.matrix[1] * camera.matrix[1][1] + coord.matrix[2] * camera.matrix[2][1] + coord.matrix[3] * camera.matrix[3][1];
	res.matrix[2] = coord.matrix[0] * camera.matrix[0][2] + coord.matrix[1] * camera.matrix[1][2] + coord.matrix[2] * camera.matrix[2][2] + coord.matrix[3] * camera.matrix[3][2];
	res.matrix[3] = coord.matrix[0] * camera.matrix[0][3] + coord.matrix[1] * camera.matrix[1][3] + coord.matrix[2] * camera.matrix[2][3] + coord.matrix[3] * camera.matrix[3][3];
	return (res);
}

/*
t_coord	compute_pixels(t_coord coord)
{
	t_camera	camera = {.matrix = {   {1/(ASPECT-tan(FOV / 2)), 0.0,                                      0.0, 0.0},
										{0.0,                     1/(tan(FOV/2)),                           0.0, 0.0},
										{0.0,                     0.0,            -(FAR+NEAR) / (FAR-NEAR), -((2 * FAR * NEAR) / (FAR - NEAR))},
										{0.0,                     0.0,            -1.0,                     0.0}}};
	t_coord res;
	scale(&camera, 15);
	camera = camera_mult(camera, cam_translate(4, 4, -4)); 
	res.matrix[0] = coord.matrix[0] * camera.matrix[0][0] + coord.matrix[1] * camera.matrix[1][0] + coord.matrix[2] * camera.matrix[2][0] + coord.matrix[3] * camera.matrix[3][0];
	res.matrix[1] = coord.matrix[0] * camera.matrix[0][1] + coord.matrix[1] * camera.matrix[1][1] + coord.matrix[2] * camera.matrix[2][1] + coord.matrix[3] * camera.matrix[3][1];
	res.matrix[2] = coord.matrix[0] * camera.matrix[0][2] + coord.matrix[1] * camera.matrix[1][2] + coord.matrix[2] * camera.matrix[2][2] + coord.matrix[3] * camera.matrix[3][2];
	res.matrix[3] = coord.matrix[0] * camera.matrix[0][3] + coord.matrix[1] * camera.matrix[1][3] + coord.matrix[2] * camera.matrix[2][3] + coord.matrix[3] * camera.matrix[3][3];
	return (res);
}
*/
int	fdf_point_print(t_mlx *mlx, t_transfo *transfo)
{
	(void)transfo;
	float x = 0;
	float y = 0;
	int		z = 0;;
//	float w = 1.0f;
	t_coord coord;
	int	o = 0;

	for (int i = 0; i < mlx->map->col; i++)
	{
		y = 0;
		for (int j = 0; j < mlx->map->row; j++)
		{
			z = mlx->map->data[o];
			o++;
			coord.matrix[0] = x;
			coord.matrix[1] = y;
			coord.matrix[2] = z;
			coord.matrix[3] = 1.0f;
			//printf("before tranfo= x: %f| y: %f| z: %f|\n", coord.matrix[0], coord.matrix[1], coord.matrix[2]);
			coord = compute_pixels(coord);
			//printf("After tranfo= x: %f| y: %f| z: %f|\n", coord.matrix[0], coord.matrix[1], coord.matrix[2]);
			if (coord.matrix[0] > 0 && coord.matrix[0] < WINDOW_WIDTH && coord.matrix[1] > 0 && coord.matrix[1] < WINDOW_HEIGHT)
				mlx_pixel_put(mlx->mlx, mlx->win, coord.matrix[0], coord.matrix[1], 0xFFFF89FF);
			y+=2;
		}
		x+=2;
	}
	return (0);
}
