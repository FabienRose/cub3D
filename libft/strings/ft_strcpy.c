/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:15:21 by kgauthie          #+#    #+#             */
/*   Updated: 2025/04/06 15:08:47 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcpy(char *dst, const char *src)
{
	size_t	pos;

	if (!dst || !src)
		return ;
	pos = 0;
	while (src[pos])
	{
		dst[pos] = src[pos];
		pos++;
	}
	dst[pos] = 0;
}
