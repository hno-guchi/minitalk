/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_write_error_message.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:29:45 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/09/09 19:24:21 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	write_source_name(char *src)
{
	ft_putstr_fd("\x1b[31mUsage: ./", STDERR_FILENO);
	ft_putstr_fd(src, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
}

void	exit_write_error_message(int error_num, char *source)
{
	write_source_name(source);
	if (error_num == FEW_ARGS)
		ft_putstr_fd("Not enough arguments!\n\x1b[39m",
			STDERR_FILENO);
	else if (error_num == TOO_MANY_ARGS)
		ft_putstr_fd("Too many arguments!\n\x1b[39m",
			STDERR_FILENO);
	else if (error_num == NOT_NUMBER)
		ft_putstr_fd("Enter a number for the PID\n\x1b[39m",
			STDERR_FILENO);
	else if (error_num == NOT_USE_PID)
		ft_putstr_fd("Not use a number for the PID\n\x1b[39m",
			STDERR_FILENO);
	else if (error_num == FAILED_KILL)
		ft_putstr_fd("Failed kill\n\x1b[39m",
			STDERR_FILENO);
	else if (error_num == FAILED_SIGEMPTYSET)
		ft_putstr_fd("Failed sigemptyset().\n\x1b[39m",
			STDERR_FILENO);
	else if (error_num == FAILED_SIGACTION)
		ft_putstr_fd("Failed sigaction().\n\x1b[39m",
			STDERR_FILENO);
	exit(EXIT_FAILURE);
}
