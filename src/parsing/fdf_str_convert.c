/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_str_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:04:57 by stetrel           #+#    #+#             */
/*   Updated: 2024/12/06 21:41:36 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

#define HEX "0123456789abcdef"

static int	fdf_strhex(char *str, char **remain, int *err)
{
	int		nb;
	char	*index;

	nb = 0;
	if (str[0] != '0' || !str[1] || (str[1] | 32) != 'x')
		return (0);
	str += 2;
	while (*str && str != (*remain + 10))
	{
		index = ft_strchr(HEX, (*str | ((*str - 'A' < 6) * 32)));
		if (!index)
			break ;
		if (*str >= '0' && *str <= '9')
			nb = (nb << 4) + (*str - '0');
		else if (*str >= 'a' && *str <= 'f')
			nb = (nb << 4) + (*str - 'a' + 10);
		else if (*str >= 'A' && *str <= 'F')
			nb = (nb << 4) + (*str - 'A' + 10);
		str++;
	}
	if (!nb && str < (*remain + 4))
		*err = 1;
	if (remain)
		*remain = str;
	return (nb);
}

static int	fdf_strtoi(char *str, char **remain, int base, int *err)
{
	int	n;
	int	sign;

	n = 0;
	if (base == 16)
		return (fdf_strhex(str, remain, err));
	sign = (*str == '-');
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		n = n * 10 + *str - '0';
		str++;
	}
	*err = 0;
	if (!n && str == *remain)
		*err = 1;
	if (remain)
		*remain = str;
	if (sign)
		return (-n);
	return (n);
}

static int	fdf_parse_col_row(t_map *map, char *str, char **remain)
{
	while (*str && (*str - 9 < 5 || *str == 32))
	{
		if (*str == '\n')
		{
			map->row++;
			if (!map->col)
				map->col = map->parse_index;
			if (map->parse_index % map->col)
				return (6);
		}
		str++;
	}
	if (remain)
		*remain = str;
	return (0);
}

int	fdf_parse_point(t_map *map, char *str, char **remain)
{
	int	n;
	int	err;

	while (*str && ((unsigned char)*str - 9 < 5 || *str == 32))
		str++;
	if (!*str)
		return (0);
	n = fdf_strtoi(str, &str, 10, &err);
	if (err)
		return (4);
	map->data[map->parse_index] = n;
	if (*str == ',')
	{
		str++;
		n = fdf_strtoi(str, &str, 16, &err);
		if (err)
			return (6);
		map->color[map->parse_index].argb = (uint32_t)n;
	}
	map->parse_index++;
	fdf_parse_col_row(map, str, remain);
	return (0);
}
