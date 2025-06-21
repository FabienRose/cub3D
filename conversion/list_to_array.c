/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:10:22 by diana             #+#    #+#             */
/*   Updated: 2025/06/21 19:22:38 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

#include <stdlib.h>

int list_size(t_node *head)
{
	int count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}

char **linked_list_to_array(t_node *head)
{
	int i = 0;
	char **array;
	int size = list_size(head);

	array = malloc(sizeof(char *) * (size + 1));
	if (!array)
		return (NULL);
	while (head)
	{
		array[i++] = head->line;
		head = head->next;
	}
	array[i] = NULL;
	return (array);
}
