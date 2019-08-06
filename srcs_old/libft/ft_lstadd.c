/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 15:44:29 by mbutt             #+#    #+#             */
/*   Updated: 2019/03/25 11:53:39 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Adds the element new at the beginning of the list.
** Param#1 - The address of a pointer to the first link of a list.
** param#2 - The link to add at the beginning of the list.
** Return Value - None.
** Libc function - None.
*/

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}
/*
** Creating an additional element
*/
/*
**void	ft_lstadd(t_list **alst, t_list *new)
**{
**	t_list *element;
**	element = new;
**	element->next = *alst;
**	*alst = element;
**}
*/
