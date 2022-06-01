SERVER 		= server		
CLIENT		= client
SRC_S		= server.c
SRC_C		= client.c
SRC_U		= utils.c
HEADER		= minitalk.h

OBJ_S 		= $(patsubst %.c,%.o,$(SRC_S))
OBJ_C 		= $(patsubst %.c,%.o,$(SRC_C))
OBJ_U 		= $(patsubst %.c,%.o,$(SRC_U))

D_FILES 	= $(patsubst %.c,%.d,$(SRC_S) $(SRC_C) $(SRC_U))

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -O2

all		:	$(SERVER) $(CLIENT)

$(SERVER)	:	$(OBJ_S) $(OBJ_U) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ_S) $(OBJ_U) -o $(SERVER)

$(CLIENT)	:	$(OBJ_C) $(OBJ_U) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ_C) $(OBJ_U) -o $(CLIENT)

%.o 	: 	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

include $(wildcard $(D_FILES))

clean	:
	@rm -f $(OBJ_S) $(OBJ_C) $(OBJ_U) $(D_FILES)

fclean	:	clean
	@rm -f $(SERVER) $(CLIENT)

re		:	fclean all

.PHONY		: 		all clean fclean re bonus