/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42barcel>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:24:28 by marene            #+#    #+#             */
/*   Updated: 2022/09/10 21:07:41 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			read_array[BUFFER_SIZE + 1];
	static char		*buffer;
	int				read_length;
	int				new_line_position;

	while ((read_length = read(fd, read_array, BUFFER_SIZE)) > 0 || ft_strlen(buffer) > 0) 
	{
		if (read_length > 0)
		{
			read_array[read_length] = '\0';
			buffer = concat_string(buffer, read_array);
		}
		new_line_position = find_char(buffer, '\n');
		if (new_line_position >= 0) return splice(&buffer, new_line_position + 1);
		else if (read_length == 0) return splice(&buffer, ft_strlen(buffer));
	}

	return NULL;
}
