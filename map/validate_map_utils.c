/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 15:36:56 by diana             #+#    #+#             */
/*   Updated: 2025/07/09 17:17:35 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_first_char_valid(char *line, int *i)
{
	while (line[*i] == ' ' || line[*i] == '\n')
		(*i)++;
	if (line[*i] != '1')
	{
		printf("is_line_closed: first character is not '1' → '%c' \
		(ascii %d)\n", line[*i], line[*i]);
		return (0);
	}
	return (1);
}

int	is_last_char_valid(char *line, int i)
{
	while (i >= 0 && (line[i] == ' ' || line[i] == '\n'))
		i--;
	if (line[i] != '1')
	{
		printf("is_line_closed: last character is not '1' → '%c' \
		(ascii %d)\n", line[i], line[i]);
		return (0);
	}
	return (1);
}

int	is_line_closed(char *line)
{
	int	i;

	if (!line)
	{
		printf("Map line not valid\n");
		return (0);
	}
	i = 0;
	if (!is_first_char_valid(line, &i))
		return (0);
	while (line[i])
		i++;
	if (!is_last_char_valid(line, i - 1))
		return (0);
	return (1);
}

int	has_wall_boundaries(char *line)
{
	int	start;
	int	end;

	start = 0;
	if (!line)
	{
		printf("has_wall_boundaries: line not valid\n");
		return (0);
	}
	while (line[start] == ' ' || line[start] == '\n')
		start++;
	end = start;
	while (line[end])
		end++;
	end--;
	while (end >= 0 && (line[end] == ' ' || line[end] == '\n'))
		end--;
	if (line[start] != '1' || line[end] != '1')
		return (0);
	return (1);
}

int	check_empty_lines(char **map)
{
	int	i;
	int	empty_line_found;

	i = 0;
	empty_line_found = 0;
	while (map[i])
	{
		if (map[i][0] == '\0')
		{
			empty_line_found = 1;
		}
		else if (empty_line_found)
		{
			printf("Error: empty line on the map\n");
			return (0);
		}
		i++;
	}
	return (1);
}
