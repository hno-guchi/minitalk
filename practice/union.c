#include <stdio.h>
#include <limits.h>

union number_u {
	int				si_num;
	unsigned int	ui_num;
	long			l_num;
	long long		ll_num;
} u_number;

int	main()
{
	u_number;

	u_number.si_num = INT_MAX;
	u_number.ui_num = UINT_MAX;
	// u_number.l_num = LONG_MAX;
	// u_number.ll_num = LLONG_MAX;

	printf("u_number.si_num = [%d]\n", u_number.si_num);
	printf("u_number.ui_num = [%u]\n", u_number.ui_num);
	// printf("u_number.l_num  = [%d]\n", u_number.l_num);
	// printf("u_number.ll_num = [%d]\n", u_number.ll_num);
	
}
