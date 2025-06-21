/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 13:56:51 by diana             #+#    #+#             */
/*   Updated: 2025/06/21 21:33:35 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

//create a new node of the linked list 
//build the structure line by line
t_node *create_node(char *line)
{
    t_node *new = malloc(sizeof(t_node));
    if (!new)
        return (NULL);
    new->line = line;
    new->next = NULL;
    return (new);
}
//add a new node to the end of the list
//make sure it follow the order of the file.cub
void append_node(t_node **head, char *line)
{
    t_node *new = create_node(line);
    t_node *temp;

    if (!*head)
    {
        *head = new;
        return;
    }
    temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = new;
}
//open the file.cub and read every line and save it as linked list
t_node *read_file_to_list(const char *filename)
{
    int     fd;
    char    *line;
    t_node  *head = NULL;

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

//free all the memory linked to the linked list
//first the line after the node 
void	free_linked_list(t_node *head)
{
	t_node *tmp;

	while (head)
	{
		tmp = head->next;
		free(head->line);
		free(head);
		head = tmp;
	}
}
