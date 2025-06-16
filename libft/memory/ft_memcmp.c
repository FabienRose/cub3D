/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:18:04 by kgauthie          #+#    #+#             */
/*   Updated: 2024/10/04 15:47:34 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (((char *)s1)[i] == ((char *)s2)[i]
	&& i < n - 1)
	{
		i++;
	}
	return ((unsigned char)(((char *)s1)[i])
	- (unsigned char)(((char *)s2)[i]));
}
