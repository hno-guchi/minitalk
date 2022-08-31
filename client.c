/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:16:36 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/08/31 19:17:11 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include "ft_printf.h"

int	main(int argc, char **argv)
{
	(void)argc;
	kill((pid_t)atoi(argv[1]), SIGSEGV);
	ft_printf("success kill!!\n"); 
	return (0);
}
