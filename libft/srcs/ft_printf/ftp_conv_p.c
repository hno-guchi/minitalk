/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_conv_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:27:30 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/07/07 16:06:29 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	puts_not_width(char *ullp_str, size_t ullp_len, size_t puts_len)
{
	size_t	puts_prec_len;

	puts_prec_len = 0;
	if (ullp_len < puts_len)
	{
		puts_prec_len = puts_len - ullp_len;
		if (write(1, "0x", 2) == -1)
			return (-1);
		if (ftp_puts_char('0', puts_prec_len) == -1)
			return (-1);
		if (write(1, ullp_str, (puts_len - puts_prec_len)) == -1)
			return (-1);
	}
	else
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		if (write(1, ullp_str, ullp_len) == -1)
			return (-1);
	}
	return (1);
}

static int	puts_p(char *ullp_str,
		t_fmt_info *info, size_t ullp_len, size_t puts_len)
{
	if ((puts_len + 2) < (size_t)info->width)
	{
		if (ftp_fputs_p(ullp_str, info, ullp_len, puts_len) == -1)
			return (ftp_free_null(&ullp_str));
	}
	else
		if (puts_not_width(ullp_str, ullp_len, puts_len) == -1)
			return (ftp_free_null(&ullp_str));
	return (1);
}

static size_t	adjust_info_puts_len(t_fmt_info *info,
		void *p, size_t *ullp_len)
{
	size_t	puts_len;

	puts_len = 0;
	if ((info->precision != -1) && (*ullp_len < (size_t)info->precision))
		puts_len = (size_t)info->precision;
	else if (p == NULL && info->precision == 0)
	{
		puts_len = 0;
		*ullp_len = 0;
	}
	else
		puts_len = *ullp_len;
	return (puts_len);
}

static char	*create_ull_p_str(unsigned long long ull_p, size_t *len)
{
	char				*ull_p_str;

	ull_p_str = ftp_ull_itoa_base(ull_p, 16, len);
	if (ull_p_str == NULL)
		return (NULL);
	ull_p_str = ftp_str_tolower(ull_p_str);
	return (ull_p_str);
}

int	ftp_conv_p(void *point, t_fmt_info *info, char *buf, size_t *p_len)
{
	size_t	buf_len;
	size_t	ullp_len;
	size_t	puts_len;
	char	*ullp_str;

	buf_len = ft_strlen(buf);
	ullp_str = create_ull_p_str((unsigned long long)point, &ullp_len);
	if (ullp_str == NULL)
		return (-1);
	puts_len = adjust_info_puts_len(info, point, &ullp_len);
	if (ftp_check_len_count(p_len, buf_len, puts_len, info) == -1)
		return (ftp_free_null(&ullp_str));
	if (write(1, buf, buf_len) == -1)
		return (ftp_free_null(&ullp_str));
	if (puts_p(ullp_str, info, ullp_len, puts_len) == -1)
		return (ftp_free_null(&ullp_str));
	(void)ftp_free_null(&ullp_str);
	return (1);
}
