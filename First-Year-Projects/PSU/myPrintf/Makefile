##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## makefile
##

SRC	=	src/my_getnbr.c	\
		src/my_putchar.c	\
		src/my_put_nbr.c	\
		src/my_putstr.c	\
		src/my_revstr.c	\
		src/my_strcpy.c	\
		src/my_strlen.c	\
		src/my_printf.c	\
		src/my_printf_basic.c	\
		src/maj_hexa.c	\
		src/min_hexa.c	\
		src/convert.c	\

TEST_SRC	=	test/test_my_printf.c	\

OBJ	=	$(SRC:.c=.o)

CFLAG	=	-lcriterion

CPPFLAGS        =       -Wall -I include/

CC	=	gcc

RM 	= 	rm -f

NAME	=	libmy.a

tests_run	=	unit_tests

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

tests_run:	fclean $(OBJ)
	$(CC) -o $(tests_run) $(TEST_SRC) $(OBJ) --coverage $(CFLAG)
	./unit_tests && gcovr --branches --exclude test

clean:
	$(RM) $(OBJ)
	$(RM) src/*~

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(tests_run)
	$(RM) *gcda
	$(RM) *gcno

re:	fclean all
