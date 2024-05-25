##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

CC = gcc

SRC =	lib/my_use.c	\
		lib/write.c \
		src/pre_game/set.c	\
		src/pre_game/set2.c	\
		src/pre_game/messages.c	\
		src/pre_game/set_game.c	\
		src/pre_game/destroy.c	\
		src/pre_game/draw.c	\
		src/pre_game/draw2.c	\
		src/pre_game/music.c	\
		src/menu/menu.c	\
		src/menu/menu2.c	\
		src/menu/move.c	\
		src/menu/check.c	\
		src/game/game.c \
		src/game/cut_scene.c \
		src/game/boss_battle.c \
		src/movement/movement.c	\
		src/movement/move_pos.c	\
		src/movement/fill_struct_perso.c	\
		src/movement/move_rect.c	\
		src/movement/special_moves.c	\
		src/inventory/struct_inventory.c	\

SRC_MAIN = src/main.c

OBJ = $(SRC:.c=.o)

OBJ_MAIN = $(SRC_MAIN:.c=.o)

CFLAGS = -Wall -Wextra -pedantic

CPPFLAGS = -I./include

LDFLAGS = -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

RM	=	rm -f

NAME = my_rpg

all: $(NAME)

debug: CFLAGS += -g3
debug: re

$(NAME): $(OBJ) $(OBJ_MAIN)
	$(CC) -o $(NAME) $(LDFLAGS) $(OBJ) $(OBJ_MAIN)

clean:
	$(RM) $(OBJ) $(OBJ_MAIN)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
