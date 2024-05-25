##
## EPITECH PROJECT, 2022
## B-ASM-400-PAR-4-1-asmminilibc-antoine.gavira-bottari
## File description:
## Makefile
##

CC	=	gcc

ASM	=	nasm -f elf64

SRC	=	src/strlen.asm	\
		src/strchr.asm	\
		src/strrchr.asm	\
		src/memset.asm	\
		src/memcpy.asm	\
		src/strcmp.asm	\
		src/strncmp.asm	\
		src/strcasecmp.asm	\

OBJ	=	$(SRC:.asm=.o)

NAME	=	libasm.so

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -nostdlib -fpic -shared $(OBJ) -o $(NAME)

%.o : %.asm
	$(ASM) -o $@ $<

clean:
	$(RM) $(OBJ)
	$(RM) *.o

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re