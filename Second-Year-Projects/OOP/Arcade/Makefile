##
## EPITECH PROJECT, 2022
## B-OOP-400-PAR-4-1-arcade-valentin.fouillet
## File description:
## Makefile
##

CXX			=	g++

OSXCXX	=	g++-11

#************************ DIR ************************#

COREDIR	=	./core

GAMEDIR	=	./games

GRAPHICALSDIR	=	./graphicals

#************************ SRC ************************#

NIBBLERSRC	=	$(GAMEDIR)/nibbler/Nibbler.cpp	\

PACMANSRC	=	$(GAMEDIR)/pacman/Pacman.cpp	\

CORESRC	=	$(COREDIR)/main.cpp	\
	$(COREDIR)/Preprocess.cpp	\

SFMLSRC	=	$(GRAPHICALSDIR)/sfml/sfml.cpp	\

SDLSRC	=	$(GRAPHICALSDIR)/sdl/sdl.cpp	\

NCURSESRC	=	$(GRAPHICALSDIR)/ncurse/ncurse.cpp	\

#************************ OBJ ************************#

NIBBLEROBJ	=	$(NIBBLERSRC:.cpp=.o)

PACMANOBJ	=	$(PACMANSRC:.cpp=.o)

PACMANOBJ	= $(PACMANSRC:.cpp=.o)

SFMLOBJ	= $(SFMLSRC:.cpp=.o)

NCURSEOBJ	= $(NCURSESRC:.cpp=.o)

SDLOBJ	= $(SDLSRC:.cpp=.o)

COREOBJ	=	$(CORESRC:.cpp=.o)

#************************ FLAGS ************************#

CPPFLAGS	=	-I./includes

CFLAGS		=	-W -Wall -Wextra -Werror

SHAREDLIBFLAGS	=	-fno-gnu-unique

OSXSHAREDLIBFLAGS  =  -dynamiclib

COREFLAGS	=	-ldl

NCURSEFLAGS	=	-shared -fPIC -lncurses

SFMLFLAGS	=	-shared -fPIC -lsfml-graphics -lsfml-window -lsfml-system

SDLFLAGS	=	-shared -fPIC -lSDL2


#************************ NAMES ************************#

CORENAME		=	arcade

LIBSFML	=	arcade_sfml.so

LIBNCURSE	=	arcade_ncurses.so

LIBSDL	=	arcade_sdl2.so

GAMENIBBLER	=	arcade_nibbler.so

GAMEPACMAN	=	arcade_pacman.so

OSXLIBSFML  =  arcade_sfml.dylib

OSXLIBNCURSE  =  arcade_ncurses.dylib

OSXLIBSDL  =  arcade_sdl2.dylib

OSXGAMENIBBLER  =  arcade_nibbler.dylib

OSXGAMEPACMAN  =  arcade_pacman.dylib

FOLDER	=	lib

#************************ MAC OSX ************************#

CPPFLAGSOSX	   =  -I/opt/homebrew/Cellar/sfml/2.5.1_1/include
LDFLAGSOSX	   =  -L/opt/homebrew/Cellar/sfml/2.5.1_1/lib
SFMLFLAGSOSX   =  -lsfml-graphics -lsfml-window -lsfml-system
NCURSEFLAGSOSX =  -lncurses
SDLFLAGSOSX    =


#************************ RULES ************************#

all:	core games graphicals
osx:   core osxgames osxgraphicals

debug: CFLAGS += -g3
debug: re

core: $(CORENAME)

games: CXXFLAGS += -fPIC
games: $(FOLDER) $(GAMENIBBLER) $(GAMEPACMAN)

graphicals: CXXFLAGS += -fPIC
graphicals: $(FOLDER) $(LIBSFML) $(LIBNCURSE) $(LIBSDL)

osxgames: CXXFLAGS += -fPIC
osxgames: $(FOLDER) $(OSXGAMENIBBLER) $(OSXGAMEPACMAN)

osxgraphicals: CXXFLAGS += -fPIC
osxgraphicals: $(FOLDER) $(OSXLIBSFML) $(OSXLIBNCURSE) $(OSXLIBSDL)

