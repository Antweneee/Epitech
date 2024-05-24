##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

SRC 	=	do_op.c		\
		prio.c		\
		main.c		\
		error.c		\

LDFLAGS	=	-L ./lib/ -lmy

CPPFLAGS	=	-Wall -I include/

LIB	=	libmy.a

CC	=	gcc

OBJ	=	$(SRC:.c=.o)

NAME	=	calc

all:	$(LIB) $(NAME)

$(LIB)	:
	make -C ./lib/my/

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -rf $(OBJ)
	rm -rf *~
	make clean -C lib/my/

fclean: clean
	$(RM) $(NAME)
	make fclean -C lib/my

re:	fclean all
