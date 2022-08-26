/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:20:44 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/08/26 16:34:25 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	main()
{
	pid_t	server_pid;

	server_pid = getpid();

	ft_printf("server: [%d]\n", (int)server_pid);
	while(1);

	return (0);
}
