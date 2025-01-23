/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 02:32:07 by stetrel           #+#    #+#             */
/*   Updated: 2024/10/11 20:32:36 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		length;
	char	*d;

	if ((!size || !dst) && !size)
		return (size + ft_strlen(src));
	length = ft_strlen(dst) + ft_strlen(src);
	d = dst + ft_strlen(dst);
	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	ft_strlcpy(d, src, size - ft_strlen(dst));
	return (length);
}
