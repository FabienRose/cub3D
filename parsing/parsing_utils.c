/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:46:58 by diana             #+#    #+#             */
/*   Updated: 2025/06/23 18:52:59 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

char *ft_strtrim_newline(const char *str)
{
    size_t len;
    char *trimmed;

    if (!str)
        return (NULL);

    len = ft_strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        len--;

    trimmed = malloc(sizeof(char) * (len + 1));
    if (!trimmed)
        return (NULL);

    for (size_t i = 0; i < len; i++)
        trimmed[i] = str[i];
    trimmed[len] = '\0';

    return trimmed;
}
