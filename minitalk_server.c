#include "minitalk.h"

void	ft_putchar_fd(char c)
{
	write(1, &c, 1);
}

void    convert_binary(char *c)
{
    char *letter;
    int i;
    int ret = 13;

    letter = ft_convert_base(c, "01", "0123456789");
    i = ft_atoi(letter);
    ft_putchar((char)i);
}

static void    handle_sigusr1(int s, siginfo_t *siginfo, void *context)
{
    static char c[8];
    static int i = 0;
    if (s == SIGUSR1)
    {
        c[i] = '1';
    }
    else 
    {
        c[i] = '0';
    }
    i++;
    if (i % 7 == 0)
    {
        i = 0;
        convert_binary(c);
    }
    kill(siginfo->si_pid, SIGUSR1);
}

int main()
{
    struct sigaction sa;

    sa.sa_sigaction = handle_sigusr1;
	sa.sa_flags = SA_SIGINFO;
    ft_putstr("pid = ");
    ft_putnbr(getpid());
    ft_putstr(" \n");
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while(1)
        pause();
    return 0;
}