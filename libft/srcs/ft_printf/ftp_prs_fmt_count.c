/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_prs_fmt_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:37:08 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/07/06 21:24:51 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	check_parsed_format_info(t_fmt_info *info)
{
	char	conversion;

	conversion = (char)info->conversion;
	if (ft_strchr("csdiu", conversion) != NULL)
		info->bit_flag &= ~(1 << 0);
	if (ft_strchr("cspuxX", conversion) != NULL)
	{
		info->bit_flag &= ~(1 << 2);
		info->bit_flag &= ~(1 << 3);
		if (info->conversion == 'p')
			info->bit_flag |= (1 << 0);
	}
	if ((info->precision != -1 && ft_strchr("pdiuxX", conversion) != NULL)
		|| (info->bit_flag & (1 << 1)))
		info->bit_flag &= ~(1 << 4);
	if (info->bit_flag & (1 << 2))
		info->bit_flag &= ~(1 << 3);
	if (info->width & (1 << 31))
		info->width &= ~(1 << 31);
	if (info->precision & (1 << 31))
		info->precision = -1;
}

static size_t	prs_fmt_count(const char *save, va_list args, t_fmt_info *info)
{
	size_t	i;

	i = 0;
	if (ft_strchr("#-+ 0", save[i]) != NULL)
		info->bit_flag |= ftp_is_flags_count("#-+ 0", save[i], &i);
	else if (ft_isdigit(save[i]) || save[i] == '*')
		i = ftp_prs_wth_count(&save[i], args, info);
	else if (save[i] == '.')
		i = ftp_prs_prec_count(&save[i], args, info);
	return (i);
}

static void	initialize_format_info(t_fmt_info *info)
{
	info->bit_flag = 0;
	info->width = 0;
	info->precision = -1;
	info->conversion = 0;
}

size_t	ftp_prs_fmt_count(const char *save, va_list args, t_fmt_info *info)
{
	size_t	i;
	size_t	move_i;

	i = 1;
	move_i = 0;
	initialize_format_info(info);
	while (save[i] != '\0')
	{
		if (ft_strchr(CONVERSIONS, save[i]) != NULL)
		{
			info->conversion = save[i];
			i += 1;
			break ;
		}
		move_i = prs_fmt_count(&save[i], args, info);
		if (move_i != 0)
			i += move_i;
		else
			i += 1;
	}
	check_parsed_format_info(info);
	return (i);
}

/*
#include <stdio.h>
void	check_function_printf(const char *input, ...)
{
	ssize_t		move_i;
	const char	*save;
	va_list		args;
	t_fmt_info	*format_info;
	// s_fmt_info	*format_info;

	save = ft_strdup(input);
	format_info = (t_fmt_info *)malloc(1 * sizeof(t_fmt_info));
	if (save == NULL || format_info == NULL)
		return ;
	va_start(args, input);
	move_i = ftp_parse_format(save, args, format_info);
	va_end(args);
	printf("\n----- save[%s] -----\n", save);
	printf("move_i     = [%d]\n", move_i);
	size_t	n = 0;
	printf("bit_flag   = [%d] = [%s]\n",
		format_info->bit_flag, ftp_ull_itoa_base(format_info->bit_flag, 2, &n));
	printf("width      = [%d]\n", format_info->width);
	printf("precision  = [%d]\n", format_info->precision);
	printf("conversion = [%c]\n", (char)format_info->conversion);
	printf("----------------------\n");
	free((char *)save);
}

int	main(void)
{
	// check conversion
	check_function_printf("%c");
	check_function_printf("%s");
	check_function_printf("%d");
	check_function_printf("%i");
	check_function_printf("%u");
	check_function_printf("%p");
	check_function_printf("%x");
	check_function_printf("%X");
	check_function_printf("%%");

	// check flags
	check_function_printf("%#-+ 0d");
	check_function_printf("%#d");
	check_function_printf("%-d");
	check_function_printf("%+d");
	check_function_printf("% d");
	check_function_printf("%0d");

	// check flags combination
	check_function_printf("%-0d");
	check_function_printf("%0-d");
	check_function_printf("%+ d");
	check_function_printf("% +d");

	// check flags ellegal
	check_function_printf("%###---+++    000d");
	check_function_printf("%-0# #-++-#+ 00 +d");

	// check width
	check_function_printf("%-100d");
	check_function_printf("%0d");
	check_function_printf("%100d");
	check_function_printf("%-2147483648d");
	check_function_printf("%2147483647d");
	check_function_printf("%2147483648d");
	check_function_printf("%2147483649d");

	// check precision
	check_function_printf("%.-100d");
	check_function_printf("%.0d");
	check_function_printf("%.100d");
	check_function_printf("%.-2147483648d");
	check_function_printf("%.2147483647d");
	check_function_printf("%.2147483648d");
	check_function_printf("%.2147483649d");

	// check precision
	check_function_printf("%.-100d");
	check_function_printf("%.0d");
	check_function_printf("%.008d");
	check_function_printf("%.100d");
	check_function_printf("%.-2147483648d");
	check_function_printf("%.2147483647d");
	check_function_printf("%.2147483648d");
	check_function_printf("%.2147483649d");

	return (0);
}
*/
