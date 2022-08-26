NAME = minitalk

CC = cc
CFLAGS = -Wall -Wextra -Werror

CLIENT_SRCS = client.c
SERVER_SRCS = server.c

CLIENT_OBJS = $(CLIENT_SRCS:%.c=%.o)
SERVER_OBJS = $(SERVER_SRCS:%.c=%.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:%.c=%.o)

$(NAME):	client	server

client: $(CLIENT_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -L./libft -lft

server: $(SERVER_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -L./libft -lft

all:	$(NAME)

bonus: all

clean:
	$(RM) $(CLIENT_OBJS) $(SERVER_OBJS)
fclean: clean
	$(RM) server client

re:	fclean all

.PHONY: bonus all clean fclean re
