/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 12:03:30 by fmixtur           #+#    #+#             */
/*   Updated: 2025/07/17 12:03:30 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../cub3d.h"

typedef struct s_node	t_node;
typedef struct s_config	t_config;

typedef struct s_indices
{
	int		i;
	int		j;
	int		space;
}	t_indices;

//----parse_color.c----
int				assign_color(t_config *cfg, char *key, char *value);

//----parse_map.c----
void			clean_line(char *line);
int				parse_map(char **array);

//----parse_rgb.c----
int				ft_isdigit_str(char *str);
int				clean_component(char *str);
int				parse_rgb(char *str);
void			free_split(char **arr);

//----parse_texture.c----
int				assign_texture(char **field, char *value);
int				parse_texture_line(t_config *cfg, char *line);

//----parse_spaces_utils.c----
char			*ft_reduce_spaces(char *str);

//----parse_spaces.c----
int				is_space_tab(char c);
int				count_clean_len(char *str);
char			*ft_clean_path(const char *str);

//----parse_validate.c----
int				is_valid_xpm_path(char *path);
int				check_rgb_parts(char **parts);
int				is_valid_rgb(char *str);
int				extract_colors(char **config_lines, t_config *cfg);

//----parsing_utils.c----
void			free_config(t_config *cfg);
void			free_list(t_node *head);
void			trim_newline_from_map(char **map);

//----parsing.c----
int				parse_config_line(t_config *cfg, char *line);
t_config		*parse_config(char **config_lines);

int				extract_texture_by_prefix(char **config_lines,
					char **target_field, const char *prefix);

#endif