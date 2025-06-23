/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 17:21:30 by diana             #+#    #+#             */
/*   Updated: 2025/06/23 18:10:33 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

#include <ctype.h>

int	is_line_empty_or_spaces_only(const char *line)
{
	int	i = 0;

	if (!line)
		return (1);
	while (line[i])
	{
		if (!ft_isspace((unsigned char)line[i]))
			return (0);
		i++;
	}
	return (1);
}


char **extract_config_lines(char **array, int start_index)
{
	char	**config;
	int		count = 0;
	int		i = 0;
	int		j = 0;

	while (i < start_index)
	{
		if (!is_line_empty_or_spaces_only(array[i]))
			count++;
		i++;
	}

	config = malloc(sizeof(char *) * (count + 1));
	if (!config)
		return (NULL);
	i = 0;
	while (i < start_index)
	{
		if (!is_line_empty_or_spaces_only(array[i]))
		{
			config[j] = ft_strdup(array[i]);
			if (!config[j++])
			{
				while (j > 0)
					free(config[--j]);
				free(config);
				return (NULL);
			}
		}
		i++;
	}
	config[j] = NULL;
	return (config);
}
