# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aschmidt <aschmidt@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 14:23:45 by aschmidt          #+#    #+#              #
#    Updated: 2024/05/08 11:36:23 by aschmidt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	= ft_strlen.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c \
	  ft_print.c ft_pointer.c ft_unsigned.c

OBJS	:= $(SRC:%.c=%.o)

NAME	= libftprintf.a

CC 	= cc

CCFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CCFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
