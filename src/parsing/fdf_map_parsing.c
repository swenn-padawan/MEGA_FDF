/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 23:49:46 by stetrel           #+#    #+#             */
/*   Updated: 2025/01/21 20:08:11 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <fdf.h>

t_list	*fdf_read_segment(int fd, int *bytes_read)
{
	t_list	*tmp;

	tmp = ft_lstnew(NULL);
	if (!tmp)
		return (NULL);
	*bytes_read = read(fd, tmp->buffer, FDF_BUFFER_SIZE - 1);
	if (*bytes_read > 0)
	{
		tmp->buffer[*bytes_read] = 0;
		return (tmp);
	}
	free(tmp);
	return (NULL);
}

int	fdf_read_lines(int fd, int *err, t_list **ret_list, int *size)
{
	int		bytes_read;
	t_list	*head;
	t_list	*tmp;

	*err = 0;
	head = NULL;
	while (1)
	{
		tmp = fdf_read_segment(fd, &bytes_read);
		if (!tmp)
		{
			if (bytes_read < 0)
				*err = 1;
			break ;
		}
		*size += bytes_read;
		ft_lstadd_back(&head, tmp);
	}
	if (*err)
		ft_lstfree(head);
	*ret_list = head;
	return (bytes_read);
}

char	*fdf_listjoin(t_list *list, int size)
{
	char	*str;
	char	*next_buffer;
	char	*tmp;
	t_list	*free_ptr;

	str = ft_calloc(sizeof(char), size + 1);
	if (!str)
		return (NULL);
	tmp = str;
	free_ptr = list;
	while (list)
	{
		next_buffer = list->buffer;
		ft_memcpy(tmp, next_buffer, ft_strlen(next_buffer));
		tmp += ft_strlen(next_buffer);
		list = list->next;
	}
	ft_lstfree(free_ptr);
	return (str);
}

int	fdf_map_parse(const char *filename, t_map *map, int *err)
{
	int32_t	fd;
	t_list	*lst;
	char	*str;
	int		size;
	char	*tmp;

	str = NULL;
	size = 0;
	if (!filename)
		return (1);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NO_PERMISSION);
	*err = fdf_read_lines(fd, err, &lst, &size);
	if (*err)
		return (*err);
	str = fdf_listjoin(lst, size);
	if (*err)
		return (*err);
	tmp = str;
	while (!*err && *str)
		*err = fdf_parse_point(map, str, &str);
	free(tmp);
	close(fd);
	return (*err);
}
