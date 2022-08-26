/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_puts_character.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 20:32:35 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/07/07 08:56:38 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

ssize_t	ftp_puts_char(char c, size_t len)
{
	size_t	i;
	char	*zero_str;

	i = 0;
	if (100 < len)
	{
		zero_str = (char *)ft_calloc(len + 1, sizeof(char));
		if (zero_str == NULL)
			return (-1);
		(void)ft_memset(zero_str, c, len);
		if (write(1, zero_str, len) == -1)
			return (ftp_free_null(&zero_str));
		i = len;
		(void)ftp_free_null(&zero_str);
	}
	else
	{
		while (i < len)
		{
			if (write(1, &c, 1) == -1)
				return (-1);
			i += 1;
		}
	}
	return (i);
}
