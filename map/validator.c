/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:14:11 by diana             #+#    #+#             */
/*   Updated: 2025/06/23 15:38:20 by diana            ###   ########.fr       */
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
	int		valid;

	parts = ft_split(line, ',');
	if (!parts)
		return (0);
	if (!parts[0] || !parts[1] || !parts[2] || parts[3] != NULL)
	{
		free_array(parts);
		return (0);
	}
	valid = (is_valid_component(parts[0])
		&& is_valid_component(parts[1])
		&& is_valid_component(parts[2]));
	printf("Validando línea RGB: [%s]\n", line);
	free_array(parts);
	return (valid);
}


