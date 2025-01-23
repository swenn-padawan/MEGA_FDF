/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 00:53:37 by stetrel           #+#    #+#             */
/*   Updated: 2024/11/26 16:30:48 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char	*d;

	d = dst;
	if (!size--)
		return (ft_strlen(src));
	while (size-- && *src)
		*dst++ = *src++;
	*dst = 0;
	return (dst - d + ft_strlen(src));
}
