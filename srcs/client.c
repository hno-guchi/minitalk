/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:16:36 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/09/08 18:22:30 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
			exit(1);
		i += 1;
	}
}

static void	send_message(pid_t pid, char *str)
{
	int				i;

	i = 0;
	while (str[i] != '\0')
	{
		send_char(pid, str[i]);
		i += 1;
	}
}

static bool	write_error_message(int error_num)
{
	ft_putstr_fd("\x1b[31mUsage: ./client: ", STDERR_FILENO);
	if (error_num == FEW_ARGS)
		ft_putstr_fd("Not enough arguments!\n\x1b[39m",
			STDERR_FILENO);
	if (error_num == TOO_MANY_ARGS)
		ft_putstr_fd("Too many arguments!\n\x1b[39m",
			STDERR_FILENO);
	if (error_num == NOT_NUMBER)
		ft_putstr_fd("Enter a number for the PID\n\x1b[39m",
			STDERR_FILENO);
	if (error_num == NOT_USE_PID)
		ft_putstr_fd("Not use a number for the PID\n\x1b[39m",
			STDERR_FILENO);
	return (false);
}

static bool	is_pid(pid_t server_pid)
{
	if (server_pid == 0)
		return (false);
	else if (kill(server_pid, 0) == -1)
		return (false);
	else
		return (true);
}

static bool	is_digits_argv(char *args_pid)
{
	int	i;

	i = 0;
	while (args_pid[i] != '\0')
	{
		if (ft_isdigit(args_pid[i]) == 0)
			return (false);
		i += 1;
	}
	return (true);
}

static bool	validation_args(int argc, char **argv)
{
	if (argc < 3)
		return (write_error_message(FEW_ARGS));
	else if (3 < argc)
		return (write_error_message(TOO_MANY_ARGS));
	else if (is_digits_argv(argv[1]) == false)
		return (write_error_message(NOT_NUMBER));
	else if (is_pid((pid_t)ft_atoi(argv[1])) == false)
		return (write_error_message(NOT_USE_PID));
	else
		return (true);
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	server_pid = 0;
	if (validation_args(argc, argv) == false)
		return (FAILED);
	server_pid = (pid_t)ft_atoi(argv[1]);
	send_message(server_pid, argv[2]);
	return (SUCCESS);
}
