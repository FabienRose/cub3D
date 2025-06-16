/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:37:55 by kgauthie          #+#    #+#             */
/*   Updated: 2025/04/06 15:15:27 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_strpush(char **str, char c)
{
	size_t	len;

	len = ft_strlen(*str);
	if (!ft_realloc((void **)str, len, len + 2))
		return (FALSE);
	(*str)[len] = c;
	return (TRUE);
}
