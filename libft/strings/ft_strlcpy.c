/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:21:40 by kgauthie          #+#    #+#             */
/*   Updated: 2024/10/02 17:03:35 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	if (size == 0)
		return ((ft_strlen(src)));
	i = 0;
	while (i < size - 1)
	{
		dst[i] = src[i];
		if (src[i] == '\0')
		{
			return (ft_strlen(src));
		}
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
