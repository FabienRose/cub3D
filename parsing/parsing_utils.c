/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:46:58 by diana             #+#    #+#             */
/*   Updated: 2025/06/24 16:07:23 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

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

char	*ft_reduce_spaces(char *str)
{
	int		i;
	int		j;
	int		space;
	char	*new;

	i = 0;
	j = 0;
	space = 1;
	new = malloc(sizeof(char) * (count_clean_len(str) + 1));
	if (!new)
		return (NULL);
	while (str[i])
	{
		if (!is_space_tab(str[i]))
		{
			new[j++] = str[i];
			space = 0;
		}
		else if (!space)
		{
			new[j++] = ' ';
			space = 1;
		}
		i++;
	}
	if (j > 0 && new[j - 1] == ' ')
		j--;
	new[j] = '\0';
	return (new);
}

char	*ft_clean_path(const char *str)
{
	char	*clean;
	int		i = 0;

	clean = malloc(ft_strlen(str) + 1); // suficiente espacio
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
