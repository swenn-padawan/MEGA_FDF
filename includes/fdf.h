/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:51:55 by stetrel           #+#    #+#             */
/*   Updated: 2025/01/23 12:30:18 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libs/Libft/include/libft.h"
# include "../libs/MacroLibX/includes/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdint.h>
# include <unistd.h>

# define FDF_BUFFER_SIZE 65536
# define WINDOW_HEIGHT 1080
# define WINDOW_WIDTH 1920
# define PIXEL 2

enum				e_error
{
	NO_FILE = 1,
	NO_PERMISSION,
	BAD_DATA,
	BAD_MAP,
	BAD_COLOR,
	ONE_LINE
};

typedef struct s_line
{
	uint32_t		*line1;
	uint32_t		*line2;
}					t_line;

typedef union u_color
{
	struct
	{
		uint8_t		b;
		uint8_t		g;
		uint8_t		r;
		uint8_t		a;
	};
	uint32_t		argb;
}					t_color;

typedef struct s_map
{
	uint16_t		col;
	uint16_t		row;
	uint32_t		parse_index;
	uint32_t		data[33554432];
	t_color			color[33554432];
}					t_map;

typedef union	s_camera
{
	struct
	{
		float	x[4];
		float	y[4];
		float	z[4];
		float	w[4];
	};
	float	matrix[4][4];
}	t_camera;

typedef struct	s_coord
{
	float	matrix[4];
	struct
	{
		float	x;
		float	y;
		float	z;
		float	w;
	};
}	t_coord;

typedef struct s_draw
{
	int				diffx;
	int				diffy;
	float			dx;
	float			dy;
	float			ix;
	float			iy;
	float			max;
}					t_draw;

typedef struct s_tranfo
{
	int				zoom;
	double			x;
	double			y;
	double			z;
}					t_transfo;

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	uint32_t		*data;
	t_map			*map;
	t_transfo		*transfo;
}					t_mlx;

// PARSING
int					fdf_map_parse(const char *filename, t_map *map, int *err);
int					fdf_parse_point(t_map *map, char *str, char **remain);
char				*fdf_listjoin(t_list *list, int size);

// RENDER
int					fdf_point_print(t_mlx *mlx, t_transfo *transfo);
void				fdf_line_draw(int *matrix0, int *matrix1, t_mlx *mlx);
int					fdf_coord_check(int x, int y);

// COLOR
uint32_t			fdf_custom_color(int height, uint32_t color);

// MATHS

// KEY_HOOK
int					key_hook(int key, void *param);
int					window_hook(int event, void *param);
int					mouse_wheel_hook(int button, void *params);

// UTILS

// ERROR
void				fdf_handle_error(int err);

#endif
