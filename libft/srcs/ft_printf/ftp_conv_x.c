/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_conv_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:04:17 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/07/07 16:04:55 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	puts_not_width(char *uint_str,
		t_fmt_info *info, size_t uint_len, size_t puts_len)
{
	size_t	puts_prec_len;

	puts_prec_len = 0;
	if (uint_len < puts_len)
	{
		puts_prec_len = puts_len - uint_len;
		if (ftp_puts_flags(info, 0) == -1)
			return (-1);
		if (ftp_puts_char('0', puts_prec_len) == -1)
			return (-1);
		if (write(1, uint_str, (puts_len - puts_prec_len)) == -1)
			return (-1);
	}
	else
	{
		if (ftp_puts_flags(info, 0) == -1)
			return (-1);
		if (write(1, uint_str, uint_len) == -1)
			return (-1);
	}
	return (1);
}

int	puts_x(char *uint_str, t_fmt_info *info, size_t uint_len, size_t puts_len)
{
	size_t	sharp_len;

	sharp_len = 0;
	if (info->bit_flag & (1 << 0))
		sharp_len = 2;
	if (info->conversion == 'x')
		uint_str = ftp_str_tolower(uint_str);
	if ((puts_len + sharp_len) < (size_t)info->width)
	{
		if (ftp_fputs_x(uint_str, info, uint_len, puts_len) == -1)
			return (-1);
	}
	else
		if (puts_not_width(uint_str, info, uint_len, puts_len) == -1)
			return (-1);
	return (1);
}

static size_t	adjust_info_puts_len(t_fmt_info *info,
		unsigned int uint, size_t *uint_len)
{
	size_t	puts_len;

	puts_len = 0;
	if (uint == 0)
		info->bit_flag &= ~(1 << 0);
	if ((info->precision != -1) && (*uint_len < (size_t)info->precision))
		puts_len = (size_t)info->precision;
	else if (uint == 0 && info->precision == 0)
	{
		puts_len = 0;
		*uint_len = 0;
	}
	else
		puts_len = *uint_len;
	return (puts_len);
}

int	ftp_conv_x(unsigned int uint, t_fmt_info *info, char *buf, size_t *p_len)
{
	size_t	buf_len;
	size_t	uint_len;
	size_t	puts_len;
	char	*uint_str;

	if (!uint)
		uint = 0;
	buf_len = ft_strlen(buf);
	uint_str = ftp_ull_itoa_base((unsigned long long)uint, 16, &uint_len);
	if (uint_str == NULL)
		return (-1);
	puts_len = adjust_info_puts_len(info, uint, &uint_len);
	if (ftp_check_len_count(p_len, buf_len, puts_len, info) == -1)
		return (ftp_free_null(&uint_str));
	if (write(1, buf, buf_len) == -1)
		return (ftp_free_null(&uint_str));
	if (puts_x(uint_str, info, uint_len, puts_len) == -1)
		return (ftp_free_null(&uint_str));
	(void)ftp_free_null(&uint_str);
	return (1);
}
