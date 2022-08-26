/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_puts_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:00:36 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/07/07 10:17:15 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	fput_flags_plus_space(t_fmt_info *info)
{
	if (info->bit_flag & (1 << 2))
	{
		if (write(1, "+", 1) == -1)
			return (-1);
		return (1);
	}
	else if (info->bit_flag & (1 << 3))
	{
		if (write(1, " ", 1) == -1)
			return (-1);
		return (1);
	}
	return (0);
}

static int	fputs_flag_sharp(t_fmt_info *info)
{
	if (info->bit_flag & (1 << 0))
	{
		if (info->conversion == 'X')
		{
			if (write(1, "0X", 2) == -1)
				return (-1);
		}
		else
			if (write(1, "0x", 2) == -1)
				return (-1);
		return (2);
	}
	return (0);
}

int	ftp_puts_flags(t_fmt_info *info, int flag)
{
	int	puts_len;

	puts_len = 0;
	if (flag == 0)
		puts_len = fputs_flag_sharp(info);
	else if (flag == 23)
		puts_len = fput_flags_plus_space(info);
	return (puts_len);
}
