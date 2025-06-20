/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:16:09 by diana             #+#    #+#             */
/*   Updated: 2025/06/20 17:41:47 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../map/map.h"

//----parsing.c----
int			parse_config_line(char *line, t_map_config *config);
int			parse_map(int fd, char *first_line, t_map_config *config);

//----parsing_utils.c----
int			parse_color(char *str, t_color *color);
void		free_split(char **arr);


#endif