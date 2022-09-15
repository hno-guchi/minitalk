#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

// https://en-junior.com/sigaction-signal/

static void	write_message(char *message)
{
	if (message == NULL)
		write(1, "\nNot message!!\n", 14);
	else
		write(1, message, strlen(message));
}

static void	signal_handler(int signal_num)
{
	if (signal_num == SIGINT)
		write_message("\nCatch signal SIGINT!!\n");
	exit(1);
}

int	main(void)
{
	signal(SIGINT, signal_handler);
	while(1)
		pause();
	return (0);
}
