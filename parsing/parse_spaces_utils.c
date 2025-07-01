/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_spaces_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:20:31 by diana             #+#    #+#             */
/*   Updated: 2025/07/01 15:32:44 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	*initialize_and_allocate(char *str, int *i, int *j, int *space)
{
	char	*new;

	*i = 0;
	*j = 0;
	*space = 1;
	new = malloc(sizeof(char) * (count_clean_len(str) + 1));
	if (!new)
		return (NULL);
	return (new);
}

static char	*finalize_string(char *new, int j)
{
	if (j > 0 && new[j - 1] == ' ')
		j--;
	new[j] = '\0';
	return (new);
}

static void	process_string(char *str, char *new, t_indices *indices)
{
	while (str[indices->i])
	{
		if (!is_space_tab(str[indices->i]))
		{
			new[indices->j] = str[indices->i];
			(indices->j)++;
			indices->space = 0;
		}
		else if (!(indices->space))
		{
			new[indices->j] = ' ';
			(indices->j)++;
			indices->space = 1;
		}
		(indices->i)++;
	}
}

char	*ft_reduce_spaces(char *str)
{
	t_indices	indices;
	char		*new;

	new = initialize_and_allocate(str, &indices.i, &indices.j, &indices.space);
	if (!new)
		return (NULL);
	process_string(str, new, &indices);
	return (finalize_string(new, indices.j));
}

/*
static char	*initialize_and_allocate(char *str, int *i, int *j, int *space)
{
	char	*new;

	*i = 0;
	*j = 0;
	*space = 1;
	new = malloc(sizeof(char) * (count_clean_len(str) + 1));
	if (!new)
		return (NULL);
	return (new);
}

static char	*finalize_string(char *new, int j)
{
	if (j > 0 && new[j - 1] == ' ')
		j--;
	new[j] = '\0';
	return (new);
}

//primera version process string
static void process_string(char *str, char *new, int *i, int *j, int *space)
{
    while (str[*i])
    {
        if (!is_space_tab(str[*i]))
        {
            new[*j] = str[*i];
            (*j)++;
            *space = 0;
        }
        else if (!(*space))
        {
            new[*j] = ' ';
            (*j)++;
            *space = 1;
        }
        (*i)++;
    }
}*/

/*version modificada
static void	process_string(char *str, char *new, t_indices *indices)
{
	while (str[indices->i])
	{
		if (!is_space_tab(str[indices->i]))
		{
			new[indices->j] = str[indices->i];
			(indices->j)++;
			indices->space = 0;
		}
		else if (!(indices->space))
		{
			new[indices->j] = ' ';
			(indices->j)++;
			indices->space = 1;
		}
		(indices->i)++;
	}
}*/
/*//primer version que ya no se adecua al resto
char *ft_reduce_spaces(char *str)
{
    int i;
    int j;
    int space;
    char *new;

    new = initialize_and_allocate(str, &i, &j, &space);
    if (!new)
        return (NULL);

    process_string(str, new, &i, &j, &space);

    return (finalize_string(new, j));
}*/

/* segunda version
char	*ft_reduce_spaces(char *str)
{
	t_indices	indices;
	char		*new;

	indices.i = 0;
	indices.j = 0;
	indices.space = 1;
	new = malloc(sizeof(char) * (count_clean_len(str) + 1));
	if (!new)
		return (NULL);
	process_string(str, new, &indices);
	if (indices.j > 0 && new[indices.j - 1] == ' ')
		indices.j--;
	new[indices.j] = '\0';
	return (new);
}
*/