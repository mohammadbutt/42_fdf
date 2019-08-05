/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 22:17:21 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/25 13:24:07 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description - Iterates a list lst and applies the function f to each link to
** create a “fresh” list (using malloc(3)) resulting from the suc- cessive
** applications of f. If the allocation fails, the function returns NULL.
** Param#1 - A pointer to the first link of a list.
** Param#2 - The address of a function to apply to each link of a list.
** Return Value - The new list.
** Libc function - malloc, free.
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_list;

	if (!lst)
		return (NULL);
	new_list = f(lst);
	if (lst)
	{
		new_list->next = ft_lstmap(lst->next, f);
	}
	return (new_list);
}
