/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:46:58 by diana             #+#    #+#             */
/*   Updated: 2025/06/20 17:41:26 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parse_color(char *str, t_color *color)
{
	char	**components = ft_split(str, ',');
	if (!components || !components[0] || !components[1] || !components[2])
		return (0);
	color->r = ft_atoi(components[0]);
	color->g = ft_atoi(components[1]);
	color->b = ft_atoi(components[2]);

	free_split(components);
	return (1);
}

void	free_split(char **arr)
{
	int i = 0;
	while (arr && arr[i])
		free(arr[i++]);
	free(arr);
}
