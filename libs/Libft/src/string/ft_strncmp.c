/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:20:40 by stetrel           #+#    #+#             */
/*   Updated: 2024/10/09 02:09:48 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const char	*str;
	const char	*str2;

	str = s1;
	str2 = s2;
	if (!n--)
		return (0);
	while (*str && *str2 && (unsigned char)*str == (unsigned char)*str2 && n)
	{
		str++;
		str2++;
		n--;
	}
	return ((unsigned char)*str - (unsigned char)*str2);
}
