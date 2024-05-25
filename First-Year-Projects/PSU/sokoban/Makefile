##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

SRC 	=	src/main.c	\
		src/parameters.c	\
		src/movement.c	\
		src/end.c	\
		src/fix_o.c	\

LDFLAGS	=	-L ./lib/ -lmy

CFLAGS = -Wall -Wextra -pedantic

CPPFLAGS	=	-g3 -I include/

LIB	=	libmy.a

CC	=	gcc -g

RM	=	rm -f

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

all:	$(LIB) $(NAME)

$(LIB)	:
	make -C ./lib/my/

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) -lncurses

clean:
	$(RM) $(OBJ)
	make clean -C lib/my/

fclean: clean
	$(RM) $(NAME)
	make fclean -C lib/my

re:	fclean all

.PHONY:	clean fclean re all
