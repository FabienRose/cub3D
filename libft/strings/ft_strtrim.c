/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:16:23 by kgauthie          #+#    #+#             */
/*   Updated: 2024/10/05 16:35:48 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strtrim_is_char(char charin, char const *set)
{
	while (*set != '\0')
	{
		if (charin == *set)
			return (1);
		set++;
	}
	return (0);
}

static size_t	ft_strtrim_get_start(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len && ft_strtrim_is_char(s1[i], set))
		i++;
	return (i);
}

static size_t	ft_strtrim_get_end(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1);
	while (i > 0 && ft_strtrim_is_char(s1[i - 1], set))
		i--;
	return (i - 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*retstr;

	start = ft_strtrim_get_start(s1, set);
	end = ft_strtrim_get_end(s1, set);
	if (start > end)
	{
		retstr = malloc(1 * sizeof(char));
		if (!retstr)
			return (NULL);
		retstr[0] = '\0';
		return (retstr);
	}
	return (ft_substr(s1, start, end - start + 1));
}
