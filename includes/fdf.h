/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swenntetrel <swenntetrel@42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 01:06:20 by swenntetrel       #+#    #+#             */
/*   Updated: 2025/01/21 01:51:29 by swenntetrel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/MacroLibX/includes/mlx.h"
# include "../lib/MacroLibX/includes/mlx_extended.h"
# include "hook.h"

#include <stdio.h>

typedef struct	s_mlx
{
	mlx_context				mlx;
	mlx_window				win;
	mlx_window_create_info	info;

}	t_mlx;

#endif
