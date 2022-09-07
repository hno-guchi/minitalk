#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

static void	send_char(pid_t pid, char c)
{
	int				i;
	int				bit;
	unsigned char	uc;

	i = 0;
	bit = 0;
	uc = (unsigned char)c;
	while (i < 8)
	{
		usleep(50);
		bit = (uc >> i) & 0x01;
		if (kill(pid, SIGUSR1 + bit) == -1)
			exit(1);
		i += 1;
	}
}

static void	send_str(pid_t pid, char *str)
{
	int				i;

	i = 0;
	while (str[i] != '\0')
	{
		send_char(pid, str[i]);
		i += 1;
	}
	send_char(pid, '\n');
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		send_str(atoi(argv[1]), argv[2]);
	return (0);
}
