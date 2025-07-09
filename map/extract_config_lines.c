/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_config_lines.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 17:21:30 by diana             #+#    #+#             */
/*   Updated: 2025/07/09 14:46:17 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**allocate_config_array(int count)
{
	char	**config;

	config = malloc(sizeof(char *) * (count + 1));
	if (!config)
		return (NULL);
	return (config);
}

void	free_config_on_failure(char **config, int j)
{
	while (j > 0)
		free(config[--j]);
	free(config);
}

char	**fill_config_array(char **config, char **array, int start_index)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!array)
		return (NULL);
	while (i < start_index)
	{
		if (!is_line_empty_or_spaces_only(array[i]))
		{
			config[j] = ft_strdup(array[i]);
			if (!config[j])
			{
				free_config_on_failure(config, j);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	config[j] = NULL;
	return (config);
}

char	**allocate_and_fill_config(char **array, int start_index, int count)
{
	char	**config;

	config = allocate_config_array(count);
	if (!config)
		return (NULL);
	return (fill_config_array(config, array, start_index));
}

char	**extract_config_lines(char **array, int start_index)
{
	int		count;
	char	**config;

	count = count_non_empty_lines(array, start_index);
	config = allocate_and_fill_config(array, start_index, count);
	return (config);
}
