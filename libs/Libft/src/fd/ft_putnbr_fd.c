/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:56:36 by stetrel           #+#    #+#             */
/*   Updated: 2024/10/11 01:39:46 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print(char c, int fd)
{
	write (fd, &c, 1);
}

static void	ft_putnbr(int nb, int fd)
{
	if (nb == -2147483648)
	{
		write (fd, "-", 1);
		write (fd, "2147483648", 10);
		return ;
	}
	else if (nb < 0)
	{
		ft_print('-', fd);
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, fd);
		ft_putnbr(nb % 10, fd);
	}
	else
		ft_print(nb + 48, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (!fd)
		return ;
	ft_putnbr(n, fd);
}
