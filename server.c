#include "aux_func.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void	sig_func(int sig, siginfo_t *info, void *context)
{
	static int				bits_count = 0;
	static unsigned char	bits = 0;
	static int				last_pid = 0;

	(void)context;
	if (info->si_pid != last_pid)
	{
		if (last_pid != 0)
			ft_putchar('\n');
		last_pid = info->si_pid;
		ft_putstr("Message from: ");
		ft_putnbr(last_pid);
		ft_putchar('\n');
	}
	if (sig == SIGUSR1)
		bits = (bits << 1) | 1;
	else if (sig == SIGUSR2)
		bits = (bits << 1);
	bits_count++;
	if (bits_count >= 8)
	{
		ft_putchar(bits);
		bits_count = 0;
		bits <<= 8;
	}
}

void	print_pid(void)
{
	ft_putstr("[");
	ft_putnbr(getpid());
	ft_putstr("]");
	ft_putchar('\n');
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = sig_func;
	sa.sa_flags = SA_SIGINFO;

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	print_pid();
	while (1)
		;
	return (0);
}
