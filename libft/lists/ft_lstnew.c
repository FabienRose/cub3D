/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgauthie <kgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 08:35:16 by kgauthie          #+#    #+#             */
/*   Updated: 2025/01/20 17:16:01 by kgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*n_list;

	n_list = malloc(sizeof(t_list));
	if (!n_list)
		return (NULL);
	n_list->content = content;
	n_list->next = NULL;
	return (n_list);
}
