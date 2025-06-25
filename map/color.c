/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:14:11 by diana             #+#    #+#             */
/*   Updated: 2025/06/24 20:04:37 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

static int ft_is_whitespace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' ||
            c == '\r' || c == '\v' || c == '\f');
}

char *ft_strtrim_whitespace(const char *s)
{
    size_t start = 0;
    size_t end;

    if (!s)
        return NULL;
    end = strlen(s);

    while (s[start] && ft_is_whitespace(s[start]))
        start++;
    while (end > start && ft_is_whitespace(s[end - 1]))
        end--;
    size_t len = end - start;
    char *trimmed = (char *)malloc(len + 1);
    if (!trimmed)
        return NULL;

    memcpy(trimmed, s + start, len);
    trimmed[len] = '\0';
    return trimmed;
}

int is_valid_component(char *str)
{
	int	i;
	int	val;

	i = 0;
	if (!str || !*str)
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	val = ft_atoi(str);
	if (val < 0 || val > 255)
		return (0);
	return (1);
}

int	validate_rgb_format(char *line)
{
	char	**parts;
	int		i;
	int		valid;
	char	*trimmed_part;

	parts = ft_split(line, ',');
	if (!parts)
		return (0);
	i = 0;
	valid = 1;
	while (i < 3)
	{
		if (!parts[i])
		{
			valid = 0;
			break;
		}
		trimmed_part = ft_strtrim_whitespace(parts[i]);
		if (!trimmed_part || !is_valid_component(trimmed_part))
		{
			valid = 0;
			free(trimmed_part);
			break;
		}
		free(trimmed_part);
		i++;
	}
	if (parts[3] != NULL)
		valid = 0;
	free_array(parts);
	return (valid);
}

int rgb_to_int(char *rgb_str)
{
	char **parts;
	char *trimmed_part;
	int r, g, b;

	parts = ft_split(rgb_str, ',');
	if (!parts)
		return (-1);

	trimmed_part = ft_strtrim_whitespace(parts[0]);
	if (!trimmed_part)
	{
		free_array(parts);
		return (-1);
	}
	r = ft_atoi(trimmed_part);
	free(trimmed_part);

	trimmed_part = ft_strtrim_whitespace(parts[1]);
	if (!trimmed_part)
	{
		free_array(parts);
		return (-1);
	}
	g = ft_atoi(trimmed_part);
	free(trimmed_part);

	trimmed_part = ft_strtrim_whitespace(parts[2]);
	if (!trimmed_part)
	{
		free_array(parts);
		return (-1);
	}
	b = ft_atoi(trimmed_part);
	free(trimmed_part);

	free_array(parts);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	return ((r << 16) | (g << 8) | b);
}
