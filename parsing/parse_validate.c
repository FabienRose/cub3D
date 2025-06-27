/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:45:35 by diana             #+#    #+#             */
/*   Updated: 2025/06/27 19:29:51 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int is_valid_xpm_path(char *path)
{
    int len;

    if (!path)
        return (0);
    len = ft_strlen(path);
    if (len < 5)
        return (0);
    return (ft_strncmp(path + len - 4, ".xpm", 4) == 0);
}

int check_rgb_parts(char **parts)
{
    int i;
    int value;

    for (i = 0; i < 3; i++)
    {
        if (!parts[i])
            return (0);
        value = ft_atoi(parts[i]);
        if (value < 0 || value > 255)
            return (0);
    }
    if (parts[3])
        return (0);
    return (1);
}

int is_valid_rgb(char *str)
{
    char **parts;
    int result;

    if (!str)
        return (0);
    parts = ft_split(str, ',');
    if (!parts)
        return (0);
    result = check_rgb_parts(parts);
    free_array(parts);
    return (result);
}

