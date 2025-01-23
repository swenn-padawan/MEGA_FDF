/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:13:31 by stetrel           #+#    #+#             */
/*   Updated: 2024/10/14 13:25:00 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str;
	const unsigned char	*str2;

	if (!n)
		return (0);
	str = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((*str == *str2) && --n)
	{
		str++;
		str2++;
	}
	return ((unsigned char)*str - (unsigned char)*str2);
}
