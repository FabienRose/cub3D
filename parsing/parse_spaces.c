/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:07:21 by diana             #+#    #+#             */
/*   Updated: 2025/07/01 13:21:06 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_space_tab(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	count_clean_len(char *str)
{
	int	i;
	int	len;
	int	space;

	i = 0;
	len = 0;
	space = 1;
	while (str[i])
	{
		if (!is_space_tab(str[i]))
		{
			len++;
			space = 0;
		}
		else if (!space)
		{
			len++;
			space = 1;
		}
		i++;
	}
	if (len > 0 && space)
		len--;
	return (len);
}

char	*ft_clean_path(const char *str)
{
	char	*clean;
	int		i;

	i = 0;
	clean = malloc(ft_strlen(str) + 1);
	if (!clean)
		return (NULL);
	while (*str)
	{
		if (*str != ' ')
			clean[i++] = *str;
		str++;
	}
	clean[i] = '\0';
	return (clean);
}
