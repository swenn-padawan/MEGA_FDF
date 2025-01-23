/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 22:01:33 by stetrel           #+#    #+#             */
/*   Updated: 2025/01/21 18:44:44 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static t_list	**alloc_collector(void)
{
	static t_list	*lst;

	if (!lst)
		lst = ft_lstnew(NULL);
	return (&lst);
}

__attribute__((destructor))
static void	free_alloc_collector(void)
{
	t_list	**lst;
	t_list	*tmp;

	lst = alloc_collector();
	if (!lst)
		return ;
	tmp = *lst;
	while (tmp->next)
	{
		tmp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	free(tmp->content);
	free(tmp);
}

void lp_free(void *address)
{
    t_list **lst;
    t_list *current;
    t_list *prev;

	lst = alloc_collector();
	current = *lst;
	prev = NULL;
    while (current)
    {
        if (current->content == address)
        {
            if (prev == NULL)
                *lst = current->next;
            else
                prev->next = current->next;

            free(current->content);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}


static void	lp_push(void *malloc_address)
{
	t_list	**lst;

	lst = alloc_collector();
	ft_lstadd_front(lst, ft_lstnew(malloc_address));
}

void	*lp_alloc(size_t size)
{
	void	*ptr;

	ptr = ft_calloc(size, 1);
	lp_push(ptr);
	return (ptr);
}
