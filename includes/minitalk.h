/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:32:21 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/09/09 19:21:53 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include "ft_printf.h"
# include "libft.h"

# define FEW_ARGS 1
# define TOO_MANY_ARGS 2
# define NOT_NUMBER 3
# define NOT_USE_PID 4
# define FAILED_KILL 5
# define FAILED_SIGEMPTYSET 6
# define FAILED_SIGACTION 7

void	signal_receiver(void handler(int, siginfo_t *, void *));
void	validation_args(int argc, char **argv);
void	exit_write_error_message(int error_num, char *source);

#endif
