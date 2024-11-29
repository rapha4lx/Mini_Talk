#include <unistd.h>

void	ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(const char *str)
{
	while (*str)
		ft_putchar(*str++);
}

int		ft_atoi(const char *nptr)
{
	int	sing;
	int	i;

	sing = 1;
	i = 0;
	while (*nptr == ' ' || *nptr == '\n' || *nptr == '\f'
		|| *nptr == '\t' || *nptr == '\v' || *nptr == '\r')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sing = -1;
		nptr++;
	}
	while (*nptr && (*nptr >= '0' && *nptr <= '9'))
	{
		i = (i * 10) + (*nptr - '0');
		nptr++;
	}
	return (i * sing);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}