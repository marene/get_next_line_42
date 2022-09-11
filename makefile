# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aldgonza <aldgonza@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/10 20:16:48 by aldgonza          #+#    #+#              #
#    Updated: 2022/09/10 21:07:36 by aldgonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= get_next_line.a
HEADER	= get_next_line.h
HEADER_BONUS	= get_next_line_bonus.h
SRCS	= get_next_line.c \
				get_next_line_utils.c

BONUS_SRS = get_next_line_bonus.c \
						get_next_line_utils.c

BONUS_OBJ = get_next_line_bonus.o \
						get_next_line_utils.o
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -D BUFFER_SIZE=42
OBJS	= ${SRCS:%.c=%.o}

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): ${HEADER} ${OBJS}
		ar rc $(NAME) $(OBJS)

bonus: ${HEADER} ${BONUS_OBJ}
	ar rc $(NAME) $(BONUS_OBJ)

all: $(NAME)


clean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
