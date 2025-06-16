/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayfree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:21:18 by fmixtur           #+#    #+#             */
/*   Updated: 2025/04/06 15:19:06 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arrayfree(void **arr)
{
	if (*arr)
	{
		free(*arr);
		*arr = NULL;
	}
}

void	ft_arrayfree_d(void ***arr, void (*del)(void *))
{
	void	**carr;
	size_t	pos;

	carr = *arr;
	pos = 0;
	if (!carr)
		return ;
	while (carr[pos])
	{
		(*del)(carr[pos]);
		carr[pos] = NULL;
		pos++;
	}
	free(carr);
	*arr = NULL;
}
