/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:38:37 by kgauthie          #+#    #+#             */
/*   Updated: 2025/04/06 15:09:28 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_split_cw(char const *s, char c)
{
	size_t	count;
	size_t	pos;

	count = 0;
	pos = 0;
	while (s[pos] != '\0')
	{
		if (s[pos] == c && pos > 0 && s[pos - 1] != c)
			count++;
		pos++;
	}
	if (pos > 0 && s[pos - 1] != c)
		count++;
	return (count);
}

static char	**ft_split_sub(char **final_str, char const *s, char c)
{
	size_t	pos;
	size_t	prev_pos;
	size_t	count;

	pos = 0;
	prev_pos = 0;
	count = 0;
	while (s[pos] != '\0')
	{
		if (s[pos] == c)
		{
			if (pos > 0 && s[pos - 1] != c)
				final_str[count++] = ft_substr(s, prev_pos, pos - prev_pos);
			prev_pos = pos + 1;
		}
		pos++;
	}
	if (pos > 0 && s[pos - 1] != c)
	{
		final_str[count] = ft_substr(s, prev_pos, pos - prev_pos);
		count++;
	}
	return (final_str);
}

void	ft_split_release(char	***arr)
{
	size_t	pos;

	pos = 0;
	if (!arr || !(*arr))
		return ;
	while ((*arr)[pos])
	{
		free((*arr)[pos]);
		(*arr)[pos] = NULL;
		pos++;
	}
	free(*arr);
	*arr = NULL;
}

static char	**ft_split_final(char **final_str, size_t wc)
{
	size_t	pos;

	pos = 0;
	while (pos < wc)
	{
		if (!final_str[pos])
		{
			ft_split_release(&final_str);
			return (NULL);
		}
		pos++;
	}
	final_str[wc] = NULL;
	return (final_str);
}

char	**ft_split(char const *s, char c)
{
	size_t	wc;
	char	**final_str;

	wc = ft_split_cw(s, c);
	final_str = ft_calloc(wc + 1, sizeof(char *));
	if (!final_str)
		return (NULL);
	final_str = ft_split_sub(final_str, s, c);
	return (ft_split_final(final_str, wc));
}
