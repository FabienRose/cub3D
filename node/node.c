/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 13:56:51 by diana             #+#    #+#             */
/*   Updated: 2025/06/21 15:27:08 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"
//# include "node.h"

t_node *create_node(char *line)
{
    t_node *new = malloc(sizeof(t_node));
    if (!new)
        return (NULL);
    new->line = line;
    new->next = NULL;
    return (new);
}

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

    while ((line = ft_gnl(fd)))
    {
        append_node(&head, line);
        // Ojo: no hagas free(line) porque lo usas en la lista
    }
    close(fd);
    return (head);
}
