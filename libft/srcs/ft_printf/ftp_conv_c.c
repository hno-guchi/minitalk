/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_conv_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:19:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/07/07 13:52:45 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ftp_conv_c(char c, t_fmt_info *info, char *buf, size_t *p_len)
{
	size_t	buf_len;

	buf_len = ft_strlen(buf);
	if (ftp_check_len_count(p_len, buf_len, 1, info) == -1)
		return (-1);
	if (write(1, buf, buf_len) == -1)
		return (-1);
	if (1 < (size_t)info->width)
	{
		if (ftp_fputs_c_s(&c, info, 1) == -1)
			return (-1);
	}
	else
		if (write(1, &c, 1) == -1)
			return (-1);
	return (1);
}
