##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

IDIR	=	include/

LIBDIR	=	lib/my/

LIB	=	libmy.a

SRC	=	eval_expr.c	\
		main.c		\

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

MV	=	mv

CP	=	cp

CC	=	gcc -g

NAME	=	eval_expr

all:	$(NAME)

$(LIB):
	make -C lib/my

$(NAME):	$(LIB) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -I $(IDIR) -L $(LIBDIR) -lmy

clean:
	$(RM) $(OBJ)
	rm -f *~
	make clean -C lib/my

fclean: clean
	$(RM) $(NAME)
	rm -f *.o
	make fclean -C lib/my

re:	fclean all
