/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_fputs_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 12:16:22 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/07/07 15:57:57 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	puts_prec_str(char *uint_str, size_t uint_len, size_t puts_len)
{
	size_t	puts_prec_len;

	puts_prec_len = puts_len - uint_len;
	if (ftp_puts_char('0', puts_prec_len) == -1)
		return (-1);
	if (write(1, uint_str, (puts_len - puts_prec_len)) == -1)
		return (-1);
	return (1);
}

static int	puts_nflag_minus(char *uint_str,
		t_fmt_info *info, size_t uint_len, size_t puts_len)
{
	int	flag_len;

	flag_len = ftp_puts_flags(info, 0);
	if (flag_len == -1)
		return (-1);
	if ((0 < info->width) && (info->bit_flag & (1 << 4)))
		if (ftp_puts_char('0',
				(size_t)(info->width - flag_len) - uint_len) == -1)
			return (-1);
	if (uint_len < puts_len)
	{
		if (puts_prec_str(uint_str, uint_len, puts_len) == -1)
			return (-1);
	}
	else
		if (write(1, uint_str, uint_len) == -1)
			return (-1);
	return (1);
}

static int	puts_flag_minus(char *uint_str,
		t_fmt_info *info, size_t uint_len, size_t puts_len)
{
	int	flag_len;

	flag_len = ftp_puts_flags(info, 0);
	if (flag_len == -1)
		return (-1);
	if (uint_len < puts_len)
	{
		if (puts_prec_str(uint_str, uint_len, puts_len) == -1)
			return (-1);
	}
	else
		if (write(1, uint_str, uint_len) == -1)
			return (-1);
	if ((0 < info->width) && !(info->bit_flag & (1 << 4)))
		if (ftp_puts_char(' ',
				(size_t)(info->width - flag_len) - puts_len) == -1)
			return (-1);
	return (1);
}

int	ftp_fputs_x(char *uint_str, t_fmt_info *info, size_t sign, size_t puts_len)
{
	int	flag_len;

	flag_len = 0;
	if (info->bit_flag & (1 << 0))
		flag_len = 2;
	if (info->bit_flag & (1 << 1))
	{
		if (puts_flag_minus(uint_str, info, sign, puts_len) == -1)
			return (-1);
	}
	else
	{
		if ((0 < info->width) && !(info->bit_flag & (1 << 4)))
			if (ftp_puts_char(' ',
					(size_t)(info->width - flag_len) - puts_len) == -1)
				return (-1);
		if (puts_nflag_minus(uint_str, info, sign, puts_len) == -1)
			return (-1);
	}
	return (1);
}
