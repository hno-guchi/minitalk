#include <unistd.h>
#include <stdio.h>

// pid_t	getpid(void);

/*
 * pid_t == int
 */

int	main(void)
{
	pid_t	process_id;

	process_id = getpid();
	printf("prcess_id : [%d]\n", process_id);
	exit();

	return (0);
}
