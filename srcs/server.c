/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:20:44 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/09/09 19:00:13 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	write_server_pid(void)
{
	ft_printf("\x1b[32mserver PID : [%d]\x1b[39m\n", getpid());
}

static void	initialize_catch_bit(int *i, unsigned char *uc)
{
	*i = 0;
	*uc = 0;
}

static void	write_uc(int *i, unsigned char *uc, siginfo_t *info)
{
	static pid_t	client_pid;

	write(1, uc, 1);
	initialize_catch_bit(i, uc);
	if (info->si_pid != 0)
	{
		client_pid = info->si_pid;
		if (kill(info->si_pid, SIGUSR1) == -1)
			exit_write_error_message(FAILED_KILL, "server");
	}
	else
		if (kill(client_pid, SIGUSR1) == -1)
			exit_write_error_message(FAILED_KILL, "server");
}

static void	signal_handler(int signal_num, siginfo_t *info, void *ucontext_ap)
{
	static int				i;
	static unsigned char	uc;

	(void)ucontext_ap;
	if ((signal_num - SIGUSR1) == 1)
		uc |= (1 << i);
	if (i == 7)
		write_uc(&i, &uc, info);
	else
		i += 1;
}

int	main(void)
{
	write_server_pid();
	signal_receiver(signal_handler);
	while (1)
		pause();
	return (0);
}
