/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:16:09 by diana             #+#    #+#             */
/*   Updated: 2025/06/25 17:51:10 by diana            ###   ########.fr       */
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
    int floor_color;
    int ceiling_color;
}   t_config;


//----parsing.c----
int             parse_config_line(t_config *cfg, char *line);
int             missing_fields(t_config *cfg);
int	            assign_color(t_config *cfg, char *key, char *value);
t_config	    *parse_config(char **config_lines);
void	        free_config(t_config *cfg);
char            *ft_strjoin_three(char *s1, char *s2, char *s3);

//----parsing_utils.c----
int             is_space_tab(char c);
int             count_clean_len(char *str);
char            *ft_reduce_spaces(char *str);
char	        *ft_clean_path(const char *str);

//----parse_rgb.c----
int             ft_isdigit_str(char *str);
int             clean_component(char *str);
int             parse_rgb(char *str);
void            free_split(char **arr);

//----parse_map.c----
//int             parse_map(t_node *lines);


#endif