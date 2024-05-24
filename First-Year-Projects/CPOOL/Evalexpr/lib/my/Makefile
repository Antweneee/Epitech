##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

IDIR	=	include/

LIBDIR	=	lib/my/

SRC	=	my_putchar.c		\
		my_put_nbr.c		\

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

MV	=	mv

CP	=	cp

CC	=	gcc -g

AR	=	ar rc

NAME	=	libmy.a

all:	$(NAME)
	cp $(NAME) ../
	cp my.h ../../include

$(NAME):	$(OBJ)
	$(CC) -w -c $(SRC) -Wall
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)
	rm -f *~

fclean:	clean
	$(RM) $(NAME)
	rm ../libmy.a

re:	fclean all
