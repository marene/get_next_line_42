/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:33:31 by marene            #+#    #+#             */
/*   Updated: 2013/12/01 20:44:38 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define MIN_INT -2147483648
/*
** this header contains all the prototypes required for the creation of libft.a
** libft.a is a very usefull archives which contains re-coded libc functions,
** and a few other memory and char strings manipulation functions.
*/
# include <string.h>
# include <unistd.h>

typedef struct	s_list
{
	void	*content;
	size_t	content_size;
	struct	s_list *next;
} 				t_list;

void			ft_striteri(char*, void (*)(unsigned int, char*));
void			*ft_memccpy(void*, const void*, int, size_t);
void			ft_lstiter(t_list*, void (*f)(t_list*));
void			*ft_memcpy(void*, const void*, size_t);
void			*ft_memmove(void*, const void*, size_t);
void			*ft_memchr(const void*, int, size_t);
void			ft_striter(char*s, void (*)(char*));
void 			ft_putendl_fd(char const*, int);
void			*ft_memset(void*, int, size_t);
void 			ft_putstr_fd(char const*, int);
void 			ft_putchar_fd(char, int);
void 			ft_putendl(char const*);
void			ft_bzero(void*, size_t);
void 			ft_putnbr_fd(int, int);
void 			ft_putstr(char const*);
void			*ft_memalloc(size_t);
void			ft_memdel(void**);
void			ft_strdel(char**);
void			ft_strclr(char*);
void 			ft_putnbr(int);
void 			ft_putchar(char);

char			*ft_strmapi(char const*, char (*)(unsigned int, char));
char			*ft_strnstr(const char*, const char*, size_t);
char			*ft_strsub(char const*, unsigned int, size_t);
char			*ft_strncpy(char*, const char*, size_t);
char			*ft_strncat(char*, const char*, size_t);
char			*ft_strmap(char const*, char (*)(char));
char			*ft_strjoin(char const*, char const*);
char			*ft_strstr(const char*, const char*);
char			**ft_strsplit(char const*, char);
char			**ft_strsplit(char const*, char);
char			*ft_strrchr(const char*, char);
char			*ft_strcpy(char*, const char*);
char			*ft_strcat(char*, const char*);
char			*ft_strchr(const char*, int);
char			*ft_strtrim(char const*);
char			*ft_strdup(const char*);
char			*ft_strnew(size_t);
char			*ft_itoa(int);

size_t			ft_strlcat(char*, const char*, size_t);
size_t			ft_strlen(const char*);

int				ft_strnequ(char const*, char const*, size_t);
int				ft_strncmp(const char*, const char*, size_t);
int				ft_memcmp(const void*, const void*, size_t);
int				ft_strcmp(const char*, const char*);
int				ft_strequ(char const*, char const*);
int				ft_atoi(const char*);
int				ft_isdigit(int);
int				ft_isalpha(int);
int				ft_isascii(int);
int				ft_isprint(int);
int				ft_isalnum(int);
int				ft_toupper(int);
int				ft_tolower(int);

t_list		 	*lstmap(t_list*, t_list *(*f)(t_list*));
t_list			*ft_lstnew(void const*, size_t);
#endif /*!LIBFT_H*/
