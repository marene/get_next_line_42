/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:17:18 by marene            #+#    #+#             */
/*   Updated: 2013/11/30 14:01:29 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_wcount(const char *s, char c)
{
	size_t	i;
	size_t	w_nb;
	char	prev;

	if (s[0] == c)
		w_nb = 0;
	else
		w_nb = 1;
	i = 1;
	prev = s[0];
	while (s[i])
	{
		if (s[i] != c && prev == c)
			w_nb++;
		i++;
	}
	return (w_nb);
}

static char		**ft_makearray(const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	index;
	char **array;

	index = 0;
	i = 0;
	array = malloc(sizeof(char*) * ft_wcount(s, c));
	while (s[i])
	{
		if (s[i] != c)
		{
			j = i;
			while (s[j] != c)
				j++;
			array[index] = ft_strsub(s, i, j - i);
			array[index][j] = '\0';
			index++;
			i = j;
		}
		i++;
	}
	array[index] = NULL;
	return (array);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**array;

	if (ft_strcmp(s, "") == 0 || (ft_strlen(s) == 1 && s[0] == c))
	{
		array = malloc(sizeof(char*));
		array[0] = NULL;
		return (array);
	}
	else if (ft_strlen(s) == 1 && s[0] != c)
	{
		array = malloc(sizeof(char*) * 2);
		ft_strcpy(array[0], "");
		array[1] = NULL;
	}
	array = ft_makearray(s, c);
	return (array);
}
