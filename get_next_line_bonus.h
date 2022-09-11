/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldgonza <aldgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:09:32 by aldgonza          #+#    #+#             */
/*   Updated: 2022/09/10 20:29:08 by aldgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 255
#endif

typedef struct filed_s {
	int fd;
	char* buffer;
} filed_t;

filed_t* get_filed(int fd);
void free_fd(int fd);
int find_char(char* haystack, char needle);
size_t ft_strlen(const char* str);
char* splice(char** str, size_t splice_len);
char* concat_string(char* str1, char* str2);
char	*get_next_line(int fd);

#endif
