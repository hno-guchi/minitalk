NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

ARFLAGS = rcs

SRCS = ft_printf.c \
	ftp_scanning_count.c \
	ftp_check_has_fmt.c ftp_puts_not_conv_count.c \
	ftp_prs_fmt_count.c ftp_is_flags_count.c ftp_prs_wth_count.c ftp_prs_prec_count.c \
	ftp_select_conv.c \
	ftp_conv_c.c ftp_conv_s.c ftp_conv_d_i.c ftp_conv_u.c ftp_conv_p.c ftp_conv_x.c \
	ftp_check_len_count.c \
	ftp_fputs_percent.c ftp_fputs_c_s.c ftp_fputs_d_i.c ftp_fputs_u.c ftp_fputs_p.c ftp_fputs_x.c \
	ftp_puts_flags.c ftp_puts_char.c \
	ftp_atoi_count.c ftp_itoa_count.c ftp_ull_itoa_base.c \
	ftp_str_tolower.c ftp_free_null.c

LIBFT_DIR = ../..
INCLUDES_DIR = ../../includes
OBJS_DIR = ../../objs

INCLUDE = $(addprefix -I, $(INCLUDES_DIR))

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.c=%.o))

all:	$(NAME)

$(NAME):	$(OBJS)
		$(AR) $(ARFLAGS) $(LIBFT_DIR)/$(NAME) $(OBJS)
		
$(OBJS_DIR)/%.o:	%.c
		$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@

re:	all

.PHONY: all re
