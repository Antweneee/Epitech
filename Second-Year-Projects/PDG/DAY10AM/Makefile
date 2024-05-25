##
## EPITECH PROJECT, 2022
## B-PDG-300-PAR-3-1-PDGD09-antoine.gavira-bottari
## File description:
## Makefile
##

CC	=	g++

SRC_TESTS	=	ex01/Banana.cpp	\
				ex01/Fruit.cpp	\
				ex01/FruitBox.cpp	\
				ex01/FruitNode.cpp	\
				ex01/Lime.cpp	\
				ex01/Lemon.cpp	\
				ex01/LittleHand.cpp	\
				test/test.cpp	\
				test/test2.cpp	\


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
