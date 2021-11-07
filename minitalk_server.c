#include "minitalk.h"

void    handle_sigusr1(int s)
{
    if (s == SIGUSR1)
    {
        printf("message recu\n");
        kill(s, SIGUSR2);
    }
    else 
        printf("bad signal \n");
}

int main()
{
    struct sigaction sa;

    sa.sa_handler = &handle_sigusr1; 
    ft_putstr("pid = ");
    ft_putnbr(getpid());
    ft_putstr(" \n");
    sigaction(SIGUSR1, &sa, NULL);
    pause();
    return 0;
}