#include "minitalk.h"

static void    handle_sigusr1(int s, siginfo_t *siginfo, void *context)
{
    static char c[8];
    static int i = 0;
    printf("sig = %d\n", siginfo->si_pid);
    if (s == SIGUSR1)
    {
        c[i] = '1';
        printf("1\n");
        kill(siginfo->si_pid, SIGUSR1);
    }
    else 
    {
        c[i] = '0';
        printf("0\n");
        kill(siginfo->si_pid, SIGUSR1);
    }
    i++;
    if (i == 7)
    {
        i = 0;
        printf("c = %s\n", c);
    }
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