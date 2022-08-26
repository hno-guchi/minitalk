/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_puts_not_conv_count.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:05:37 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/07/07 14:29:51 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

ssize_t	ftp_puts_not_conv_count(char *buf, size_t *p_len)
{
	size_t	buf_len;

	buf_len = ft_strlen(buf);
	if ((*p_len + buf_len) < INT_MAX)
	{
		if (write(1, buf, buf_len) == -1)
			return (-1);
		*p_len += buf_len;
		return (1);
	}
	return (-1);
}
