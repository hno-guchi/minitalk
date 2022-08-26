/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_select_conv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:51:51 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/07/07 14:32:06 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ftp_select_conv(va_list args, t_fmt_info *info, char *buf, size_t *p_len)
{
	int	error_flag;

	error_flag = 0;
	if (info->conversion == '%')
		error_flag = ftp_fputs_percent('%', info, buf, p_len);
	else if (info->conversion == 'c')
		error_flag = ftp_conv_c(va_arg(args, int), info, buf, p_len);
	else if (info->conversion == 's')
		error_flag = ftp_conv_s(va_arg(args, char *), info, buf, p_len);
	else if (info->conversion == 'd' || info->conversion == 'i')
		error_flag = ftp_conv_d_i(va_arg(args, int), info, buf, p_len);
	else if (info->conversion == 'u')
		error_flag = ftp_conv_u(
				va_arg(args, unsigned long long), info, buf, p_len);
	else if (info->conversion == 'p')
		error_flag = ftp_conv_p(va_arg(args, void *), info, buf, p_len);
	else if (info->conversion == 'x')
		error_flag = ftp_conv_x(va_arg(args, unsigned int), info, buf, p_len);
	else if (info->conversion == 'X')
		error_flag = ftp_conv_x(va_arg(args, unsigned int), info, buf, p_len);
	return (error_flag);
}
