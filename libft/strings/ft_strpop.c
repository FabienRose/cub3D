/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:36:15 by kgauthie          #+#    #+#             */
/*   Updated: 2025/04/06 15:09:06 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_strpopat(char **rstr, size_t at)
{
	size_t	offset;
	size_t	pos;
	char	*nstr;
	char	*str;

	str = *rstr;
	if (at >= ft_strlen(str))
		return (FALSE);
	nstr = ft_calloc(sizeof(char), ft_strlen(str) - 1 + 1);
	if (!nstr)
		return (FALSE);
	offset = 0;
	pos = 0;
	while (str[pos])
	{
		if (pos == at)
			offset = 1;
		else
			nstr[pos - offset] = str[pos];
		pos++;
	}
	free(str);
	*rstr = nstr;
	return (TRUE);
}
