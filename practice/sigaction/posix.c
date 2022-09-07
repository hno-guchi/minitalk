#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// int sigaction(int signum,
// 		const struct sigaction *act, struct sigaction *oldact);

/*
sigset_t
sigset_i is POSIX signal set;
 */
/*
struct siginfo_t {
	int			si_signo;  // Signal number
	int			si_errno;  // An errno value
	int			si_code;   // Signal code
	pid_t		si_pid;    // Sending process ID
	uid_t		si_uid;    // Real user ID of sending process
	int			si_status; // Exit value or signal
	clock_t		si_utime;  // User time consumed
	clock_t		si_stime;  // System time consumed
	sigval_t	si_value;  // Signal value
	int			si_int;    // POSIX.1b signal
	void		*si_ptr;   // POSIX.1b signal
	void		*si_addr;  // Memory location which caused fault
	int			si_band;   // Band event
	int			si_fd;     // File descriptor
}
*/

/*
// linux
struct sigaction {
	void		(*sa_handler)(int);
	void		(*sa_sigaction)(int, siginfo_t *, void *);
	sigset_t	sa_mask;
	int			sa_flags;
	void		(*sa_restorer)(void);
}

// Mac
struct sigaction {
	union		__sigaction_u __sigaction_u; // signal handler
	sigset_t	sa_mask;					 // signal mask to apply
	int			sa_flags;					 // see signal options below
}
union __sigaction_u {
	void	(*__sa_handler)(int);
	void	(*__sa_sigaction)(int, siginfo_t *, void *);
};
# define sa_handler		__sigaction_u.__sa_handler
# define sa_sigaction	__sigaction_u.__sa_sigaction
*/

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

static void	write_message(char *message)
{
	if (message == NULL)
		write(1, "\nNot message!!\n", 14);
	else
		write(1, message, strlen(message));
}

static void	write_server_pid(int pid)
{
	write(1, "server pid [", 12);
	ft_putnbr_fd(pid, 1);
	write(1, "]\n",2);
}

bool	sa_initialize(struct sigaction *sa)
{
	if (sigemptyset(&sa->sa_mask) == -1)
		return (false);
	if (sigaction(SIGINT, sa, NULL) == -1)
		return (false);
	return (true);
}

void	signal_handler(int signal_num, siginfo_t *info, void *ucontext_ap)
{

	write(1, "\n", 1);
	write_server_pid(getpid());
	write_message("signal_handler info->si_signo : [");
	ft_putnbr_fd(info->si_signo, 1);
	write_message("]\n");

	write_message("signal_handler info->si_errno : [");
	ft_putnbr_fd(info->si_errno, 1);
	write_message("]\n");

	write_message("signal_handler info->si_code : [");
	ft_putnbr_fd(info->si_code, 1);
	write_message("]\n");

	write_message("signal_handler info->si_pid : [");
	ft_putnbr_fd(info->si_pid, 1);
	write_message("]\n");

	write_message("signal_handler info->si_uid : [");
	ft_putnbr_fd(info->si_uid, 1);
	write_message("]\n");

	write_message("signal_handler info->si_status : [");
	ft_putnbr_fd(info->si_status, 1);
	write_message("]\n");

	count += 25;
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
	while (count < 50);
	write_message("\nfinish process!!\n");
	return (0);
}
