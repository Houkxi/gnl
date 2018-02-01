# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 11:58:31 by mmanley           #+#    #+#              #
#    Updated: 2018/02/01 20:22:40 by mmanley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

INC = includes/

SRCS = 	ft_atoi.c\
		ft_bzero.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_itoa.c\
		ft_lst_print.c\
		ft_lstadd_end.c\
		ft_lstadd.c\
		ft_lstdel.c\
		ft_lstdelone.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_lstmapi.c\
		ft_lstnew.c\
		ft_deltab.c\
		ft_memalloc.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c \
		ft_memcpy.c\
		ft_memdel.c\
		ft_memmove.c\
		ft_memset.c \
		ft_newtab.c\
		ft_strdup.c\
		ft_strnew.c\
		ft_strjoin.c\
		ft_strsub.c\
		ft_strsplit.c\
		ft_putchar_fd.c\
		ft_putchar.c\
		ft_putendl_fd.c\
		ft_putendl.c\
		ft_putnbr_fd.c\
		ft_putnbr.c\
		ft_putstr_fd.c\
		ft_putstr.c\
		ft_show_tab.c\
		ft_occ_counter.c\
		ft_count_btw.c\
		ft_strcat.c\
		ft_strchr.c\
		ft_strcmp.c\
		ft_strcpy.c\
		ft_strlcat.c\
		ft_strlen.c\
		ft_strncat.c\
		ft_strncmp.c\
		ft_strncpy.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strstr.c\
		ft_strdel.c\
		ft_strmap.c\
		ft_strclr.c\
		ft_strequ.c\
		ft_strnequ.c\
		ft_strtrim.c\
		ft_strmapi.c\
		ft_striter.c\
		ft_striteri.c\
		ft_tabcpy.c\
		ft_tolower.c\
		ft_toupper.c \

OBJS =	$(SRCS:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJ_PATH)%.o: %.c
	@$(CC) $(FLAGS) -o $@ -c $< -I $(INC)

clean :
	@rm -rf objs
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
