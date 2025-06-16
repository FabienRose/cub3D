/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:43:49 by kgauthie          #+#    #+#             */
/*   Updated: 2025/04/06 15:15:12 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

t_bool	ft_strmerge(char **bstr, const char *str1,
	const char *str2, const char *str3)
{
	if (!(*bstr))
		return (FALSE);
	if (str1)
	{
		if (!ft_realloc((void **)bstr, ft_strlen(*bstr),
				ft_strlen(*bstr) + ft_strlen(str1) + 1))
			return (FALSE);
		ft_strcpy(&((*bstr)[ft_strlen(*bstr)]), str1);
	}
	if (str2)
	{
		if (!ft_realloc((void **)bstr, ft_strlen(*bstr),
				ft_strlen(*bstr) + ft_strlen(str2) + 1))
			return (FALSE);
		ft_strcpy(&((*bstr)[ft_strlen(*bstr)]), str2);
	}
	if (str3)
	{
		if (!ft_realloc((void **)bstr, ft_strlen(*bstr),
				ft_strlen(*bstr) + ft_strlen(str3) + 1))
			return (FALSE);
		ft_strcpy(&((*bstr)[ft_strlen(*bstr)]), str3);
	}
	return (TRUE);
}
