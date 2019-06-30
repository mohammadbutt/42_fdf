/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 20:15:46 by mbutt             #+#    #+#             */
/*   Updated: 2019/06/29 22:36:04 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


t_fdf	*create(int *struct_coordinates)
{
	t_fdf *new_node;

	new_node = (t_fdf *)malloc(sizeof(t_fdf));
	if(new_node == NULL)
		ft_exit("Unable to allocate memory\n");
	new_node->struct_coordinates = struct_coordinates;
	new_node->next = NULL;
	return(new_node);
}


t_fdf	*append(t_fdf *head, int *struct_coordinates)
{
	t_fdf *cursor;
	t_fdf *new_node;

	cursor = head;
	while(cursor->next != NULL)
		cursor = cursor->next;
	new_node = create(struct_coordinates);
	cursor->next = new_node;
	return(head);
}

t_fdf *int_data_to_struct(int **int_data, int height)
{
	t_fdf *pointer_2;
	int i;

	i = 1;
	pointer_2 = create(int_data[0]);
	while(i < height)
	{
		pointer_2 = append(pointer_2, int_data[i]);
		i++;
	}
	return(pointer_2);
}

/*
** print_data_cood - prints data that's stored in a struct.
** Only for testing.
*/
void print_data_coord(t_fdf *struct_pointer, char **characters)
{
	int i;
	int width;
	int *pointer_2;

	i = 0;
	width = ft_width(characters);
	while(struct_pointer)
	{
		pointer_2 = struct_pointer->struct_coordinates;
		while(i < width)
		{
			ft_putnbr(pointer_2[i]);
			if(pointer_2[i] == 10)
				ft_putstr(" ");
			if(pointer_2[i] == 0)
				ft_putstr("  ");
			i++;
		}
		ft_putstr("\n");
		i = 0;
		struct_pointer = struct_pointer->next;
	}
}
