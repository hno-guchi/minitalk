/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:34:31 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/09/09 11:58:57 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printf(const char *input, ...)
{
	int			error_flag;
	size_t		print_len;
	const char	*save;
	va_list		args;

	error_flag = 0;
	print_len = 0;
	save = ft_strdup(input);
	if (save == NULL)
		return (-1);
	va_start(args, input);
	error_flag = ftp_scanning_count(save, args, &print_len);
	va_end(args);
	free((char *)save);
	if (error_flag == -1)
		return (-1);
	return ((int)print_len);
}

/*
#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

int main(void)
{
	int		res = 0;
	int		ft_res = 0;

	// segmentation fault	 
	// res = printf(NULL);
	// ft_res = ft_printf(NULL);


	// %c = 0, %s = NULL
	printf("\n--- [01] printf(\"\"); --------\n");
	printf(" |    res = [%d]\n", printf(""));
	printf(" | ft_res = [%d]\n", ft_printf(""));

	printf("\n--- [02] %%c = -123 --------\n");
	printf(" |    res = [%d]\n", printf("   printf() = [%c]", -123));
	printf(" | ft_res = [%d]\n", ft_printf("ft_printf() = [%c]", -123));

	printf("\n--- [03] %%c = 0 --------\n");
	printf(" |    res = [%d]\n", printf("   printf() = [%c]", '0'));
	printf(" | ft_res = [%d]\n", ft_printf("ft_printf() = [%c]", '0'));

	printf("\n--- [04] %%c = 200 --------\n");
	printf(" |    res = [%d]\n", printf("   printf() = [%c]", -123));
	printf(" | ft_res = [%d]\n", ft_printf("ft_printf() = [%c]", -123));

	// segmentation fault
	// printf("\n--- [5] %%s = not value --------\n");
	// printf(" |    res = [%d]\n", printf("   printf() = [%s]"));
	// printf(" | ft_res = [%d]\n", ft_printf("ft_printf() = [%s]"));

	printf("\n--- [05] %%s = NULL --------\n");
	printf(" |    res = [%d]\n", printf("   printf() = [%s]", NULL));
	printf(" | ft_res = [%d]\n", ft_printf("ft_printf() = [%s]", NULL));

	printf("\n--- [06] %%p = NULL --------\n");
	printf(" |    res = [%d]\n", printf("   printf() = [%p]", NULL));
	printf(" | ft_res = [%d]\n", ft_printf("ft_printf() = [%p]", NULL));

	printf("\n--- [07] %%u = -4 --------\n");
	printf(" |    res = [%d]\n", printf("   printf() = [%u]", -4));
	printf(" | ft_res = [%d]\n", ft_printf("ft_printf() = [%u]", -4));

	printf("\n--- [08] %%x = NULL --------\n");
	printf(" |    res = [%d]\n", printf("   printf() = [%x]", NULL));
	printf(" | ft_res = [%d]\n", ft_printf("ft_printf() = [%x]", NULL));

	printf("\n--- [09] %%x = -1 --------\n");
	printf(" |    res = [%d]\n", printf("   printf() = [%x]", -1));
	printf(" | ft_res = [%d]\n", ft_printf("ft_printf() = [%x]", -1));

	printf("\n--- [10] %%x = 0 --------\n");
	printf(" |    res = [%d]\n", printf("   printf() = [%x]", 0));
	printf(" | ft_res = [%d]\n", ft_printf("ft_printf() = [%x]", 0));

	printf("\n--- [11] %%%%d = 10 --------\n");
	printf(" |    res = [%d]\n", printf("   printf() = [%%%d]", 10));
	printf(" | ft_res = [%d]\n", ft_printf("ft_printf() = [%%%d]", 10));

	printf("\n--- [12] %%d%% = 10 --------\n");
	printf(" |    res = [%d]\n", printf("   printf() = [%%d%%]"));
	printf(" | ft_res = [%d]\n", ft_printf("ft_printf() = [%%d%%]"));

	// Output char Over INT_MAX
	char	*intmax_str;
	intmax_str = (char *)calloc(INT_MAX - 15, sizeof(char));
	intmax_str = memset(intmax_str, 'A', INT_MAX - 16);

	printf("\n--- [13] %%s, str_size = [INT_MAX - 16] --------\n");
	printf("|    res = [%d]\n",
			printf("   printf%s%s]", "() = [ ", intmax_str));
	printf("| ft_res = [%d]\n",
			ft_printf("ft_printf%s%s]", "() = [ ", intmax_str));

	printf("\n--- [14] %%u = LONG_MAX --------\n");
	printf(" |    res = [%d]\n", printf("   printf[%u]", LONG_MAX));
	printf(" | ft_res = [%d]\n", ft_printf("ft_printf[%u]", LONG_MAX));

	printf("\n--- [15] %%u = LONG_MIN --------\n");
	printf(" |    res = [%d]\n", printf("   printf[%u]", LONG_MIN));
	printf(" | ft_res = [%d]\n", ft_printf("ft_printf[%u]", LONG_MIN));

	printf("\n--- [16] %%u = UINT_MAX --------\n");
	printf(" |    res = [%d]\n", printf("   printf[%u]", UINT_MAX));
	printf(" | ft_res = [%d]\n", ft_printf("ft_printf[%u]", UINT_MAX));

	printf("\n--- [17] %%u = ULONG_MAX --------\n");
	printf(" |    res = [%d]\n", printf("   printf[%u]", ULONG_MAX));
	printf(" | ft_res = [%d]\n", ft_printf("ft_printf[%u]", ULONG_MAX));

	printf("\n--- [18] %%u = U9223372036854775807LL --------\n");
	printf(" |    res = [%d]\n",
			printf("   printf[%u]", 9223372036854775807LL));
	printf(" | ft_res = [%d]\n",
			ft_printf("ft_printf[%u]", 9223372036854775807LL));

	printf("\n--- [19] %%u, all test --------\n");
	printf(" %u %u %u %u %u %u %u \n",
			INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf(" %u %u %u %u %u %u %u \n",
			INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

	free(intmax_str);
	system("leaks -q a.out");
    return (0);
}
*/
