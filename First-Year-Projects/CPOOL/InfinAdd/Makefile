##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##


SRC	=	infin_add.c	\
		main.c	\

LDFLAGS	=	-L lib/ -lmy

CPPFLAGS	=	-I include/

LIB	=	libmy.a

CC	=	gcc

OBJ	=	$(SRC:.c=.o)

NAME	=	infin_add

all:	$(NAME)

$(LIB):
	make -C ./lib/my

$(NAME):	$(LIB) $(OBJ)
	 $(CC) -o $(NAME) -Wall $(OBJ) $(CPPFLAGS) $(LDFLAGS)

clean:
	$(RM) $(OBJ)
	rm -rf *~
	rm -rf *.o
	make clean -C lib/my

fclean:	clean
	$(RM) $(NAME)
	make fclean -C lib/my

re:	fclean all
