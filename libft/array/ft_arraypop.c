/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraypop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 09:38:26 by kgauthie          #+#    #+#             */
/*   Updated: 2025/04/06 15:23:48 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_arraypopat_d_loop(void **c_arr, void **n_arr, size_t pos)
{
	size_t	offset;
	size_t	i;

	i = 0;
	offset = 0;
	if (pos == 0)
	{
		i++;
		offset = 1;
	}
	while (c_arr[i])
	{
		n_arr[i - offset] = c_arr[i];
		i++;
		if (i == pos)
		{
			i++;
			offset = 1;
		}
	}
}

void	*ft_arraypopat_d(void ***arr, size_t pos)
{
	void	**c_arr;
	void	**n_arr;
	void	*ret;

	if (!arr || !(*arr)
		|| ft_arraylen_d(*arr) == 0
		|| pos >= ft_arraylen_d(*arr))
		return (NULL);
	c_arr = *arr;
	ret = c_arr[pos];
	n_arr = ft_calloc(sizeof(void *), ft_arraylen_d(*arr));
	if (!n_arr)
		return (NULL);
	ft_arraypopat_d_loop(c_arr, n_arr, pos);
	free(c_arr);
	*arr = n_arr;
	return (ret);
}

void	*ft_arraypopfront_d(void ***arr)
{
	void	**c_arr;
	void	**n_arr;
	void	*ret;
	size_t	current_len;
	size_t	pos;

	if (!arr || !(*arr) || ft_arraylen_d(*arr) == 0)
		return (NULL);
	current_len = ft_arraylen_d(*arr);
	c_arr = *arr;
	ret = c_arr[0];
	n_arr = ft_calloc(sizeof(void *), current_len);
	if (!n_arr)
		return (NULL);
	pos = 1;
	while (c_arr[pos])
	{
		n_arr[pos - 1] = c_arr[pos];
		pos++;
	}
	free(c_arr);
	*arr = n_arr;
	return (ret);
}
