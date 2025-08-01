/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 00:58:02 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/21 00:58:02 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	is_valid_component(char *str)
{
	int	i;
	int	val;

	i = 0;
	if (!str || !*str)
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	val = ft_atoi(str);
	if (val < 0 || val > 255)
		return (0);
	return (1);
}
