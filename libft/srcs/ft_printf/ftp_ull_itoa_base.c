/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_ull_itoa_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:31:37 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/06/15 21:52:03 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	*change_base(unsigned long long ull, int b, char *s, size_t n)
{
	while (ull != 0)
	{
		if ((ull % b) < 10)
			s[n - 1] = (ull % b) + '0';
		else
			s[n - 1] = (ull % b) + '7';
		ull = ull / b;
		n -= 1;
	}
	return (s);
}

char	*ftp_ull_itoa_base(unsigned long long ull, int base, size_t *len)
{
	char				*ull_str;
	unsigned long long	ull_clone;

	*len = 0;
	ull_clone = ull;
	if (ull == 0)
	{
		*len += 1;
		return (ft_strdup("0"));
	}
	while (ull != 0)
	{
		ull = ull / base;
		*len += 1;
	}
	ull_str = ft_calloc(*len + 1, sizeof(char));
	if (ull_str == NULL)
		return (NULL);
	ull_str = change_base(ull_clone, base, ull_str, *len);
	return (ull_str);
}
