##
## EPITECH PROJECT, 2022
## B-YEP-410-PAR-4-1-zappy-thomas.willson
## File description:
## Makefile
##

CC	?=	gcc

RM	?=	rm -f

CFLAGS	+=	-I./include
CFLAGS	+=	-Wall -Wextra

NAME	=	zappy_server

SRCS	=	main.c	\
	source/init/server.c	\
	source/init/accept_client.c	\
	source/init/map.c	\
	source/command/command_gui.c	\
	source/command/command_ai.c	\
	source/command/command_server.c	\
	source/command/command_type.c	\
	source/ai/help.c	\
	source/ai/forward.c	\
	source/ai/right.c	\
	source/ai/left.c	\
	source/ai/inventory.c	\
	source/ai/take_object.c	\
	source/ai/fork.c		\
	source/ai/set_object.c	\
	source/ai/broadcast.c	\
	source/ai/connect_nbr.c	\
	source/ai/look.c	\
	source/ai/incantation.c	\
	source/ai/eject.c	\
	source/gui/help.c	\
	source/gui/amap.c	\
	source/gui/apla.c	\
	source/gui/print.c	\
	source/service/manage_server.c	\
	source/service/manage_client.c	\
	source/utils/error_handling.c	\
	source/utils/linked_list.c	\
	source/utils/split_str.c	\
	source/utils/change_quote.c	\
	source/utils/gui_write.c	\
	source/utils/broadcast_utils.c	\
	source/utils/broadcast_position.c	\
	source/utils/reset_event.c	\
	source/utils/delete_gui.c	\
	source/utils/add_gui.c	\
	source/utils/free_client.c	\
	source/utils/check_connection.c	\
	source/utils/fork_utils.c	\
	source/utils/add_client_to_team.c	\
	source/utils/delete_client_from_team.c	\
	source/utils/message_chrono.c	\
	source/utils/set_writable.c		\
	source/utils/style_writing.c	\
	source/utils/handling_chrono.c	\
	source/utils/linked_players.c	\
	source/utils/set_id_teams.c	\
	source/utils/game/add_player.c	\
	source/utils/gui/translate_map.c	\
	source/utils/gui/translate_player.c	\
	source/utils/gui/translate_mod.c	\
	source/utils/ai/handle_look.c

OBJS	=	${SRCS:.c=.o}

all:	${NAME}

${NAME}:	${OBJS}
	${CC} -o ${NAME} ${OBJS} -lm -luuid
	cp ${NAME} ../${NAME}

debug:	CFLAGS += -g3
debug:	re

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}
	${RM} ../${NAME}

re:	fclean all

.PHONY:	all clean fclean re
