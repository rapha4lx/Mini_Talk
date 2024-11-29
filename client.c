#include <unistd.h>
#include <signal.h>

#include "aux_func.h"

void    send_bits(const char c, int pid)
{
    int		bits_count;
	unsigned char bits;

	bits = c;
    bits_count = 8;
	while (bits_count--)
    {
		if (((bits >> bits_count) & 1))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(5);
    }
}

void    send_message(const char *str, int pid)
{
    int i;

    i = 0;
    while (str[i])
	{
        send_bits(str[i], pid);
		i++;
	}
}

int main(int argc, char **argv)
{
    int server_pid;
	int argc_count;

	if (argc <= 1)
	{
		ft_putstr("You dont input message\n");
		return (0);
	}

    server_pid = ft_atoi(argv[1]);
	argc_count = 2;
	ft_putnbr(server_pid);
	ft_putchar('\n');
	while (argv[argc_count])
	{
		send_message(argv[argc_count], server_pid);
		argc_count++;
	}
	
}
