/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:38:44 by kgauthie          #+#    #+#             */
/*   Updated: 2025/04/05 15:27:42 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gnl.h"

int	gnl_check_buffer(char *buffer, char **str)
{
	char	*nstr;

	nstr = gln_strjoin(*str, buffer, BUFFER_SIZE);
	free(*str);
	if (!nstr)
		return (-1);
	*str = nstr;
	if (gnl_strlen(*str, 0) > 0 && (*str)[gnl_strlen(*str, 0) - 1] == '\n' )
		return (1);
	return (0);
}

void	gln_finish_line(char *buffer)
{
	size_t	buf_len;

	buf_len = gnl_strlen(buffer, BUFFER_SIZE);
	if (buf_len == BUFFER_SIZE)
	{
		gln_clear(buffer, BUFFER_SIZE);
	}
	else
	{
		gln_memmove(buffer, buffer + (buf_len), BUFFER_SIZE - buf_len);
		buffer[BUFFER_SIZE - buf_len] = '\0';
	}
}

char	*ft_gnl(int fd)
{
	static char	buffer[MAX_FD][BUFFER_SIZE];
	char		*retstr;
	size_t		rsize;

	if (fd >= MAX_FD || fd < 0)
		return (NULL);
	retstr = (char *)malloc(sizeof(char) * 1);
	if (!retstr)
		return (NULL);
	retstr[0] = '\0';
	while (gnl_check_buffer(buffer[fd], &retstr) == 0)
	{
		rsize = read(fd, buffer[fd], BUFFER_SIZE);
		gln_clear(buffer[fd] + rsize, BUFFER_SIZE - rsize);
		if ((rsize == 0 && gnl_strlen(retstr, 0) == 0) || rsize > BUFFER_SIZE)
		{
			free(retstr);
			return (NULL);
		}
		else if (rsize == 0)
			return (retstr);
	}
	gln_finish_line(buffer[fd]);
	return (retstr);
}
