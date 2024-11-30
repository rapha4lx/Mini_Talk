#include "aux_func.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	send_bits(const char c, int pid)
{
	int				bits_count;
	unsigned char	bits;

	bits = c;
	bits_count = 8;
	while (bits_count--)
	{
		if (((bits >> bits_count) & 1))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
	}
}

void	send_message(const char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_bits(str[i], pid);
		i++;
	}
}

void	error_message(const char *str)
{
	ft_putstr(str);
	exit(0);
}

int	main(int argc, char **argv)
{
	int	server_pid;

	if (argc <= 1)
		error_message("You dont insert your PID\n");
	else if (argc <= 2)
		error_message("You dont insert your message\n");
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
		error_message("PID 0 or less is not valid\n");
	send_message(argv[2], server_pid);
	return (0);
}
