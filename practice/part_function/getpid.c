#include <unistd.h>
#include <stdio.h>

// pid_t	getpid(void); (pid_t == int)

int	main(void)
{
	printf("prcess_id : [%d]\n", (int)getpid());
	return (0);
}
