/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:17:32 by stetrel           #+#    #+#             */
/*   Updated: 2024/10/09 00:02:18 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_isupper(int c)
{
	return ((unsigned)c - 'A' < 26);
}

int	ft_tolower(int c)
{
	if (ft_isupper(c))
		return (c | 32);
	return (c);
}
