/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:22:58 by kgauthie          #+#    #+#             */
/*   Updated: 2024/10/04 18:08:02 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_atoi_isspace(char char_in)
{
	if (char_in == ' ' || char_in == '\f'
		|| char_in == '\n' || char_in == '\r'
		|| char_in == '\t' || char_in == '\v')
		return (1);
	return (0);
}

static long long int	ft_atoi_next(long long int result,
	const char *nptr,
	int pos)
{
	if (ft_isdigit(nptr[pos]))
	{
		result *= 10;
		result += nptr[pos] - 48;
		result = ft_atoi_next(result, nptr, pos + 1);
	}
	return (result);
}

int	ft_atoi(const char *nptr)
{
	int				i;
	int				sign;
	long long int	result;

	i = 0;
	sign = 1;
	while (ft_atoi_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	result = 0;
	result = ft_atoi_next(result, nptr, i);
	return ((int)(result * sign));
}
