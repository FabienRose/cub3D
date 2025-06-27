/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_key_extension.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:27:27 by diana             #+#    #+#             */
/*   Updated: 2025/06/27 19:18:58 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

int	ends_with_cub(const char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	return (ft_strncmp(filename + len - 4, ".cub", 4) == 0);
}

int	check_and_set_flag(const char *line, t_flags *flags)
{
	while (*line == ' ' || *line == '\t')
		line++;

	if (strncmp(line, "NO ", 3) == 0 && !flags->no)
		return (flags->no = 1, 1);
	if (strncmp(line, "SO ", 3) == 0 && !flags->so)
		return (flags->so = 1, 1);
	if (strncmp(line, "WE ", 3) == 0 && !flags->we)
		return (flags->we = 1, 1);
	if (strncmp(line, "EA ", 3) == 0 && !flags->ea)
		return (flags->ea = 1, 1);
	if (strncmp(line, "F ", 2) == 0 && !flags->f)
		return (flags->f = 1, 1);
	if (strncmp(line, "C ", 2) == 0 && !flags->c)
		return (flags->c = 1, 1);
	return (0);
}

int	all_flags_set(t_flags *flags)
{
	return (flags->no && flags->so && flags->we && flags->ea
		&& flags->f && flags->c);
}

int	is_valid_key(const char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (1);
	if (ft_strncmp(line, "SO ", 3) == 0)
		return (2);
	if (ft_strncmp(line, "WE ", 3) == 0)
		return (3);
	if (ft_strncmp(line, "EA ", 3) == 0)
		return (4);
	if (ft_strncmp(line, "F ", 2) == 0)
		return (5);
	if (ft_strncmp(line, "C ", 2) == 0)
		return (6);
	return (0);
}

int	validate_unique_keys(t_node *list)
{
	int		key_count[6] = {0};
	t_node	*current = list;
	int		key_index;

	while (current)
	{
		if (!is_line_empty_or_spaces_only(current->line))
		{
			key_index = is_valid_key(current->line);
			if (key_index > 0)
			{
				key_count[key_index - 1]++;
				if (key_count[key_index - 1] > 1)
				{
					printf("Clave duplicada: %s\n", current->line);
					return (0);
				}
			}
			else if (!ft_isdigit(current->line[0]) && current->line[0] != ' ')
			{
				printf("Clave no reconocida: %s\n", current->line);
				return (0);
			}
		}
		current = current->next;
	}

	for (int i = 0; i < 6; i++)
	{
		if (key_count[i] == 0)
		{
			printf("Falta clave %d\n", i + 1);
			return (0);
		}
	}
	return (1);
}
