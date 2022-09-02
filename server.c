/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:20:44 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/09/02 12:38:24 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	count = 0;

static void	write_server_pid(int pid)
{
	write(1, "server pid [", 12);
	ft_putnbr_fd(pid, 1);
	write(1, "]\n",2);
}

static void	write_message(char *message)
{
	if (message == NULL)
		write(1, "\nNot message!!\n", 14);
	else
		write(1, message, ft_strlen(message));
}

static void	signal_handler(int signal_num)
{
	if (signal_num == SIGINT)
		count += 100;
}

static void	sa_initialize(struct sigaction *sa)
{
	if (-1 == sigemptyset(&sa->sa_mask))
		exit(1);
	sa->sa_handler = signal_handler;
	sa->sa_flags = 0;

	if (-1 == sigaction(SIGINT, sa, NULL))
		exit(1);
}

int	main()
{
	pid_t				server_pid;
	struct sigaction	sa;

	server_pid = getpid();
	write_server_pid(server_pid);
	sa_initialize(&sa);

	while(count < 50);
	write_message("\nFinish!!\n");

	return (0);
}
