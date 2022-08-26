/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_is_flags_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:35:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/06/28 14:36:49 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ftp_is_flags_count(const char *flag_set, const char c, size_t *index)
{
	int	bit_flag;
	int	i;
	int	flag_set_len;

	bit_flag = 0;
	i = 0;
	flag_set_len = ft_strlen(flag_set);
	while (i < flag_set_len)
	{
		if (flag_set[i] == c)
		{
			bit_flag |= (1 << i);
			*index += 1;
		}
		i += 1;
	}
	return (bit_flag);
}
