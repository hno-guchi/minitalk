/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_fputs_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 12:16:22 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/07/07 16:00:47 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	puts_prec_str(char *ullp_str,
		size_t ullp_len, size_t puts_len)
{
	size_t	puts_prec_len;

	puts_prec_len = puts_len - ullp_len;
	if (ftp_puts_char('0', puts_prec_len) == -1)
		return (-1);
	if (write(1, ullp_str, (puts_len - puts_prec_len)) == -1)
		return (-1);
	return (1);
}

static int	puts_nflag_minus(char *ullp_str,
		t_fmt_info *info, size_t ullp_len, size_t puts_len)
{
	if (write(1, "0x", 2) == -1)
		return (-1);
	if ((0 < info->width) && (info->bit_flag & (1 << 4)))
		if (ftp_puts_char('0', (size_t)info->width - 2 - ullp_len) == -1)
			return (-1);
	if (ullp_len < puts_len)
	{
		if (puts_prec_str(ullp_str, ullp_len, puts_len) == -1)
			return (-1);
	}
	else
		if (write(1, ullp_str, ullp_len) == -1)
			return (-1);
	return (1);
}

static int	puts_flag_minus(char *ullp_str, size_t ullp_len, size_t puts_len)
{
	if (write(1, "0x", 2) == -1)
		return (-1);
	if (ullp_len < puts_len)
	{
		if (puts_prec_str(ullp_str, ullp_len, puts_len) == -1)
			return (-1);
	}
	else
		if (write(1, ullp_str, ullp_len) == -1)
			return (-1);
	return (1);
}

int	ftp_fputs_p(char *ullp_str,
		t_fmt_info *info, size_t ullp_len, size_t puts_len)
{
	if (info->bit_flag & (1 << 1))
	{
		if (puts_flag_minus(ullp_str, ullp_len, puts_len) == -1)
			return (-1);
		if ((0 < info->width) && !(info->bit_flag & (1 << 4)))
			if (ftp_puts_char(' ', (size_t)info->width - 2 - puts_len) == -1)
				return (-1);
	}
	else
	{
		if ((0 < info->width) && !(info->bit_flag & (1 << 4)))
			if (ftp_puts_char(' ', (size_t)info->width - 2 - puts_len) == -1)
				return (-1);
		if (puts_nflag_minus(ullp_str, info, ullp_len, puts_len) == -1)
			return (-1);
	}
	return (1);
}
