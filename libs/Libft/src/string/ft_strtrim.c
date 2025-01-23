/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:34:30 by stetrel           #+#    #+#             */
/*   Updated: 2024/10/14 14:16:41 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char *set)
{
	while (*set != c && *set)
		set++;
	if (!*set)
		return (0);
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;

	if (!s1)
		return (NULL);
	if (!*set || !*s1)
		return (ft_strdup(s1));
	while (ft_isset(*s1, (char *)set))
		s1++;
	len = ft_strlen(s1);
	while (len && ft_isset(s1[len - 1], (char *)set))
		len--;
	return (ft_substr(s1, 0, len));
}
