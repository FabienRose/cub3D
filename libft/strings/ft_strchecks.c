/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchecks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:25:18 by kgauthie          #+#    #+#             */
/*   Updated: 2025/04/06 15:08:19 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_isonlyspace(char *str)
{
	size_t	pos;

	pos = 0;
	while (str[pos])
	{
		if (!ft_isspace(str[pos]))
			return (FALSE);
		pos++;
	}
	return (TRUE);
}
