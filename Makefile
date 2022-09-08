NAME = minitalk

CC = cc
CFLAGS = -Wall -Wextra -Werror

CLIENT_SRCS = client.c
SERVER_SRCS = server.c

INCLUDES_DIR = includes
SRCS_DIR = srcs
OBJS_DIR = objs

INCLUDE = $(addprefix -I, ./$(INCLUDES_DIR))

CLIENT_OBJS = $(addprefix ./$(OBJS_DIR)/, $(CLIENT_SRCS:%.c=%.o))
SERVER_OBJS = $(addprefix ./$(OBJS_DIR)/, $(SERVER_SRCS:%.c=%.o))

LIBFT_DIR = libft
LIBFT_INCLUDES_DIR = libft/includes
LIBFT_LIB_NAME = ft

LIBFT_INCLUDE = $(addprefix -I, ./$(LIBFT_INCLUDES_DIR))

.PHONY: libft bonus all clean fclean re

all:	$(NAME)

$(NAME): $(OBJS_DIR) libft client server

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

libft:
	make -C $(LIBFT_DIR)

client: $(CLIENT_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -L./$(LIBFT_DIR) -l$(LIBFT_LIB_NAME)

server: $(SERVER_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -L./$(LIBFT_DIR) -l$(LIBFT_LIB_NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c $(INCLUDE) $(LIBFT_INCLUDE) $< -o $@

clean:
	$(RM) -r $(OBJS_DIR)
	make clean -C $(LIBFT_DIR)

fclean:
	$(RM) -r $(OBJS_DIR)
	$(RM) server client
	make fclean -C $(LIBFT_DIR)

bonus: all

re:	fclean all
