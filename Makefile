# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhossan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/03 20:42:53 by akhossan          #+#    #+#              #
#    Updated: 2019/07/24 10:17:53 by yoouali          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Fdf

LFT		= 	libft/libft.a

LIBS	=	-lmlx -framework OpenGl -framework Appkit

CFLAGS	=	-Werror -Wextra -Wall

GNL		=	get_next_line.o 

SRCDIR	=	fdf_proj/srcs/

SRC		=	$(SRCDIR)draw.c $(SRCDIR)read.c $(SRCDIR)main.c $(SRCDIR)color.c\
   		   $(SRCDIR)map.c $(SRCDIR)leak.c $(SRCDIR)proj.c $(SRCDIR)events.c

OBJ		=	draw.o read.o main.o color.o map.o leak.o proj.o events.o
   		    

all: $(NAME)

$(GNL) : gnl/get_next_line.c
	@printf "\033[92mGenerating gnl object file\n\033[15m"
	gcc -c $(CFLAGS) $^

$(OBJ) : $(SRC)
	@printf "\033[92mGenerating object files\n\033[15m"
	gcc $(CFLAGS) -c $^ 

$(LFT) :
	@printf "\033[92mCompiling Libft\n"\033[15m
	make -C libft

$(NAME): $(LFT) $(GNL) $(OBJ)
	@printf "\033[92mCompiling Fdf\n"\033[15m
	gcc $(CFALGS) $^ $(LIBS) -o $(NAME)

clean:
	make clean -C libft
	/bin/rm -rf $(OBJ) $(GNL)

fclean: clean
	make -C libft fclean
	/bin/rm -rf $(NAME)

re: fclean all 
