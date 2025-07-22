/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_rectangular.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diramire <diramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:05:10 by diana             #+#    #+#             */
/*   Updated: 2025/07/22 11:39:51 by diramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	validate_rectangular_map(char **map)
{
	int	i;
	int	first_len;
	int	current_len;

	if (!map || !map[0])
		return (0);
	first_len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		current_len = ft_strlen(map[i]);
		if (current_len != first_len)
		{
			printf("Error: Line %d has length %d, expected %d\n", \
i, current_len, first_len);
			return (0);
		}
		i++;
	}
	return (1);
}
