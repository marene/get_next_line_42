/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 15:39:13 by marene            #+#    #+#             */
/*   Updated: 2013/12/06 16:45:14 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswhite(const char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
			|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

static int	ft_check(const char *s)
{
	if (!s)
		return (0);
	if (ft_strcmp(s, "") == 0)
		return (0);
	return (1);
}

int			ft_atoi(const char *s)
{
	int		i;
	int		pow;
	int		nb;

	i = 0;
	if (!ft_check(s))
		return (0);
	pow = 1;
	nb = 0;
	while (ft_iswhite(s[i]))
		i++;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (ft_isdigit((int)s[i]))
		i++;
	i--;
	while (i >= 0 && ft_isdigit((int)(s[i])))
	{
		nb = nb + (s[i] - '0') * pow;
		pow *= 10;
		i --;
	}
	if (s[i] == '-')
		return (-nb);
	return (nb);
}
