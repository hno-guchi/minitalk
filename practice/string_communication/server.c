#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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

/*
static void	write_message(char *message)
{
	if (message == NULL)
		write(1, "\nNot message!!\n", 14);
	else
		write(1, message, strlen(message));
}
*/

static void	write_server_pid(int pid)
{
	write(1, "server pid [", 12);
	ft_putnbr_fd(pid, 1);
	write(1, "]\n",2);
}

static void	initialize_index_and_uc(int *i, unsigned char *uc)
{
	*i = 0;
	*uc = 0;
}

static bool	sa_initialize(struct sigaction *sa)
{
	if (sigemptyset(&sa->sa_mask) == -1)
		return (false);
	if (sigaction(SIGUSR1, sa, NULL) == -1)
		return (false);
	if (sigaction(SIGUSR2, sa, NULL) == -1)
		return (false);
	return (true);
}

static void	signal_handler(int signal_num, siginfo_t *info, void *ucontext_ap)
{
	static int				i;
	static unsigned char	uc;

	(void)info;
	(void)ucontext_ap;
	if (i == 8)
		initialize_index_and_uc(&i, &uc);
	if ((signal_num - SIGUSR1) == 1)
		uc |= (1 << i);
	if (i == 7)
		write(1, &uc, 1);
	i += 1;
}

static void	signal_receiver(void handler(int, siginfo_t *, void *))
{
	struct sigaction	sa;

	memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	if (sa_initialize(&sa) == false)
		exit(1);
}

int	main()
{
	write_server_pid(getpid());
	signal_receiver(signal_handler);
	while (1)
		pause();
	return (0);
}
