#include "minitalk.h"

char *str;

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (6);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static void    handle_sigusr1(int s, siginfo_t *siginfo, void *context)
{
    printf("pid = %d\n", siginfo->si_pid);
    printf("str = %c\n", *str);
    if (s == SIGUSR1)
    {
        if(*str++ == '\0')
        {
            exit(EXIT_SUCCESS);
        }
        if (*str++ == '1')
            kill(siginfo->si_pid, SIGUSR1);
        else if (*str++ == '0')
            kill(siginfo->si_pid, SIGUSR2); 

    }
}



int main(int argc, char **argv)
{
    int pid;
    char *bin;
    int i = 1;
    struct sigaction sa;

    sa.sa_sigaction = handle_sigusr1;
	sa.sa_flags = SA_SIGINFO;
    ft_putstr("pid = ");
    ft_putnbr(getpid());
    ft_putstr(" \n");
    pid = ft_atoi(argv[1]);
    str = ft_itoa(argv[2][0], 2);
    while (argv[2][i] != '\0')
    {
        bin = ft_itoa(argv[2][i], 2);
        str = ft_strcat(str, bin);
        i++;
    }
    printf("str = %s\n", str);
    printf("str = %c\n", *str);
    if (*str == '1')
    {
        kill(pid, SIGUSR1);
    }
    else
        kill(pid, SIGUSR2);
    sigaction(SIGUSR1, &sa, NULL);
    while(1)
        pause();
    return 0;
}