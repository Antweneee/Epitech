##
## EPITECH PROJECT, 2022
## B-PSU-400-PAR-4-1-nmobjdump-antoine.gavira-bottari
## File description:
## Makefile
##

all:	nm objdump

NM_DIR	=	./nm/

OBJ_DIR	=	./objdump/

nm:
	@make -C $(NM_DIR)

objdump:
	@make -C $(OBJ_DIR)

clean:
	@make clean -C $(NM_DIR)
	@make clean -C $(OBJ_DIR)

fclean: clean
	@make fclean -C $(NM_DIR)
	@make fclean -C $(OBJ_DIR)

debug:
	@make debug -C $(NM_DIR)
	@make debug -C $(OBJ_DIR)

re:	fclean all

.PHONY: all re clean fclean nm objdump
