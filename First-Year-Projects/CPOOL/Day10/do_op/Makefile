##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC	=	do_op.c	\
		main.c	\

LDFLAGS	=	-L ../lib/ -lmy

CPPFLAGS	=	-I ../include/

CC	=	gcc

OBJ	=	$(SRC:.c=.o)

NAME	=	do-op

all:	$(NAME)

$(NAME):	$(OBJ)
	 $(CC) -o $(NAME) -Wall $(OBJ) $(LDFLAGS) $(CPPFLAGS)

clean:
	$(RM) $(OBJ)
	rm -rf *~
	rm -rf *.o

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
