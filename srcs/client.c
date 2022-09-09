/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:16:36 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/09/09 19:24:02 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t	g_catch_signal_flag;

static void	send_char(pid_t pid, char c)
{
	int				i;
	int				bit;
	unsigned char	uc;

	i = 0;
	bit = 0;
	uc = (unsigned char)c;
	while (i < 8)
	{
		usleep(50);
		bit = (uc >> i) & 0x01;
		if (kill(pid, SIGUSR1 + bit) == -1)
			exit_write_error_message(FAILED_KILL, "client");
		i += 1;
	}
}

static void	send_message(pid_t pid, char *str)
{
	int				i;

	i = 0;
	g_catch_signal_flag = 1;
	while (str[i] != '\0')
	{
		while (g_catch_signal_flag == 0)
			pause();
		send_char(pid, str[i]);
		i += 1;
		g_catch_signal_flag = 0;
	}
}

static void	signal_handler(int signal_num, siginfo_t *info, void *ucontext_ap)
{
	(void)info;
	(void)ucontext_ap;
	if (signal_num == SIGUSR1)
		g_catch_signal_flag = 1;
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	validation_args(argc, argv);
	server_pid = (pid_t)ft_atoi(argv[1]);
	signal_receiver(signal_handler);
	send_message(server_pid, argv[2]);
	return (0);
}
