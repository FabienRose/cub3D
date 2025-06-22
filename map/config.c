/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 17:21:30 by diana             #+#    #+#             */
/*   Updated: 2025/06/22 17:22:36 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

char **extract_config_lines(char **array, int start_index)
{
    char **config;
    int count = 0;
    int i = 0;

    while (i < start_index)
    {
        if (array[i][0] != '\0' && array[i][0] != '\n')
            count++;
        i++;
    }

    config = malloc(sizeof(char *) * (count + 1));
    if (!config)
        return (NULL);

    i = 0;
    int j = 0;
    while (i < start_index)
    {
        if (array[i][0] != '\0' && array[i][0] != '\n')
        {
            config[j] = strdup(array[i]);
            if (!config[j++])
            {
                while (j > 0)
                    free(config[--j]);
                free(config);
                return (NULL);
            }
        }
        i++;
    }
    config[j] = NULL;
    return config;
}
