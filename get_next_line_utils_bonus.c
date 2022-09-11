/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42barcel>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:24:28 by marene            #+#    #+#             */
/*   Updated: 2022/09/10 21:07:41 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

filed_t** file_descriptors = NULL;

filed_t* get_filed(int fd)
{
	filed_t** tmp;
	int i = 0;
	int j = 0;

	if (file_descriptors == NULL)
	{
		file_descriptors = malloc(sizeof(filed_t*));
		file_descriptors[0] = NULL;
	}

	while (file_descriptors[i])
	{
		if (file_descriptors[i]->fd == fd)
		{
			return file_descriptors[i];
		}

		i++;
	}

	tmp = malloc(sizeof(filed_t*) * (i + 2));
	while (file_descriptors[j])
	{
		tmp[j] = file_descriptors[j];
		j++;
	}
	tmp[j] = malloc(sizeof(filed_t));
	tmp[j]->buffer = NULL;
	tmp[j]->fd = fd;
	tmp[j+1] = NULL;
	free(file_descriptors);
	file_descriptors = tmp;

	return tmp[j];
}

void free_fd(int fd)
{
	int i = 0;
	int j = 0;
	int k = 0;
	filed_t** tmp = NULL;
	int fd_num = -1;

	while (file_descriptors[++fd_num]) {}

	while (file_descriptors[i])
	{
		if (file_descriptors[i]->fd == fd)
		{
			if (fd_num > 1)
			{
				tmp = malloc(sizeof(filed_t*) * fd_num);
				tmp[fd_num - 1] = NULL;
				while (j < fd_num)
				{
					if (j != i) 
					{
						tmp[k] = file_descriptors[j];
						k++;
					}
					j++;
				}
			}
			free(file_descriptors[i]->buffer);
			free(file_descriptors[i]);
			free(file_descriptors);
			file_descriptors = tmp;
			
			return ;
		}
		i++;
	}
}

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

