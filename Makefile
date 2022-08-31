NAME = minitalk

CC = cc
CFLAGS = -Wall -Wextra -Werror

CLIENT_SRCS = client.c
SERVER_SRCS = server.c

CLIENT_OBJS = $(CLIENT_SRCS:%.c=%.o)
SERVER_OBJS = $(SERVER_SRCS:%.c=%.o)

LIBFT_DIR = libft
LIBFT_INCLUDES_DIR = libft/includes
LIBFT_LIB_NAME = ft

INCLUDE = $(addprefix -I, ./$(LIBFT_INCLUDES_DIR))

.PHONY: libft bonus all clean fclean re

all:	$(NAME)

$(NAME): libft client server

libft:
	make -C $(LIBFT_DIR)

client: $(CLIENT_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -L./$(LIBFT_DIR) -l$(LIBFT_LIB_NAME)

$(CLIENT_OBJS): $(CLIENT_SRCS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $(CLIENT_SRCS)

server: $(SERVER_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -L./$(LIBFT_DIR) -l$(LIBFT_LIB_NAME)

$(SERVER_OBJS): $(SERVER_SRCS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SERVER_SRCS)

clean:
	$(RM) $(CLIENT_OBJS) $(SERVER_OBJS)
	make clean -C $(LIBFT_DIR)

fclean:
	$(RM) $(CLIENT_OBJS) $(SERVER_OBJS)
	$(RM) server client
	make fclean -C $(LIBFT_DIR)

bonus: all

re:	fclean all
