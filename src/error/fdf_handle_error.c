/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_handle_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:06:15 by stetrel           #+#    #+#             */
/*   Updated: 2024/12/13 15:00:15 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	fdf_handle_error(int err)
{
	if (err == NO_FILE)
		write(2, "No File Are Provided\n", 21);
	else if (err == NO_PERMISSION)
		write(2, "No Permission\n", 14);
	else if (err == BAD_MAP)
		write(2, "The Map is not correct\n", 23);
	else if (err == BAD_COLOR)
		write(2, "A Color is not Formatted Correctly\n", 35);
	else if (err == BAD_DATA)
		write(2, "A Heigth is not Correct (Maybe out of the int Range)\n", 53);
	else if (err == ONE_LINE)
		write(2, "Useless Map (More lines please)\n", 32);
	exit(EXIT_FAILURE);
}
