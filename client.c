/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:16:36 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/08/26 11:22:04 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

int	main(int argc, char **argv)
{
	(void)argc;
	kill((pid_t)atoi(argv[1]), SIGSEGV);

	return (0);
}
