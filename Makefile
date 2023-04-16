# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 16:57:15 by aoubhoum          #+#    #+#              #
#    Updated: 2022/11/29 14:22:41 by aoubhoum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SOURCES = \
	ft_print_ptr.c ft_printf_2nd_utils.c \
	ft_printf.c ft_printf_utils.c ft_memcpy.c \

OBJECTS = $(SOURCES:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -cr $(NAME) $(OBJECTS)

%.o: %.c ft_printf.h
	$(CC) -c $(FLAGS) $<

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all