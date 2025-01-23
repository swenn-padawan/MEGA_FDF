/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 03:39:38 by stetrel           #+#    #+#             */
/*   Updated: 2024/10/11 18:14:04 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	length;
	void	*ptr;

	if (size && nmemb > (size_t)-1 / size)
		return (NULL);
	length = nmemb * size;
	ptr = malloc(length);
	if (ptr)
		ft_bzero(ptr, length);
	return (ptr);
}
