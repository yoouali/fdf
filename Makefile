# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoouali <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/11 05:42:44 by yoouali           #+#    #+#              #
#    Updated: 2019/07/12 10:06:18 by yoouali          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = fdf_proj/srcs/main.c fdf_proj/srcs/check.c gnl/get_next_line.c libft/libft.a fdf_proj/srcs/stock.c fdf_proj/srcs/free.c
NAME = fdf

all : $(NAME)
$(NAME) :
	@ make -C libft
	@ cc -Wall -Wextra -Werror -I /usr/include -o $(NAME) $(SRC) -L /usr/local/lib -lmlx -framework OpenGL -framework appKit

clean :
	@ make -C libft clean

fclean : clean
	@ make -C libft fclean
	@ rm -rf $(NAME)

re : fclean all
