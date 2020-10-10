# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/10 11:56:52 by mskinner          #+#    #+#              #
#    Updated: 2020/10/10 19:46:41 by mskinner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

FLAG = -f macho64

SRC =	ft_read.s	ft_strcmp.s	ft_strcpy.s	ft_strdup.s	ft_strlen.s	ft_write.s

OBJ = $(SRC:.s=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^
	@ranlib $@
	
%.o: %.s
	@nasm $(FLAG) $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

test:
	@gcc -Wall -Werror -Wextra libasm.a main.c && ./a.out

.PHONY: all clean fclean re
