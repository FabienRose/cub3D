/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:20:07 by kgauthie          #+#    #+#             */
/*   Updated: 2025/04/06 15:15:54 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strinsert_loop(char *n_str, char *str, size_t at, char c)
{
	size_t	offset;
	size_t	pos;

	pos = 0;
	offset = 0;
	while (str[pos])
	{
		if (pos == at)
		{
			n_str[pos + offset] = c;
			offset++;
		}
		n_str[pos + offset] = str[pos];
		pos++;
	}
	if (pos == at)
		n_str[pos + offset] = c;
}

t_bool	ft_strinsert(char **p_str, size_t at, char c)
{
	char	*str;
	char	*n_str;

	str = *p_str;
	if (!str || at > ft_strlen(str))
		return (FALSE);
	n_str = ft_calloc(sizeof(char), ft_strlen(str) + 1 + 1);
	if (!n_str)
		return (FALSE);
	ft_strinsert_loop(n_str, str, at, c);
	free(str);
	*p_str = n_str;
	return (TRUE);
}
