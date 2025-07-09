/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_spaces_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:20:31 by diana             #+#    #+#             */
/*   Updated: 2025/07/09 17:18:42 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	*initialize_and_allocate(char *str, int *i, int *j, int *space)
{
	char	*new;

	*i = 0;
	*j = 0;
	*space = 1;
	new = malloc(sizeof(char) * (count_clean_len(str) + 1));
	if (!new)
		return (NULL);
	return (new);
}

static char	*finalize_string(char *new, int j)
{
	if (j > 0 && new[j - 1] == ' ')
		j--;
	new[j] = '\0';
	return (new);
}

static void	process_string(char *str, char *new, t_indices *indices)
{
	while (str[indices->i])
	{
		if (!is_space_tab(str[indices->i]))
		{
			new[indices->j] = str[indices->i];
			(indices->j)++;
			indices->space = 0;
		}
		else if (!(indices->space))
		{
			new[indices->j] = ' ';
			(indices->j)++;
			indices->space = 1;
		}
		(indices->i)++;
	}
}

char	*ft_reduce_spaces(char *str)
{
	t_indices	indices;
	char		*new;

	new = initialize_and_allocate(str, &indices.i, &indices.j, &indices.space);
	if (!new)
		return (NULL);
	process_string(str, new, &indices);
	return (finalize_string(new, indices.j));
}
