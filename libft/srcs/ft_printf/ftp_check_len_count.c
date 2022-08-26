/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_check_len_count.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:36:45 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/07/07 13:49:43 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static size_t	sum_len_bit_flag(t_fmt_info *info)
{
	size_t	total_len;
	size_t	flag_sharp;
	size_t	flag_plus;
	size_t	flag_space;

	total_len = 0;
	flag_sharp = 0;
	flag_plus = 0;
	flag_space = 0;
	if ((info->bit_flag & (1 << 0))
		&& ft_strchr("pxX", info->conversion) != NULL)
		flag_sharp = 2;
	if (info->bit_flag & (1 << 2))
		flag_plus = 1;
	else if (info->bit_flag & (1 << 3))
		flag_space = 1;
	total_len = flag_sharp + flag_plus + flag_space;
	return (total_len);
}

int	ftp_check_len_count(size_t *p, size_t buf, size_t va, t_fmt_info *info)
{
	size_t	flag_len;

	flag_len = sum_len_bit_flag(info);
	if ((va + flag_len) < (size_t)info->width)
	{
		if ((INT_MAX - 1) <= (*p + buf + (size_t)info->width))
			return (-1);
		*p += buf + (size_t)info->width;
	}
	else
	{
		if ((INT_MAX - 1) <= (*p + buf + va + flag_len))
			return (-1);
		*p += buf + va + flag_len;
	}
	return (1);
}
