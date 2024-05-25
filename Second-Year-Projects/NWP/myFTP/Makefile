##
## EPITECH PROJECT, 2022
## B-NWP-400-PAR-4-1-myftp-antoine.gavira-bottari
## File description:
## Makefile
##

CC	=	gcc

SRCDIR	=	src/

SRC	=	$(SRCDIR)/main.c	\
	$(SRCDIR)/server_engine.c	\
	$(SRCDIR)/s_struct_related.c	\
	$(SRCDIR)/str_array.c	\
	$(SRCDIR)/read_writecase.c	\
	$(SRCDIR)/c_struct_related.c	\
	$(SRCDIR)/checker.c	\
	$(SRCDIR)/commands_first.c	\
	$(SRCDIR)/commands_sec.c	\
	$(SRCDIR)/commands_third.c	\
	$(SRCDIR)/commands_fourth.c	\

OBJ	=	$(SRC:.c=.o)

CPPFLAGS	=	-I include/

CFLAGS	=	-Wall -Wextra

NAME	=	myftp

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

debug:	CFLAGS += -g3
debug: re

.PHONY:	all re fclean clean debug