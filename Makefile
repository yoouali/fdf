# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhossan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/03 20:42:53 by akhossan          #+#    #+#              #
#    Updated: 2019/07/27 21:56:44 by yoouali          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   Fdf

LFT     =   libft/libft.a

LIBS    =   -lmlx -framework OpenGl -framework Appkit

CFLAGS  =   -Werror -Wextra -Wall

GNL     =   obj/get_next_line.o 

SRCDIR  =   fdf_proj/srcs/

OBJDIR  =   obj/

SRC     =   $(SRCDIR)draw.c $(SRCDIR)read.c $(SRCDIR)main.c $(SRCDIR)color.c\
			           $(SRCDIR)map.c $(SRCDIR)leak.c $(SRCDIR)proj.c $(SRCDIR)events.c

OBJ     =   $(OBJDIR)draw.o $(OBJDIR)read.o $(OBJDIR)main.o $(OBJDIR)color.o\
			            $(OBJDIR)map.o $(OBJDIR)leak.o $(OBJDIR)proj.o $(OBJDIR)events.o

all: $(NAME)

$(GNL) : gnl/get_next_line.c
	    @printf "\033[92mGenerating gnl object file\n\033[15m"
		    gcc -c $(CFLAGS) $^

$(OBJ) : $(SRC)
	    @printf "\033[92mGenerating object files\n\033[15m"
		    mkdir -p $(OBJDIR)
			    gcc $(CFLAGS) -c $^ 
				    mv *.o $(OBJDIR)

$(LFT) :
	    @printf "\033[92mCompiling Libft\n\033[15m"
		    make -C libft

$(NAME): $(LFT) $(GNL) $(OBJ)
	    @printf "\033[92mCompiling Fdf\n\033[15m"
		    gcc $(CFALGS) $^ $(LIBS) -o $(NAME)

clean:
	    @printf "\033[1;31mRemoving all object files\n"
		    make clean -C libft
			/bin/rm -rf $(OBJDIR)

fclean: clean
	    @printf "\033[1;31mRemoving all binary files\n"
		    make -C libft fclean
			    /bin/rm -rf $(NAME)

re: fclean all 
