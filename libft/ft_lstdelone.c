/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 20:29:04 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/25 11:48:35 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description - Takes as a parameter a link's pointer address and free the
** memory of the link's content using the function del given as a parameter,
** then free the link's memory using free. The memory of next must not be freed
** under any circumstance. Finally, the pointer to the link that was just freed
** must be set to NULL (quite similar to the function ft_memdel in the mandatory
** part).
** Param#1 - The address of a pointer to a link that needs to be freed.
** Return Value - None.
** Libc functions - free.
*/

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (((*alst)->content != NULL || (*alst)->content_size != 0))
	{
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = NULL;
	}
}
