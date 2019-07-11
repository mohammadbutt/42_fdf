/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 20:15:46 by mbutt             #+#    #+#             */
/*   Updated: 2019/07/11 15:36:47 by mbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Create function allocates memory for the struct and stores the first row. And
** points to the next node setting it equal to NULL.
*/
t_fdf	*create(int *struct_coordinates)
{
	t_fdf *new_node;

	new_node = (t_fdf *)malloc(sizeof(t_fdf));
	if(new_node == NULL)
		ft_exit("linked_list.c create() error: Unable to allocate memory.\n");
	new_node->struct_coordinates = struct_coordinates;
	new_node->next = NULL;
	return(new_node);
}
/*
** appen goes through the while loop to get to NULL node and calls onto create
** function to allocate memory for the second row.
*/
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
/*
** Calls onto create to allocate memory for the struct to exist, and calls onto
** append function in  while loop to store each row one at a time.
*/
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
** **str_to_int_struct takes in 2D array of string, converts them into 2D
** int array.
**
** 2D string array that's taken in is stored as such:
** "0  1  3  0"
** "0 10 -5  0"
**
** This will look like this:
** characters[0] = "7  1  3  0"
** characters[1] = "4 10 -5  0"
** When any of the elements in this string are accessed they are perceived
** as characters, not numbers. chararcters [1][0] will be '4', characters[1][1]
** will be ' ', a space, and characters[1][2] will be '1';
**
** After the string is converted to a 2d int array, it will be stored as such:
** {7, 1, 3, 0}
** {4, 10, -5, 0}
** Now when any of the elements in this int array are accessed they are
** perceived as numbers. int_array[1][0] will be 4. int_array[1][1] will be 10,
** and int_array[1][2] will be -5.
** 
*/
int **str_to_int_struct(char **characters)
{
//	t_fdf *fdf;
	int i;
	int height;
	int **int_data_2;

//	fdf = malloc(sizeof(fdf));
//	if(fdf == NULL)
//		ft_exit("linked_list.c str_to_int_struct error1: Unable to malloc\n");
	i = 0;
	height = ft_height(characters);
//	fdf->int_data_2 = malloc(sizeof(int *) * (height));
	int_data_2 = malloc(sizeof(int *) * (height));
	if(int_data_2 == NULL)
		ft_exit("linked_list.c str_to_int_struct error: Unable to malloc\n");
//	if(fdf->int_data_2 == NULL)
//		ft_exit("linked_list.c str_to_int_struct error2: Unable to malloc\n");
	while(height)
	{
//		fdf->int_data_2[i] = ft_2d_atoi(characters[i]);
		int_data_2[i] = ft_2d_atoi(characters[i]);
		i++;
		height--;
	}
/*Insert the below code here to test if the str_to_int_struct works properly*/
	return(int_data_2);
}
/*
** Below is to test str_to_int_struct()
*/
/*
	i = 0;
	int j = 0;
	int wordcount = ft_wordcount(characters[i], ' ');
	int temp_wordcount = wordcount;
	height = ft_height(characters);
	while(height)
	{
		while(wordcount)
		{
			ft_putnbr(fdf->int_data_2[i][j]);
			if(fdf->int_data_2[i][j+1] == 0)
				ft_putstr("  ");
			else if(fdf->int_data_2[i][j+1] == 10)
				ft_putstr(" ");
			wordcount--;
			j++;
		}
		ft_putstr("\n");
		i++;
		j = 0;
		height--;
		wordcount = temp_wordcount;
	}
*/
/*
* ********************* Extra Functions ***************************************
*/
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
