/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_atoi_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:14:12 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/06/28 15:44:34 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_isspace(int c);
static int	change_format(const char *str, int sign, size_t *digit);

// int	ft_atoi(const char *str)
int	ftp_atoi_count(const char *str, size_t *digit)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (ft_isspace(str[i]) == 1)
		i += 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign = -1;
			*digit += 1;
		}
		i += 1;
	}
	num = change_format(&str[i], sign, digit);
	return (num);
}

static int	ft_isspace(int c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

// static int	change_format(const char *str, int sign)
static int	change_format(const char *str, int sign, size_t *digit)
{
	int			i;
	long long	num;

	i = 0;
	num = 0;
	while (ft_isdigit(str[i]) == 1)
	{
		if (num <= ((LONG_MAX - (str[i] - '0')) / 10))
			num = (num * 10) + (str[i] - '0');
		else
		{
			if (sign == -1)
				return ((int)LONG_MIN);
			else
				return ((int)LONG_MAX);
		}
		i += 1;
	}
	num *= (long long )sign;
	*digit += i;
	return ((int)num);
}
