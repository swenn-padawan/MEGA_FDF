/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:46:26 by stetrel           #+#    #+#             */
/*   Updated: 2025/01/21 21:09:57 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <math.h>

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void	fdf_line_draw(int *matrix0, int *matrix1, t_mlx *mlx)
{
	t_draw	draw;

	draw.diffx = matrix1[0] - matrix0[0];
	draw.diffy = matrix1[1] - matrix0[1];
	draw.max = (float)ft_abs(ft_max(ft_abs(draw.diffx), ft_abs(draw.diffy)));
	draw.dx = (float)draw.diffx / draw.max;
	draw.dy = (float)draw.diffy / draw.max;
	draw.ix = matrix0[0];
	draw.iy = matrix0[1];
	while (draw.ix != matrix1[0] || draw.iy != matrix1[1])
	{
		if (fabsf(draw.ix - matrix1[0]) < 1e-1f && fabsf(draw.iy
				- matrix1[1]) < 1e-1f)
			break ;
		draw.ix += draw.dx;
		draw.iy += draw.dy;
		if (roundf(draw.ix) < 0 || roundf(draw.ix) < 0
			|| roundf(draw.ix) > WINDOW_WIDTH - 1
			|| roundf(draw.iy) > WINDOW_HEIGHT - 1)
			continue ;
		mlx_pixel_put(mlx->mlx, mlx->win, roundf(draw.ix), roundf(draw.iy),
			0xff8396ff);
	}
}
