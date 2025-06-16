/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 10:37:14 by kgauthie          #+#    #+#             */
/*   Updated: 2024/10/02 11:24:46 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int		i;
	size_t	bytes;

	i = 0;
	bytes = 0;
	while (s[i])
	{
		i++;
		bytes += sizeof(char);
	}
	return (bytes);
}
