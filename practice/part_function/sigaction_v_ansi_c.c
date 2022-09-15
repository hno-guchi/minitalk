#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void	write_message(char *message)
{
	if (message == NULL)
		write(1, "\nNot message!!\n", 14);
	else
		write(1, message, strlen(message));
}

// sample 1
void	signal_handler(int signal_num)
{
	if (signal_num == SIGINT)
		write_message("\nCatch signal SIGINT!!\n");
	exit(1);
}

void	sa_initialize(struct sigaction *sa)
{
	memset(sa, 0, sizeof(struct sigaction));
	sa->sa_handler = signal_handler;
	sa->sa_flags = 0;
	if (sigemptyset(&sa->sa_mask) == -1)
		exit(1);
	if (sigaction(SIGINT, sa, NULL) == -1)
		exit(1);
}

int	main()
{
	struct sigaction	sa;

	sa_initialize(&sa);
	// sample 1
	while(1)
		pause();
	/*
	// sample 2
	while (count < 50)
		pause();
	write_message("\nfinish process!!\n");
	*/
	return (0);
}

/*
// sample 2
int	count = 0;
void	signal_handler(int signal_num)
{
	if (signal_num == SIGINT)
		write_message("\nCatch signal SIGINT!!\n");
	count += 25;
}
*/



