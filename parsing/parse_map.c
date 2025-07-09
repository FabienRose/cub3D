/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:58:59 by diana             #+#    #+#             */
/*   Updated: 2025/07/09 21:11:29 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	clean_line(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] != '\n' && line[i] != '\r' && line[i] != '\t')
		{
			line[j] = line[i];
			j++;
		}
		i++;
	}
	line[j] = '\0';
}

static int	process_line_from_string(char *line, t_flags *flags)
{
	if (is_line_empty_or_spaces_only(line))
		return (1);
	clean_line(line);
	if (!check_and_set_flag(line, flags))
	{
		printf("Error: Key not recognized");
		return (0);
	}
	return (1);
}

static int	validate_lines_map(char **array, int start_index)
{
	int	i;

	i = start_index;
	while (array[i])
	{
		if (is_line_empty_or_spaces_only(array[i]))
		{
			i++;
			continue ;
		}
		if (!is_map_line(array[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	process_config_lines(char **array, t_flags *flags)
{
	int	i;

	i = 0;
	while (array[i] && !all_flags_set(flags))
	{
		if (!process_line_from_string(array[i], flags))
			return (0);
		i++;
	}
	if (!all_flags_set(flags))
	{
		printf("Error: Required keys are missing\n");
		return (0);
	}
	return (i);
}

int	parse_map(char **array)
{
	t_flags	flags;
	int		i;

	flags.no = 0;
	flags.so = 0;
	flags.we = 0;
	flags.ea = 0;
	flags.f = 0;
	flags.c = 0;
	i = process_config_lines(array, &flags);
	if (i == 0)
		return (0);
	if (!validate_lines_map(array, i))
		return (0);
	return (1);
}
