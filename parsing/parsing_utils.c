/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:46:58 by diana             #+#    #+#             */
/*   Updated: 2025/06/24 09:40:13 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

char *ft_strtrim_right(const char *str)
{
    size_t end;
    char *trimmed;

    if (!str)
        return (NULL);

    end = strlen(str);
    while (end > 0 && ft_isspace((unsigned char)str[end - 1]))
        end--;

    trimmed = malloc(sizeof(char) * (end + 1));
    if (!trimmed)
        return (NULL);

    for (size_t i = 0; i < end; i++)
        trimmed[i] = str[i];
    trimmed[end] = '\0';

    return trimmed;
}

