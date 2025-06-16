/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:20:30 by kgauthie          #+#    #+#             */
/*   Updated: 2024/10/04 18:26:53 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*rets;

	len = ft_strlen(s);
	rets = ft_calloc(len + 1, sizeof(char));
	if (!rets)
		return (NULL);
	ft_strlcpy(rets, s, len + 1);
	return (rets);
}
