/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:16:09 by diana             #+#    #+#             */
/*   Updated: 2025/06/24 16:07:54 by diana            ###   ########.fr       */
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
int             parse_config_line(t_config *cfg, char *line);
int             missing_fields(t_config *cfg);
t_config	    *parse_config(char **config_lines);
void	        free_config(t_config *cfg);

//----parsing_utils.c----
int             is_space_tab(char c);
int             count_clean_len(char *str);
char            *ft_reduce_spaces(char *str);
char	        *ft_clean_path(const char *str);


#endif