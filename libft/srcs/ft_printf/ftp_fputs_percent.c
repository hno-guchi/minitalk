/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_fputs_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 20:50:57 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/07/07 12:02:33 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ftp_fputs_percent(char c, t_fmt_info *info, char *buf, size_t *p_len)
{
	size_t	buf_len;

	(void)info;
	buf_len = ft_strlen(buf);
	if ((*p_len + 1) < INT_MAX)
	{
		if (write(1, buf, buf_len) == -1)
			return (-1);
		if (write(1, &c, 1) == -1)
			return (-1);
		*p_len += (buf_len + 1);
		return (1);
	}
	else
		return (-1);
}
