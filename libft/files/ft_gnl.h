/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:29:03 by kgauthie          #+#    #+#             */
/*   Updated: 2025/04/06 15:16:55 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GNL_H
# define FT_GNL_H

# include "stdlib.h"
# include "unistd.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

# define MAX_FD 1024

void	gln_clear(char *start, size_t size);
void	*gln_memmove(void *dest, const void *src, size_t n);
char	*gln_strjoin(char const *s1, char const *s2, size_t s2max);
size_t	gnl_strlen(const char *s, size_t max);

void	gln_finish_line(char *buffer);
int		gnl_check_buffer(char *buffer, char **str);

#endif