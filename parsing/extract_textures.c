/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 12:03:19 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/17 12:03:19 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	extract_texture_by_prefix(char **config_lines, char **target_field,
	const char *prefix)
{
	int		i;
	char	*clean_line;
	char	*clean_path;

	i = 0;
	while (config_lines[i])
	{
		clean_line = ft_reduce_spaces(config_lines[i]);
		if (clean_line && ft_strncmp(clean_line, prefix, 3) == 0)
		{
			clean_path = ft_clean_path(clean_line + 3);
			if (assign_texture(target_field, clean_path) == 0)
			{
				free(clean_path);
				free(clean_line);
				return (0);
			}
			free(clean_path);
		}
		if (clean_line)
			free(clean_line);
		i++;
	}
	return (1);
}
