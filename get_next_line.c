/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/04 17:46:35 by marene            #+#    #+#             */
/*   Updated: 2013/12/07 12:53:28 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

char	*ft_get_line(char *buffer, int *position)
{
	char	*line;

	while (buffer[*position] && buffer[*position] != '\n')
		(*position)++;
	if (*position == 0)
		line = ft_strnew(1);
	else
	{
		line = ft_strsub(buffer, 0, (size_t)(*position));
		line[*position] = '\0';
	}
	while (buffer[++(*position)] == '\n')
		;
	return (line);
}

char	*ft_buffer_trim(char *buffer, int position)
{
	char	*save;
	char	*dup;

	dup = ft_strdup(buffer);
	save = buffer;
	buffer = ft_strsub(dup, position, ft_strlen(buffer));
	free (save);
	free (dup);
	return (buffer);
}

int		get_next_line(int const fd, char **line)
{
	char				*buffer;
	char				*save;
	int					ret;
	static	char		*buffer2;
	int					position;

	position = 0;
	ret = 0;
	free (*line);
	buffer = malloc(sizeof(char*) * (BUFF_SIZE + 1));
	while (!buffer2 || ft_strchr(buffer2, (int)'\n') == NULL)
	{
		ret = read(fd, buffer, BUFF_SIZE);
		buffer[ret] = '\0';
		save = buffer2;
		buffer2 = ft_strjoin(buffer2, buffer);
		free(save);
	}
	*line = ft_get_line(buffer2, &position);
	buffer2 = ft_buffer_trim(buffer2, position);
	if (ft_strequ(buffer2, "") == 0 || ret == 0)
		return (1);
	else if (ret < 0)
		return (-1);
	else
		return (0);
}
