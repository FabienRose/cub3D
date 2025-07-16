/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:30:36 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/16 17:30:36 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.h"

t_node	*create_node(char *line)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->line = line;
	new->next = NULL;
	return (new);
}

void	append_node(t_node **head, char *line)
{
	t_node	*new;
	t_node	*temp;

	new = create_node(line);
	if (!*head)
	{
		*head = new;
		return ;
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

t_node	*read_file_to_list(const char *filename)
{
	int		fd;
	char	*line;
	t_node	*head;

	head = NULL;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (NULL);
	}
	line = ft_gnl(fd);
	while (line)
	{
		append_node(&head, line);
		line = ft_gnl(fd);
	}
	close(fd);
	return (head);
}

void	free_linked_list(t_node *head)
{
	t_node	*tmp;

	while (head)
	{
		tmp = head->next;
		free(head->line);
		free(head);
		head = tmp;
	}
}
