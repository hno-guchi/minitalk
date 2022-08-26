/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_str_tolower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:14:44 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/06/15 21:48:48 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*ftp_str_tolower(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		s[i] = ft_tolower(s[i]);
		i += 1;
	}
	return (s);
}
