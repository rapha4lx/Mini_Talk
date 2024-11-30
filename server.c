#include <unistd.h>
#include <signal.h>

#include "aux_func.h"

void    sig_func(int sig)
{   
    //ft_putstr("sig trigged\n");
    static int bits_count = 0;
    static unsigned char bits = 0;

    if (sig == SIGUSR1)
        bits = (bits << 1) | 1;
    else if (sig == SIGUSR2)
        bits = (bits << 1);
    bits_count++;
    if (bits_count >= 8)
    {
        ft_putchar(bits);
        bits_count = 0;
    }
}

int main()
{
    int pid;

    pid = getpid();
    ft_putstr("[");
    ft_putnbr(pid);
    ft_putstr("]");
    ft_putchar('\n');

    signal(SIGUSR1, sig_func);
    signal(SIGUSR2, sig_func);
    while (1)
        ;
}
