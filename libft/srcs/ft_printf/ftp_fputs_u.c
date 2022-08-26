/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_fputs_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 12:16:22 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/07/07 16:02:18 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	puts_prec_str(char *uint_str,
		size_t uint_len, size_t puts_len)
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
	if ((0 < info->width) && (info->bit_flag & (1 << 4)))
		if (ftp_puts_char('0', (size_t)info->width - uint_len) == -1)
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

static int	puts_flag_minus(char *uint_str, size_t uint_len, size_t puts_len)
{
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

int	ftp_fputs_u(char *uint_str,
		t_fmt_info *info, size_t uint_len, size_t puts_len)
{
	if (info->bit_flag & (1 << 1))
	{
		if (puts_flag_minus(uint_str, uint_len, puts_len) == -1)
			return (-1);
		if ((0 < info->width) && !(info->bit_flag & (1 << 4)))
			if (ftp_puts_char(' ',
					(size_t)info->width - puts_len) == -1)
				return (-1);
	}
	else
	{
		if ((0 < info->width) && !(info->bit_flag & (1 << 4)))
			if (ftp_puts_char(' ',
					(size_t)info->width - puts_len) == -1)
				return (-1);
		if (puts_nflag_minus(uint_str, info, uint_len, puts_len) == -1)
			return (-1);
	}
	return (1);
}
