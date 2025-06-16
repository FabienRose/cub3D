/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:49:25 by kgauthie          #+#    #+#             */
/*   Updated: 2024/10/04 17:55:22 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;

	i = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[i] != '\0'
		&& i < len
		&& ft_strncmp(&(big[i]), little, ft_strlen(little)) != 0)
	{
		if (ft_strlen(little) > (len - i))
			return (NULL);
		i++;
	}
	if (ft_strlen(little) > (len - i))
		return (NULL);
	if (ft_strncmp(&(big[i]), little, ft_strlen(little)) == 0)
		return (&(((char *)big)[i]));
	return (NULL);
}
