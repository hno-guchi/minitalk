/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:16:36 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/09/01 11:22:22 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include "ft_printf.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (ft_printf("Not Argument server PID\n"));
	kill((pid_t)atoi(argv[1]), SIGSEGV);
	ft_printf("success kill!!\n"); 
	return (0);
}
