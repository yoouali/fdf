# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhossan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/30 15:55:08 by akhossan          #+#    #+#              #
#    Updated: 2019/07/18 13:25:05 by akhossan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

CFLAGS		=	-Werror -Wall -Wextra

SRC			=	$(wildcard *.c)

OBJ			=	$(SRC:.c=.o)

all:$(NAME)

$(NAME):
	gcc -c $(CFLAGS) -I. $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
