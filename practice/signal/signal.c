#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

// https://en-junior.com/sigaction-signal/

static void	ft_putnbr_fd(int n, int fd)
{
	long long int	ln;
	char			c;

	ln = (long long int)n;
	if (ln == 0)
		write(1, "0", 1);
	else
	{
		if (ln < 0)
		{
			write(1, "-", 1);
			ln *= -1;
		}
		if (9 < ln)
		{
			ft_putnbr_fd(ln / 10, fd);
			ft_putnbr_fd(ln % 10, fd);
		}
		else
		{
			c = ln + '0';
			write(1, &c, 1);
		}
	}
	return ;
}

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
		// psignal(SIGINT, "SIGINT");
		write_message("\nfinish process!!\n");
	exit(1);
}

int	main(void)
{
	signal(SIGINT, signal_handler);
	while(1);
	return (0);
}
