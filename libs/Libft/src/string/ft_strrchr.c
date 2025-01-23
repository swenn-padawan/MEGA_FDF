/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:32:23 by stetrel           #+#    #+#             */
/*   Updated: 2024/10/14 13:32:34 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*tmp;
	const char	*occ;

	tmp = s;
	occ = NULL;
	while (*tmp)
	{
		if (*tmp == (unsigned char)c)
			occ = tmp;
		tmp++;
	}
	if (!(unsigned char)c)
		return ((char *)tmp);
	return ((char *)occ);
}
