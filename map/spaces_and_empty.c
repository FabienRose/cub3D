/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaces_and_empty.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diramire <diramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:14:28 by diana             #+#    #+#             */
/*   Updated: 2025/07/22 11:34:48 by diramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_line_empty_or_spaces_only(const char *line)
{
	int	i;

	i = 0;
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

int	count_non_empty_lines(char **array, int start_index)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < start_index)
	{
		if (!is_line_empty_or_spaces_only(array[i]))
			count++;
		i++;
	}
	return (count);
}

static int	ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || \
c == '\r' || c == '\v' || c == '\f');
}

char	*ft_strtrim_whitespace(const char *s)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*trimmed;

	start = 0;
	if (!s)
		return (NULL);
	end = ft_strlen(s);
	while (s[start] && ft_is_whitespace(s[start]))
		start++;
	while (end > start && ft_is_whitespace(s[end - 1]))
		end--;
	len = end - start;
	trimmed = (char *)malloc(len + 1);
	if (!trimmed)
		return (NULL);
	ft_memcpy(trimmed, s + start, len);
	trimmed[len] = '\0';
	return (trimmed);
}
