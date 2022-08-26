/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_prs_prec_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:27:06 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/06/29 18:50:11 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

size_t	ftp_prs_prec_count(const char *save, va_list args, t_fmt_info *info)
{
	size_t	i;

	i = 0;
	if (save[i] == '.')
	{
		i += 1;
		if (ft_isdigit(save[i]))
			info->precision = ftp_atoi_count(&save[i], &i);
		else if (save[i] == '*')
		{
			info->precision = va_arg(args, int);
			if (info->precision < 0)
				info->precision = -1;
			i += 1;
		}
		else
			info->precision = 0;
	}
	return (i);
}
