/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:13:46 by diana             #+#    #+#             */
/*   Updated: 2025/06/30 10:34:34 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	count_map_lines(char **array, int start)
{
	int	count;

	count = 0;
	while (array[start] && array[start][0] != '\0')
	{
		count++;
		start++;
	}
	return (count);
}

static void	fill_map(char **map, char **array, int start)
{
	int	i;

	i = 0;
	while (array[start] && array[start][0] != '\0')
	{
		map[i] = ft_strdup(array[start]);
		i++;
		start++;
	}
	map[i] = NULL;
}

char	**extract_map(char **array, int start)
{
	int		lines;
	char	**map;

	lines = count_map_lines(array, start);
	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
	{
		ft_putendl_fd("Error: malloc failure", 2);
		return (NULL);
	}
	fill_map(map, array, start);
	return (map);
}
