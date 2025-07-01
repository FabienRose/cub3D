/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:16:09 by diana             #+#    #+#             */
/*   Updated: 2025/07/01 15:23:38 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct s_config
{
	char	*no_texture;
	char	*so_texture;
	char	*ea_texture;
	char	*we_texture;
	int		floor_color;
	int		ceiling_color;
}	t_config;

typedef struct s_indices
{
	int	i;
	int	j;
	int	space;
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

//----parsing_utils.c----
void			free_config(t_config *cfg);
char			*ft_strjoin_three(char *s1, char *s2, char *s3);
int				missing_fields(t_config *cfg);
void			free_list(t_node *head);
void			trim_newline_from_map(char **map);

//----parsing.c----
int				parse_config_line(t_config *cfg, char *line);
t_config		*parse_config(char **config_lines);
void			free_config(t_config *cfg);

#endif