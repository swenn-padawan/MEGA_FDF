/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 00:22:43 by stetrel           #+#    #+#             */
/*   Updated: 2024/10/14 13:32:09 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const void	*d;
	const void	*s;

	d = dest;
	s = src;
	if (!dest && !src && n)
		return (NULL);
	while (n--)
		*(unsigned char *)d++ = *(unsigned char *)s++;
	return (dest);
}
