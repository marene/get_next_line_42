/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 16:46:43 by marene            #+#    #+#             */
/*   Updated: 2013/12/06 19:02:18 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 && s2)
	{
		str = ft_strdup(s2);
		return (str);
	}
	else if (s1 && !s2)
	{
		str = ft_strdup(s1);
		return (str);
	}

	if (!s1 && !s2)
		return (NULL);
	else
	{
		str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		str = ft_strcat(str, s1);
		str = ft_strcat(str, s2);
		return (str);
	}
	return (0);
}
