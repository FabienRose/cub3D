/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:01:59 by fmixtur           #+#    #+#             */
/*   Updated: 2025/03/27 16:34:39 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*retptr;

	retptr = malloc(nmemb * size);
	if (!retptr)
		return (NULL);
	ft_bzero(retptr, nmemb * size);
	return (retptr);
}
