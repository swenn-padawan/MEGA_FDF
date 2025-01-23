/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:02:45 by stetrel           #+#    #+#             */
/*   Updated: 2024/10/09 01:08:01 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_islower(int c)
{
	return ((unsigned int)c - 'a' < 26);
}

int	ft_toupper(int c)
{
	if (ft_islower(c))
		return (c & 0x5f);
	return (c);
}
