/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:46:58 by diana             #+#    #+#             */
/*   Updated: 2025/07/01 13:36:16 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_config(t_config *cfg)
{
	if (!cfg)
		return ;
	if (cfg->no_texture)
		free(cfg->no_texture);
	if (cfg->so_texture)
		free(cfg->so_texture);
	if (cfg->we_texture)
		free(cfg->we_texture);
	if (cfg->ea_texture)
		free(cfg->ea_texture);
	free(cfg);
}



void	free_list(t_node *head)
{
	t_node	*tmp;

	while (head)
	{
		tmp = head->next;
		if (head->line)
			free(head->line);
		free(head);
		head = tmp;
	}
}

void	trim_newline_from_map(char **map)
{
	int	i;
	int	len;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > 0 && (map[i][len - 1] == '\n' || map[i][len - 1] == '\r'))
			map[i][len - 1] = '\0';
		len--;
		if (len > 0 && (map[i][len - 1] == '\n' || map[i][len - 1] == '\r'))
			map[i][len - 1] = '\0';
		i++;
	}
}
