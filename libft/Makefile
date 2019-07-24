# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhossan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/30 15:55:08 by akhossan          #+#    #+#              #
#    Updated: 2019/07/24 19:38:44 by yoouali          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

CFLAGS		=	-Werror -Wall -Wextra


SRC			= ft_strsplitset.c ft_memdel.c ft_striteri.c ft_strrchr.c ft_lstadd.c ft_memmove.c ft_putstr_fd.c ft_strjoin.c ft_strsplit.c ft_atoi.c ft_atoi_base.c ft_lstdel.c ft_memset.c ft_strlcat.c ft_strstr.c ft_bzero.c ft_lstdelone.c ft_putchar.c ft_strcat.c ft_strlen.c ft_strsub.c ft_contains.c ft_lstiter.c ft_putchar_fd.c ft_strchr.c ft_strmap.c ft_strtrim.c ft_countwd.c ft_iswhitespace.c ft_lstmap.c ft_putendl.c ft_strclr.c ft_strmapi.c ft_tolower.c ft_isalnum.c ft_lstnew.c ft_putendl_fd.c ft_strcmp.c ft_strncat.c ft_toupper.c ft_isalpha.c ft_memalloc.c ft_indexof.c ft_strcpy.c ft_strncmp.c ft_pow.c ft_isascii.c ft_memccpy.c ft_putnbr.c ft_strdel.c ft_strncpy.c ft_isdigit.c ft_memchr.c ft_putnbr_fd.c ft_strdup.c ft_strnequ.c ft_isprint.c ft_memcmp.c ft_strequ.c ft_strnew.c ft_itoa.c ft_memcpy.c ft_putstr.c ft_striter.c ft_strnstr.c ft_issign.c  ft_tolower.c ft_toupper.c ft_islower.c

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
