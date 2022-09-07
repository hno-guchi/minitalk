#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

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
	pit_t		si_pid;    // Sending process ID
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

void	write_message(char *message)
{
	size_t	message_len;

	if (message == NULL)
		write(1, "\nNot message!!\n", 14);
	else
	{
		message_len = strlen(message);
		write(1, message, message_len);
	}
}

/*
// sample 1
void	signal_handler(int signal_num)
{
	if (signal_num == SIGINT)
		write_message("\nfinish process!!\n");

	exit(1);
}
*/

// sample 2
void	signal_handler(int signal_num)
{
	count += 100;
}

// ANSI C version
void	sa_initialize(struct sigaction *sa)
{
	if (-1 == sigemptyset(&sa->sa_mask))
		exit(1);
	sa->sa_handler = signal_handler;
	sa->sa_flags = 0;

	if (-1 == sigaction(SIGINT, sa, NULL))
		exit(1);
}

int	main()
{
	struct sigaction	sa;

	sa_initialize(&sa);
	while (count < 50)
	{
	}

	write_message("\nfinish process!!\n");
	return (0);
}
