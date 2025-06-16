/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraylen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:39:05 by fmixtur           #+#    #+#             */
/*   Updated: 2025/04/09 19:44:56 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_arraylen(void *arr, size_t size)
{
	size_t	pos;
	char	*carr;

	pos = 0;
	carr = (char *)arr;
	while (carr[pos])
		pos++;
	return (pos / size);
}

size_t	ft_arraylen_d(void **arr)
{
	size_t	pos;

	pos = 0;
	while (arr[pos])
		pos++;
	return (pos);
}
