/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:30:55 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/16 17:32:25 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.h"

int	list_size(t_node *head)
{
	int	count;

	count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}

char	**linked_list_to_array(t_node *head)
{
	int		count;
	char	**array;
	int		i;

	count = list_size(head);
	array = malloc(sizeof(char *) * (count + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (i < count)
	{
		array[i] = ft_strdup(head->line);
		if (!array[i])
		{
			while (--i >= 0)
				free(array[i]);
			free(array);
			return (NULL);
		}
		head = head->next;
		i++;
	}
	array[i] = NULL;
	return (array);
}
