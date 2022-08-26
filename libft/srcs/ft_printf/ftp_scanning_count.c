/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_scanning_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:18:52 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/07/07 14:27:41 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*ftp_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	chr;

	i = 0;
	chr = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == chr)
			return ((char *)&s[i]);
		i += 1;
	}
	return ((char *)&s[i]);
}

static char	*substr_count(const char *str, size_t *s_len)
{
	char	*percent_p;
	char	*cut_str;

	percent_p = ftp_strchr(str, '%');
	*s_len = percent_p - str;
	cut_str = ft_substr(str, 0, *s_len);
	return (cut_str);
}

int	ftp_scanning_count(const char *save, va_list args, size_t *print_len)
{
	size_t	i;
	size_t	buf_len;
	ssize_t	move_i;
	char	*buf;

	i = 0;
	while (save[i] != '\0')
	{
		buf_len = 0;
		move_i = 0;
		buf = substr_count(&save[i], &buf_len);
		if (buf == NULL)
			return (-1);
		i += buf_len;
		move_i = ftp_check_has_fmt(&save[i], args, buf, print_len);
		(void)ftp_free_null(&buf);
		if (move_i == -1)
			return (-1);
		if (save[i] != '\0')
			i += (size_t)move_i;
	}
	return (1);
}
