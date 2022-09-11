/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42barcel>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:24:28 by marene            #+#    #+#             */
/*   Updated: 2022/09/10 21:07:41 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char *get_next_line(int fd)
{
	char read_array[BUFFER_SIZE + 1] = {0};
	filed_t* filed = get_filed(fd);
	int read_length;
	int new_line_position;
	char* ret;

	while ((read_length = read(fd, read_array, BUFFER_SIZE)) > 0 || ft_strlen(filed->buffer) > 0) 
	{
		if (read_length > 0)
		{
			read_array[read_length] = '\0';
			filed->buffer = concat_string(filed->buffer, read_array);
		}
		new_line_position = find_char(filed->buffer, '\n');
		if (new_line_position >= 0) return splice(&(filed->buffer), new_line_position + 1);
		else if (read_length <= 0)
		{
			ret = splice(&(filed->buffer), ft_strlen(filed->buffer));
			free_fd(fd);
			return ret;
		}
	}

	free_fd(fd);
	return NULL;
}
