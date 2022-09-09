/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:08:45 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/09/09 18:44:53 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	validation_args(int argc, char **argv)
{
	if (argc < 3)
		exit_write_error_message(FEW_ARGS, "client");
	else if (3 < argc)
		exit_write_error_message(TOO_MANY_ARGS, "client");
	else if (is_digits_argv(argv[1]) == false)
		exit_write_error_message(NOT_NUMBER, "client");
	else if (is_pid((pid_t)ft_atoi(argv[1])) == false)
		exit_write_error_message(NOT_USE_PID, "client");
}
