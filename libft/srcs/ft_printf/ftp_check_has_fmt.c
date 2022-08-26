/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_check_has_fmt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:26:31 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/07/07 14:32:38 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

ssize_t	ftp_check_has_fmt(const char *save,
		va_list args, char *buf, size_t *p_len)
{
	ssize_t		move_i;
	t_fmt_info	*format_info;

	move_i = 0;
	format_info = (t_fmt_info *)malloc(sizeof(t_fmt_info) * 1);
	if (format_info == NULL)
		return (-1);
	if (save[0] != '%')
		move_i = ftp_puts_not_conv_count(buf, p_len);
	else
	{
		move_i = ftp_prs_fmt_count(save, args, format_info);
		if (ftp_select_conv(args, format_info, buf, p_len) == -1)
		{
			free(format_info);
			return (-1);
		}
	}
	free(format_info);
	return (move_i);
}
