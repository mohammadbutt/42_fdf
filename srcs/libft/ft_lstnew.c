/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 10:28:11 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/25 11:48:51 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description- Allocates (with malloc) and returns a "fresh" link. The
** variables content and content_size of the new link are initialized by copy of
** the parameters of the function. If the parameter content is nul, the
** variable content is initialized to NULL and the variable content_size is
** initialized to 0 even if the parameter content_size isnt. The variable next
** is initialized to NULL. If the allocation fails, the function returns NULL.
** Param#1- The content to put in the new link.
** Param#2- The size of the cotent of the new link.
** RETURN VALUE- The new link.
** Libc functions - malloc, free.
** -> A linked list is a data structure.
*/

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *n_node;

	n_node = (t_list *)malloc(sizeof(t_list));
	if (n_node == NULL)
		return (NULL);
	if (content == 0)
	{
		n_node->content = NULL;
		n_node->content_size = 0;
		return (n_node);
	}
	n_node->content = malloc(sizeof(void) * (content_size));
	if (!(n_node->content))
		return (NULL);
	ft_memcpy(n_node->content, content, content_size);
	n_node->content_size = content_size;
	n_node->next = NULL;
	return (n_node);
}
