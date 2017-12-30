# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 07:31:59 by mmanley           #+#    #+#              #
#    Updated: 2017/12/30 03:50:07 by mmanley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl

CC = gcc

FLAGS = -Wall -Wextra -Werror

INC = libft/libft.h

SRCS = 	get_next_line.c\

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) :
	@cd libft && make re
	@$(CC) -c $(FLAGS) $(SRCS) -I $(INC)
	@ar rc lib.a $(OBJS)
	@$(CC) -o $@ $(FLAGS) lib.a libft/libft.a

sub :
	cd libft && make re

subclean :
	cd libft && make clean

subre :
	cd libft && make fclean && make all

debug :
	cd libft && make re
	$(CC) -c $(FLAGS) $(SRCS) -I $(INC)
	ar rc libfill.a $(OBJS)
	$(CC) -g -o $(NAME) $(FLAGS) libfill.a libft/libft.a

clean :
	cd libft && make clean
	@rm -f $(OBJS)

fclean : clean
	cd libft && make fclean
	@rm -rf $(NAME) lib.a

re : fclean all