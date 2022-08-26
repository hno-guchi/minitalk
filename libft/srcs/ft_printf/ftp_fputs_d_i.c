/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_fputs_d_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 20:34:35 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/07/07 16:03:33 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	puts_prec_str(char *i_str,
		size_t i_len, ssize_t sign, size_t puts_len)
{
	size_t	puts_prec_len;

	puts_prec_len = puts_len - i_len;
	if (ftp_puts_char('0', puts_prec_len) == -1)
		return (-1);
	if (write(1, i_str, (puts_len - sign - puts_prec_len)) == -1)
		return (-1);
	return (1);
}

static int	puts_nflag_minus(char *i_str,
		t_fmt_info *info, size_t i_len, size_t puts_len)
{
	size_t	sign;

	sign = 0;
	if (ftp_puts_flags(info, 23) == -1)
		return (-1);
	else if (i_str[0] == '-')
		if (write(1, &i_str[sign++], 1) == -1)
			return (-1);
	if ((0 < info->width) && (info->bit_flag & (1 << 4)))
		if (ftp_puts_char('0', (size_t)info->width - i_len) == -1)
			return (-1);
	if (i_len < puts_len)
	{
		if (puts_prec_str(&i_str[sign], i_len, sign, puts_len) == -1)
			return (-1);
	}
	else
		if (write(1, &i_str[sign], (i_len - sign)) == -1)
			return (-1);
	return (1);
}

static int	puts_flag_minus(char *i_str,
		t_fmt_info *info, size_t i_len, size_t puts_len)
{
	size_t	sign;

	sign = 0;
	if (ftp_puts_flags(info, 23) == -1)
		return (-1);
	if (i_len < puts_len)
	{
		if (i_str[0] == '-')
			if (write(1, &i_str[sign++], 1) == -1)
				return (-1);
		if (puts_prec_str(&i_str[sign], i_len, sign, puts_len) == -1)
			return (-1);
	}
	else
		if (write(1, i_str, i_len) == -1)
			return (-1);
	return (1);
}

int	ftp_fputs_d_i(char *i_str, t_fmt_info *info, size_t i_len, size_t puts_len)
{
	size_t	flag_len;

	flag_len = 0;
	if ((info->bit_flag & (1 << 2)) || (info->bit_flag & (1 << 3)))
		flag_len = 1;
	if (info->bit_flag & (1 << 1))
	{
		if (puts_flag_minus(i_str, info, i_len, puts_len) == -1)
			return (-1);
		if ((0 < info->width) && !(info->bit_flag & (1 << 4)))
			if (ftp_puts_char(' ',
					(size_t)info->width - flag_len - puts_len) == -1)
				return (-1);
	}
	else
	{
		if ((0 < info->width) && !(info->bit_flag & (1 << 4)))
			if (ftp_puts_char(' ',
					(size_t)info->width - flag_len - puts_len) == -1)
				return (-1);
		if (puts_nflag_minus(i_str, info, i_len, puts_len) == -1)
			return (-1);
	}
	return (1);
}
