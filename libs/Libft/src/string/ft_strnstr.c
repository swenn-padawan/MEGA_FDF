/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:04:27 by stetrel           #+#    #+#             */
/*   Updated: 2024/12/13 15:18:34 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*b;
	const char	*l;
	size_t		i;

	if (!*little)
		return ((char *)big);
	if (!len)
		return (NULL);
	while (*big && len >= ft_strlen(little))
	{
		b = big;
		l = little;
		i = 0;
		while (*b == *l && ++i < ft_strlen(little))
		{
			b++;
			l++;
		}
		if (i == ft_strlen(little))
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
