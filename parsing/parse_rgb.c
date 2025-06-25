/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:37:35 by diana             #+#    #+#             */
/*   Updated: 2025/06/24 20:01:04 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

int	ft_isdigit_str(char *str)
{
	if (!str || *str == '\0')
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	clean_component(char *str)
{
	char	*trimmed;
	int		value;

	trimmed = ft_strtrim(str, " \t\n\r\v\f");
	if (!trimmed)
		return (-1);
	if (!ft_isdigit_str(trimmed)) // asegúrate de que no hay letras, signos, etc.
	{
		free(trimmed);
		return (-1);
	}
	value = ft_atoi(trimmed);
	free(trimmed);
	if (value < 0 || value > 255)
		return (-1);
	return (value);
}


int	parse_rgb(char *str)
{
	char	**components;
	int		r, g, b;
	int		result;

	components = ft_split(str, ',');
	if (!components)
		return (-1);
	// Deben ser exactamente 3 componentes
	if (!components[0] || !components[1] || !components[2] || components[3])
	{
		free_split(components);
		return (-1);
	}
	r = clean_component(components[0]);
	g = clean_component(components[1]);
	b = clean_component(components[2]);
	free_split(components);
	if (r == -1 || g == -1 || b == -1)
		return (-1);
	result = (r << 16) | (g << 8) | b;
	return result;
}

void	free_split(char **arr)
{
	int	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
