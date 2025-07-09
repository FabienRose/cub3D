/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 00:33:15 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/08 00:33:27 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
	if (ft_strncmp(line, "NO ", 3) == 0 && !flags->no)
		return (flags->no = 1, 1);
	if (ft_strncmp(line, "SO ", 3) == 0 && !flags->so)
		return (flags->so = 1, 1);
	if (ft_strncmp(line, "WE ", 3) == 0 && !flags->we)
		return (flags->we = 1, 1);
	if (ft_strncmp(line, "EA ", 3) == 0 && !flags->ea)
		return (flags->ea = 1, 1);
	if (ft_strncmp(line, "F ", 2) == 0 && !flags->f)
		return (flags->f = 1, 1);
	if (ft_strncmp(line, "C ", 2) == 0 && !flags->c)
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

int	is_unrecognized_key(const char *line)
{
	if (!ft_isdigit(line[0]) && line[0] != ' ')
	{
		printf("Unrecognized key: %s\n", line);
		return (1);
	}
	return (0);
}
