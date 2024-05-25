##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile root minishell2
##

CC	=	gcc

SRC_TESTS	=	ex01.c		\
				../new.c	\
				../player.c	\
				../point.c	\
				../vertex.c	\

OBJ_TESTS	= 	${SRC_TESTS:.c=.o}

TESTS_NAME	=	unit_tests

CPPFLAGS	= 	-I./include

tests_run: LDFLAGS += -lcriterion --coverage

tests_run: fclean $(OBJ_TESTS)
	$(CC) -o $(TESTS_NAME) $(OBJ_TESTS) $(LDFLAGS)
	./$(TESTS_NAME)

clean:
	rm -f *.html
	rm -f $(OBJ_TESTS)

fclean: clean
	rm -f $(NAME)
	rm -f $(TESTS_NAME)

re: fclean tests_run

.PHONY: clean fclean re tests_run
