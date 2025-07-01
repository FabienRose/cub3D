/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_key_extension.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:27:27 by diana             #+#    #+#             */
/*   Updated: 2025/06/30 19:31:49 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	is_duplicate_key(int *key_count, int key_index, const char *line)
{
	key_count[key_index - 1]++;
	if (key_count[key_index - 1] > 1)
	{
		printf("Duplicate key: %s\n", line);
		return (1);
	}
	return (0);
}

static int	check_missing_keys(int *key_count)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (key_count[i] == 0)
		{
			printf("Missing key: %d\n", i + 1);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	initialize_key_count(int *key_count)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		key_count[i] = 0;
		i++;
	}
	return (1);
}

static int	process_node(t_node *node, int *key_count)
{
	int	key_index;

	if (!is_line_empty_or_spaces_only(node->line))
	{
		key_index = is_valid_key(node->line);
		if (key_index > 0)
		{
			if (is_duplicate_key(key_count, key_index, node->line))
				return (0);
		}
		else if (is_unrecognized_key(node->line))
			return (0);
	}
	return (1);
}

int	validate_unique_keys(t_node *list)
{
	int		key_count[6];
	t_node	*current;

	if (!initialize_key_count(key_count))
		return (0);
	current = list;
	while (current)
	{
		if (!process_node(current, key_count))
			return (0);
		current = current->next;
	}
	return (check_missing_keys(key_count));
}
