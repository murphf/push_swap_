/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <styes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:24:24 by styes             #+#    #+#             */
/*   Updated: 2022/07/16 16:55:34 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* convert circular doubly linked list to an array
*/
int	*list_to_array(t_node	**head)
{
	int		len;
	t_node	*first_node;
	int		*array;
	int		i;

	len = list_len(head);
	first_node = *head;
	array = (int *)malloc(sizeof(int) * len);
	if (!array)
		return (NULL);
	i = 0;
	while (i < len)
	{
		array[i++] = first_node->data;
		first_node = first_node->next;
	}
	return (array);
}

int	*arr_smallest_on_top(t_node	**head)
{
	int	*array;
	int size;
	int	pos;
	int	i;
	int k;
	t_node	*first_node;
	t_node	*last_node;
	
	i = 0;
	k = 0;
	first_node = *head;
	last_node = first_node->prev;
	size = list_len(head);
	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	pos = position(head, smallest(head));
	while (first_node != last_node)
	{
		if (i >= pos)
			{
				array[k] = first_node->data;
				k++;
			}
		i++;
		first_node = first_node->next;
	}
	if (i >= pos)
		{
			array[k] = first_node->data;
			k++;
		}
	first_node = *head;
	i = 0;
	while (i < pos)
	{
		array[k] = first_node->data;
		k++;
		i++;
		first_node = first_node->next;
	}
	return (array);
}

/*
* print content of array 
*/
void	printarray(int *array, int size)
{
	int	i;

	i = 0;
	if (!array)
		printf("NOTHING!\n");
	while (i < size)
		printf("%d ", array[i++]);
	printf("\n");
}
