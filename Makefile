NAME = minitalk

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = signal_receiver.c exit_write_error_message.c
CLIENT_SRCS = client.c validation_args.c
SERVER_SRCS = server.c

INCLUDES_DIR = includes
SRCS_DIR = srcs
OBJS_DIR = objs

INCLUDE = $(addprefix -I, ./$(INCLUDES_DIR))

OBJS = $(addprefix ./$(OBJS_DIR)/, $(SRCS:%.c=%.o))
CLIENT_OBJS = $(addprefix ./$(OBJS_DIR)/, $(CLIENT_SRCS:%.c=%.o))
SERVER_OBJS = $(addprefix ./$(OBJS_DIR)/, $(SERVER_SRCS:%.c=%.o))
CLIENT_OBJS += $(OBJS)
SERVER_OBJS += $(OBJS)

LIBFT_NAME = libft.a
LIBFT_DIR = libft
LIBFT_INCLUDES_DIR = libft/includes
LIBFT_LIB_NAME = ft

LIBFT_INCLUDE = $(addprefix -I, ./$(LIBFT_INCLUDES_DIR))

.PHONY: libft bonus all clean fclean re

all:	$(NAME)

$(NAME): $(OBJS_DIR) $(LIBFT_NAME) client server

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(LIBFT_NAME):
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
