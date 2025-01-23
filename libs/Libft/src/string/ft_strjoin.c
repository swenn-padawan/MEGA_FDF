/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:49:08 by stetrel           #+#    #+#             */
/*   Updated: 2025/01/21 18:46:01 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = lp_alloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str)
	{
		ft_strlcpy(str, s1, ft_strlen(s1) + 1);
		ft_strlcat(str + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	}
	return (str);
}
