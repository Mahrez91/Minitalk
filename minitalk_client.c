#include "minitalk.h"

void    handle_sigusr2(int s)
{
    if (s == SIGUSR2)
    {
        printf("message recu\n");
    }
    else 
        printf("bad signal \n");
}

int main(int argc, char **argv)
{
    struct sigaction sa;
    int pid;

    sa.sa_handler = &handle_sigusr2; 
    pid = ft_atoi(argv[1]);
    kill(pid, SIGUSR1);
    sigaction(SIGUSR2, &sa, NULL);
    pause();
    //sigaction(SIGUSR2, &sa, NULL);
    return 0;
}