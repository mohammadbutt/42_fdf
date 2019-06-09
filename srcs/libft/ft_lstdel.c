/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 14:21:07 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/25 11:51:52 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description - Takes as a parameter the address of a pointer to a link and
** frees the memory of this link and every sucessors of that link using the
** functions del and free. Finallt the pointer to the link that was just freed
** must be set to NULL (quite similar to the function ft_memdel from the
** mandatory part).
** Param#1 - The address of a pointer to the first link of a list that needs to
** be freed.
** Return value - None.
** Libc functions - free.
*/

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next_element;

	while (*alst != NULL)
	{
		next_element = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = NULL;
		*alst = next_element;
	}
	*alst = NULL;
}
/*
** Using ft_lsdelone function
*/
/*
**void ft_lstdel(t_list **alst, void(*del)(void *, size_t))
**{
**	t_list *next_element;
**	while(*alst != NULL)
**	{
**		next_element = (*alst)->next;
**		ft_lstdelone(alst, del);
**		*alst = next_element;
**	}
**	*alst = NULL;
**}
*/
