/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:16:09 by diana             #+#    #+#             */
/*   Updated: 2025/06/23 12:55:33 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct s_config
{
    char *no_texture;
    char *so_texture;
    char *ea_texture;
    char *we_texture;
    char *floor_color;
    char *ceiling_color;
}   t_config;



//----parsing.c----
t_config		*parse_config(char **config_lines);
int             parse_config_line(t_config *cfg, char *line);
int             missing_fields(t_config *cfg);
t_config	    *parse_config(char **lines);
//int			parse_config_line(char *line, t_map_config *config);
//int			parse_map(int fd, char *first_line, t_map_config *config);

//----parsing_utils.c----
//int			parse_color(char *str, t_color *color);
//void		free_split(char **arr);



#endif