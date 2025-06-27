/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:58:59 by diana             #+#    #+#             */
/*   Updated: 2025/06/27 16:01:29 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

int	parse_map(t_node *head)
{
	t_node	*current = head;
	t_flags	flags = {0};

	while (current && !all_flags_set(&flags))
	{
		if (is_line_empty_or_spaces_only(current->line))
		{
			current = current->next;
			continue;
		}
		if (!check_and_set_flag(current->line, &flags))
		{
			ft_putendl_fd("Error", 2);
			ft_putendl_fd("Clave no reconocida", 2);
			return (0);
		}
		current = current->next;
	}
	if (!all_flags_set(&flags))
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Faltan claves obligatorias", 2);
		return (0);
	}
	return (1);
}

void	free_list(t_node *head)
{
	t_node	*tmp;

	while (head)
	{
		tmp = head->next;
		if (head->line)
			free(head->line);
		free(head);
		head = tmp;
	}
}
