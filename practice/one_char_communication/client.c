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

static void	write_message(char *message)
{
	if (message == NULL)
		write(1, "\nNot message!!\n", 14);
	else
		write(1, message, strlen(message));
}

static void	write_send_signal(int index, int signal)
{
	write_message("[");
	ft_putnbr_fd(index, 1);
	write_message("] : ");
	write_message("[");
	ft_putnbr_fd(signal, 1);
	write_message("]\n");
}

static void	write_send_char(char c)
{
	write_message("\nsend char [");
	write(1, &c, 1);
	write_message("]\n");
}

static void	send_char(pid_t pid, char c)
{
	int				i;
	int				bit;
	unsigned char	uc;

	i = 0;
	bit = 0;
	uc = (unsigned char)c;
	write_message("send signal\n");
	while (i < 8)
	{
		usleep(50);
		bit = (uc >> i) & 0x01;
		if (kill(pid, SIGUSR1 + bit) != -1)
			write_send_signal(i, bit);
		i += 1;
	}
	usleep(50);
	if (kill(pid, SIGUSR1 + 2) != -1)
		write_send_char(c);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		send_char(atoi(argv[1]), argv[2][0]);
	return (0);
}
