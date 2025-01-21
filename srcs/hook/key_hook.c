/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swenntetrel <swenntetrel@42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 01:40:16 by swenntetrel       #+#    #+#             */
/*   Updated: 2025/01/21 00:54:05 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_hook(int key, void *params)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)params;
	if (key == 41)
		mlx_loop_end(mlx->mlx);
}
