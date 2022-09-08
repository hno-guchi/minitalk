/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:20:44 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/09/08 18:57:11 by hnoguchi         ###   ########.fr       */
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

static bool	sa_initialize(struct sigaction *sa)
{
	if (sigemptyset(&sa->sa_mask) == -1)
		return (false);
	if (sigaction(SIGUSR1, sa, NULL) == -1)
		return (false);
	if (sigaction(SIGUSR2, sa, NULL) == -1)
		return (false);
	return (true);
}

static void	signal_handler(int signal_num, siginfo_t *info, void *ucontext_ap)
{
	static int				i;
	static unsigned char	uc;

	(void)info;
	(void)ucontext_ap;
	if ((signal_num - SIGUSR1) == 1)
		uc |= (1 << i);
	if (i == 7)
	{
		// write_and_prepare_next_signal(i, uc, info);
		write(1, &uc, 1);
		initialize_catch_bit(&i, &uc);
	}
	else
		i += 1;
}

static void	signal_receiver(void handler(int, siginfo_t *, void *))
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	if (sa_initialize(&sa) == false)
		exit(1);
}

int	main(void)
{
	write_server_pid();
	signal_receiver(signal_handler);
	while (1)
		pause();
	return (0);
}
