##
## EPITECH PROJECT, 2022
## B-YEP-410-PAR-4-1-zappy-thomas.willson
## File description:
## Makefile
##

CXX		=	g++

SRC	=	main.cpp	\
	Core.cpp	\
	Interpret.cpp	\
	Cases.cpp	\
	Display.cpp	\
	Player.cpp	\
	Drawable.cpp	\
	Button/Button.cpp	\
	Scenes/MenuScene.cpp	\
	Scenes/SettingsScene.cpp	\
	Scenes/BoxDescription.cpp	\

OBJ		=	$(SRC:.cpp=.o)

CPPFLAGS	= -I ./include

CXXFLAGS		= -W -Wall -Wextra

GFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

NAME		=	zappy_gui


all:	$(NAME)

$(NAME): $(MAIN_OBJ) $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(GFLAGS)
	mv $(NAME) ../

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) ../$(NAME)

debug: CXXFLAGS += -g3
debug: re

re:	fclean all

.PHONY:	all clean fclean re
