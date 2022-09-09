/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_receiver.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:51:55 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/09/09 19:21:12 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sa_initialize(struct sigaction *sa)
{
	if (sigemptyset(&sa->sa_mask) == -1)
		exit_write_error_message(FAILED_SIGEMPTYSET, "SIGNAL HANDLER");
	if (sigaction(SIGUSR1, sa, NULL) == -1)
		exit_write_error_message(FAILED_SIGACTION, "SIGNAL HANDLER");
	if (sigaction(SIGUSR2, sa, NULL) == -1)
		exit_write_error_message(FAILED_SIGACTION, "SIGNAL HANDLER");
}

void	signal_receiver(void handler(int, siginfo_t *, void *))
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sa_initialize(&sa);
}
