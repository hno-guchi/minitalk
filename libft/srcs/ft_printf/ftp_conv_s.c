/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_conv_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:24:56 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/07/07 13:53:23 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ftp_conv_s(char *str, t_fmt_info *info, char *buf, size_t *p_len)
{
	size_t	buf_len;
	size_t	s_len;

	if (str == NULL)
		str = "(null)";
	buf_len = ft_strlen(buf);
	s_len = ft_strlen(str);
	if (info->precision != -1 && (size_t)info->precision < s_len)
		s_len = (size_t)info->precision;
	if (ftp_check_len_count(p_len, buf_len, s_len, info) == -1)
		return (-1);
	if (write(1, buf, buf_len) == -1)
		return (-1);
	if (s_len < (size_t)info->width)
	{
		if (ftp_fputs_c_s(str, info, s_len) == -1)
			return (-1);
	}
	else
		if (write(1, str, s_len) == -1)
			return (-1);
	return (1);
}