$(FOLDER):
	mkdir lib

$(OSXGAMENIBBLER): $(NIBBLEROBJ)
	$(OSXCXX) -o $(OSXGAMENIBBLER) $(NIBBLERSRC) $(OSXSHAREDLIBFLAGS) -shared -fPIC $(CPPFLAGS)
	mv $(OSXGAMENIBBLER) $(FOLDER)

$(OSXGAMEPACMAN):	$(PACMANOBJ)
	$(OSXCXX) -o $(OSXGAMEPACMAN) $(PACMANSRC) $(OSXSHAREDLIBFLAGS) -shared -fPIC  $(CPPFLAGS)
	mv $(OSXGAMEPACMAN) $(FOLDER)

$(OSXLIBSFML):	$(SFMLOBJ)
	$(OSXCXX) $(OSXSFMLOBJ) -o $(OSXLIBSFML) $(OSXSHAREDLIBFLAGS) $(SFMLFLAGS)
	mv $(OSXLIBSFML) $(FOLDER)

$(OSXLIBNCURSE):	$(NCURSEOBJ)
	$(OSXCXX) $(NCURSEOBJ) -o $(OSXLIBNCURSE) $(OSXSHAREDLIBFLAGS) $(NCURSEFLAGS)
	mv $(OSXLIBNCURSE) $(FOLDER)

$(OSXLIBSDL):	$(SDLOBJ)
	$(OSXCXX) $(SDLOBJ) -o $(OSXLIBSDL) $(OSXSHAREDLIBFLAGS) $(SDLFLAGS)
	mv $(OSXLIBSDL) $(FOLDER)

$(GAMENIBBLER): $(NIBBLEROBJ)
	$(CXX) -o $(GAMENIBBLER) $(NIBBLERSRC) $(SHAREDLIBFLAGS) -shared -fPIC $(CPPFLAGS)
	mv $(GAMENIBBLER) $(FOLDER)

$(GAMEPACMAN):	$(PACMANOBJ)
	$(CXX) -o $(GAMEPACMAN) $(PACMANSRC) $(SHAREDLIBFLAGS) -shared -fPIC  $(CPPFLAGS)
	mv $(GAMEPACMAN) $(FOLDER)

$(CORENAME): $(COREOBJ)
	$(CXX) -o $(CORENAME) $(COREOBJ) $(COREFLAGS)

$(LIBSFML):	$(SFMLOBJ)
	$(CXX) $(SFMLOBJ) -o $(LIBSFML) $(SHAREDLIBFLAGS) $(SFMLFLAGS)
	mv $(LIBSFML) $(FOLDER)

$(LIBNCURSE):	$(NCURSEOBJ)
	$(CXX) $(NCURSEOBJ) -o $(LIBNCURSE) $(SHAREDLIBFLAGS) $(NCURSEFLAGS)
	mv $(LIBNCURSE) $(FOLDER)

$(LIBSDL):	$(SDLOBJ)
	$(CXX) $(SDLOBJ) -o $(LIBSDL) $(SHAREDLIBFLAGS) $(SDLFLAGS)
	mv $(LIBSDL) $(FOLDER)

clean:
	$(RM) $(SFMLOBJ) $(NCURSEOBJ) $(SDLOBJ) $(COREOBJ) $(NIBBLEROBJ) $(PACMANOBJ)

fclean:	clean
	$(RM) $(CORENAME) $(FOLDER)/$(LIBSFML) $(FOLDER)/$(LIBNCURSE) $(FOLDER)/$(LIBSDL) $(FOLDER)/$(GAMENIBBLER) $(FOLDER)/$(GAMEPACMAN) $(FOLDER)/$(OSXLIBSFML) $(FOLDER)/$(OSXLIBNCURSE) $(FOLDER)/$(OSXLIBSDL) $(FOLDER)/$(OSXGAMENIBBLER) $(FOLDER)/$(OSXGAMEPACMAN)

re:	fclean all

.PHONY:	all clean fclean re core games graphicals
