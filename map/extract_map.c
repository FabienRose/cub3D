/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:13:46 by diana             #+#    #+#             */
/*   Updated: 2025/06/22 17:05:57 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

char **extract_map(char **array, int start_index)
{
    int i = 0;
    int map_lines = 0;

    while (array[start_index + map_lines])
        map_lines++;

    char **map = malloc(sizeof(char *) * (map_lines + 1));
    if (!map)
        return (NULL);

    while (i < map_lines)
    {
        map[i] = ft_strdup(array[start_index + i]);
        if (!map[i])
        {
            while (i > 0)
                free(map[--i]);
            free(map);
            return (NULL);
        }
        i++;
    }
    map[i] = NULL;
    return map;
}
