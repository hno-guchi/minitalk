NAME = minitalk

CLIENT_SRCS = client.c
SERVER_SRCS = server.c

CC = cc
CFLAGS = -Wall -Wextra -Werror

$(NAME):	client	server

client: $(CLIENT_SRCS)
	$(CC) $(CFLAGS) -c $^ -o $@

server: $(SERVER_SRCS)
	$(CC) $(CFLAGS) -c $^ -o $@

all:	$(NAME)

bonus: all

clean:
	$(RM) server client
fclean: clean

re:	fclean all

.PHONY: bonus all clean fclean re

# SRCS = client.c server.c
# OBJS = $(SRCS:%.c=%.o)
# LIBFT_DIR = libft
# LIBFT_NAME = libft.a

# .c.o:
# 		$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $(<:%.c=%.o)

# $(NAME):	$(OBJS)
# 		make -C $(LIBFT_DIR)
# 		cp $(LIBFT_DIR)/$(LIBFT_NAME) $(NAME)
# 		ar rcs $@ $^
