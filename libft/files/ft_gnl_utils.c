/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:37:35 by kgauthie          #+#    #+#             */
/*   Updated: 2025/03/07 15:21:08 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gnl.h"
#include "stdio.h"

void	gln_clear(char *start, size_t size)
{
	while (size > 0)
	{
		*(start + size - 1) = '\0';
		size--;
	}
}

void	*gln_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;

	if (!dest && !src)
		return (NULL);
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	else
	{
		while ((int)n > 0)
		{
			((char *)dest)[n - 1] = ((char *)src)[n - 1];
			n--;
		}
	}
	return (dest);
}

char	*gln_strjoin(char const *s1, char const *s2, size_t s2max)
{
	size_t	total_size;
	char	*str;

	total_size = gnl_strlen(s1, 0) + gnl_strlen(s2, s2max);
	str = malloc((total_size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	gln_memmove(str, s1, gnl_strlen(s1, 0));
	gln_memmove(str + gnl_strlen(s1, 0), s2, gnl_strlen(s2, s2max));
	str[total_size] = '\0';
	return (str);
}

size_t	gnl_strlen(const char *s, size_t max)
{
	size_t	i;

	i = 0;
	while ((max == 0 || (max > 0 && i < max)) && s[i] && s[i] != '\n')
		i++;
	if ((max == 0 || (max > 0 && i < max)) && s[i] == '\n')
		i++;
	return (i);
}
