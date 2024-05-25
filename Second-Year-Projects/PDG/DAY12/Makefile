##
## EPITECH PROJECT, 2022
## B-PDG-300-PAR-3-1-PDGD09-antoine.gavira-bottari
## File description:
## Makefile
##

CC	=	g++

SRC_TESTS	=	test/test00.cpp	\


TESTS_NAME	=	unit_tests

CPPFLAGS	= 	-I./

tests_run: LDFLAGS += -lcriterion --coverage

tests_run: fclean
	$(CC) -o $(TESTS_NAME) $(SRC_TESTS) $(LDFLAGS)
	./$(TESTS_NAME)

clean:
	rm -f *.html
	rm -f *.gcno
	rm -f *.gcda
	rm -f $(OBJ_TESTS)

fclean: clean
	rm -f $(TESTS_NAME)

re: fclean tests_run

.PHONY: clean fclean re tests_run
