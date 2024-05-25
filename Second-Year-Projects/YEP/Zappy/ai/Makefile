##
## EPITECH PROJECT, 2022
## B-YEP-410-PAR-4-1-zappy-thomas.willson
## File description:
## Makefile
##

CC		=	gcc

SRC		=	source/main.c	\
			source/connections/init_ai_info.c	\
			source/utils/do_getline.c	\
			source/utils/shift_queued.c	\
			source/utils/move_in_tile.c	\
			source/utils/my_strcat.c	\
			source/utils/update_look_and_inventory.c	\
			source/client/select_client.c	\
			source/client/level_functions_handler.c	\
			source/errors/arg_error.c	\
			source/connections/init_client_side.c	\
			source/game_functions/elevation.c 		\
			source/game_functions/inventory.c 		\
			source/game_functions/look.c	\
			source/levels/first_level.c	\
			source/levels/second_level.c	\
			source/levels/third_level.c	\
			source/levels/fourth_level.c	\
			source/levels/fifth_level.c	\
			source/levels/sixt_level.c	\
			source/levels/seventh_level.c	\
			source/levels/heigth_level.c	\

SRC_TESTS = tests/error_args.c	\
			source/errors/arg_error.c	\
			tests/test_inventory.c 		\
			source/game_functions/elevation.c 		\
			tests/test_elevation.c 		\
			source/game_functions/inventory.c 		\
			tests/test_look.c 		\
			source/game_functions/look.c 		\

OBJ		=	$(SRC:.c=.o)

OBJ_TESTS	=	$(SRC_TESTS:.c=.o)

CPPFLAGS	= -I./includes

CFLAGS		= -W -Wall -Wextra

NAME		=	zappy_ai

TEST__NAME 	=	unit_tests

all:	$(NAME)

debug: CFLAGS += -g3
debug: re

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)
	mv $(NAME) ../

tests_run: LDFLAGS += -lcriterion --coverage

tests_run: fclean $(OBJ_TESTS)
			$(CC) -o unit_tests $(OBJ_TESTS) $(LDFLAGS)
			./$(TEST__NAME)
clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_TESTS)

fclean:	clean
	$(RM) ../$(NAME)
	$(RM) $(TEST__NAME)

re:	fclean all

.PHONY:	all tests_run clean fclean re
