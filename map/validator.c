/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:14:11 by diana             #+#    #+#             */
/*   Updated: 2025/06/23 17:31:15 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"


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

int	validate_rgb_format(char *line)
{
	char	**parts;
	int		i;
	int		valid;
	char	*trimmed;

	parts = ft_split(line, ',');
	if (!parts)
		return (0);
	i = 0;
	valid = 1;
	while (i < 3)
	{
		if (!parts[i])
		{
			valid = 0;
			break;
		}
		trimmed = ft_strtrim(parts[i], " ");
		if (!trimmed || !is_valid_component(trimmed))
		{
			valid = 0;
			free(trimmed);
			break;
		}
		free(trimmed);
		i++;
	}
	if (parts[3] != NULL)
		valid = 0;
	free_array(parts);
	return (valid);
}


