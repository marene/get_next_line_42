/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42barcel>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:24:28 by marene            #+#    #+#             */
/*   Updated: 2022/09/10 21:07:41 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int find_char(char* haystack, char needle)
{
	int i = 0;

	while (haystack[i])
	{
		if (haystack[i] == needle) return i;
		i++;
	}

	return -1;
}

size_t ft_strlen(const char* str)
{
	size_t i = 0;
	while (str && str[i] != 0) {
		i++;
	}

	return i;
}

char* splice(char** str, size_t splice_len)
{
	size_t str_len = ft_strlen(*str);
	char* spliced = malloc(splice_len + 1);
	char* tmp = str_len > splice_len ? malloc(str_len - splice_len + 1) : NULL;
	size_t i = 0;
	size_t j = 0;
	spliced[splice_len] = '\0';
	if (tmp) tmp[str_len - splice_len] = '\0';

	while (i < splice_len)
	{
		spliced[i] = str[0][i];
		i++;
	}

	while (tmp && j < str_len - splice_len)
	{
		tmp[j] = str[0][splice_len + j];
		j++;
	}

	free(*str);
	*str = tmp;

	return spliced;
}

char* concat_string(char* str1, char* str2)
{
	int total_length = ft_strlen(str1) + ft_strlen(str2);
	char* concatenated_string = malloc(total_length + 1);
	size_t i = 0;
	size_t j = 0;

	concatenated_string[total_length] = 0;
	while (str1 && str1[i])
	{
		concatenated_string[i] = str1[i];
		i++;
	}
	while (str2 && str2[j])
	{
		concatenated_string[i + j] = str2[j];
		j++;
	}

	free(str1);

	return concatenated_string;
}

