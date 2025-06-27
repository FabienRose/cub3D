/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_key_extension.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:27:27 by diana             #+#    #+#             */
/*   Updated: 2025/06/27 15:03:54 by diana            ###   ########.fr       */
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