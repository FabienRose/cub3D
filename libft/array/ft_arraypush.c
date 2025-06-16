/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraypush.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:01:45 by fmixtur           #+#    #+#             */
/*   Updated: 2025/04/06 15:25:20 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_arraypush(void **arr, size_t size)
{
	char	*carr;
	size_t	len;

	carr = (char *)(*arr);
	len = ft_arraylen(*arr, size);
	if (!ft_realloc_s(arr, len, len + 2, size))
		return (NULL);
	return ((void *)(&(carr[len * size])));
}

t_bool	ft_arraypush_d(void ***arr, void *ndata)
{
	size_t	len;

	len = ft_arraylen_d(*arr);
	if (!ft_realloc_da(arr, len, len + 2))
		return (FALSE);
	(*arr)[len] = ndata;
	return (TRUE);
}

t_bool	ft_arraypush_df(void ***arr, void *(*create)(void), void(*del)(void *))
{
	void	*ndata;

	ndata = (*create)();
	if (!ndata)
		return (FALSE);
	if (!ft_arraypush_d(arr, ndata))
	{
		(*del)(ndata);
		return (FALSE);
	}
	return (TRUE);
}
