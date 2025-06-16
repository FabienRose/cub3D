/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:50:07 by kgauthie          #+#    #+#             */
/*   Updated: 2024/10/05 18:22:35 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_itoa_getsize(int n)
{
	size_t	size;
	int		sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	size = 0;
	while (n)
	{
		size++;
		n /= 10;
	}
	if (size == 0)
		size++;
	if (sign == -1)
		size++;
	return (size);
}

char	*ft_itoa(int n)
{
	size_t			count;
	char			*finalnbr;
	size_t			pos;
	long long int	ln;

	count = ft_itoa_getsize(n);
	finalnbr = malloc((count + 1) * sizeof(char));
	if (!finalnbr)
		return (NULL);
	if (n == 0)
		finalnbr[0] = '0';
	ln = n;
	if (ln < 0)
	{
		finalnbr[0] = '-';
		ln *= -1;
	}
	pos = count;
	finalnbr[pos--] = '\0';
	while (ln)
	{
		finalnbr[pos--] = '0' + (ln % 10);
		ln /= 10;
	}
	return (finalnbr);
}
