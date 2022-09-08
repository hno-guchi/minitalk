NAME = minitalk

CC = cc
CFLAGS = -Wall -Wextra -Werror

CLIENT_SRCS = client.c
SERVER_SRCS = server.c

CLIENT_OBJS = $(CLIENT_SRCS:%.c=%.o)
SERVER_OBJS = $(SERVER_SRCS:%.c=%.o)

.PHONY: bonus all clean fclean re

all:	$(NAME)

$(NAME): client server

client: $(CLIENT_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

server: $(SERVER_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(CLIENT_OBJS) $(SERVER_OBJS)

fclean:
	$(RM) $(CLIENT_OBJS) $(SERVER_OBJS)
	$(RM) server client

bonus: all

re:	fclean all
