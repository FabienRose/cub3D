/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:13:04 by diana             #+#    #+#             */
/*   Updated: 2025/06/20 17:42:03 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	check_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	if (ft_strncmp(filename + len - 4, ".cub", 4) != 0)
		return (0);
	return (1);
} 

char	**load_cub_file(char *filename)
{
	if (!check_extension(filename))
	{
		ft_putstr_fd("Error: The file doesn't have a extension .cub\n", 2);
		return (NULL);
	}
	return (read_file_lines(filename));
} 

