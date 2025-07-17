/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 13:56:57 by diana             #+#    #+#             */
/*   Updated: 2025/07/09 17:05:33 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_H
# define CONVERSION_H

# include "../cub3d.h"

typedef struct s_node
{
	char			*line;
	struct s_node	*next;
}	t_node;

//----linked_list.c----
t_node			*create_node(char *line);
void			append_node(t_node **head, char *line);
t_node			*read_file_to_list(const char *filename);

//----list_to_array.c----
int				list_size(t_node *head);
char			**linked_list_to_array(t_node *head);

#endif