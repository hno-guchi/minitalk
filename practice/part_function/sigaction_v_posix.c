#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

static void	write_message(char *message)
{
	if (message == NULL)
		write(1, "\nNot message!!\n", 14);
	else
		write(1, message, strlen(message));
}

// sample 1
void	signal_handler(int signal_num, siginfo_t *info, void *ucontext_ap)
{
	(void)info;
	(void)ucontext_ap;
	if (signal_num == SIGINT)
		write_message("\nCatch signal SIGINT!!\n");
	exit(1);
}

void	sa_initialize(struct sigaction *sa)
{
	if (sigemptyset(&sa->sa_mask) == -1)
		exit(1);
	if (sigaction(SIGINT, sa, NULL) == -1)
		exit(1);
}

static void	signal_receiver(void handler(int, siginfo_t *, void *))
{
	struct sigaction	sa;

	memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sa_initialize(&sa);
}

int	main()
{
	signal_receiver(signal_handler);
	// sample 1
	while (1)
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


static void	write_server_pid(int pid)
{
	write(1, "server pid [", 12);
	ft_putnbr_fd(pid, 1);
	write(1, "]\n",2);
}

void	signal_handler(int signal_num, siginfo_t *info, void *ucontext_ap)
{
	if (signal_num == SIGINT)
	{
		write(1, "\n", 1);
		write_server_pid(getpid());
		write_message("----- signal_handler() ------\n");
		write_message("info->si_signo : [");
		ft_putnbr_fd(info->si_signo, 1);
		write_message("]\n");

		write_message("info->si_errno : [");
		ft_putnbr_fd(info->si_errno, 1);
		write_message("]\n");

		write_message("info->si_code : [");
		ft_putnbr_fd(info->si_code, 1);
		write_message("]\n");

		write_message("info->si_pid : [");
		ft_putnbr_fd(info->si_pid, 1);
		write_message("]\n");

		write_message("info->si_uid : [");
		ft_putnbr_fd(info->si_uid, 1);
		write_message("]\n");

		write_message("info->si_status : [");
		ft_putnbr_fd(info->si_status, 1);
		write_message("]\n");
		write_message("-----------------------------\n");
	}
	count += 25;
}
*/
