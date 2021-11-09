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
    if (s == SIGUSR1)
    {
        str++;
        if(*str == '\0')
        {
            exit(EXIT_SUCCESS);
        }
        if(*str != '1' && *str != '0')
            str++;
        if (*str == '1')
        {
            kill(siginfo->si_pid, SIGUSR1);
        }
        else if (*str == '0')
        {
            kill(siginfo->si_pid, SIGUSR2); 
        }
    }
}

int main(int argc, char **argv)
{
    int pid;
    char *bin;
    int i;
    struct sigaction sa;

    i = 1;
    sa.sa_sigaction = handle_sigusr1;
	sa.sa_flags = SA_SIGINFO;
    pid = ft_atoi(argv[1]);
    str = ft_itoa(argv[2][0], 2);
    while (argv[2][i] != '\0')
    {
        bin = ft_itoa(argv[2][i], 2);
        str = ft_strcat(str, bin);
        i++;
    }
    str = ft_strcat(str, "1111111");
    if (*str == '1')
        kill(pid, SIGUSR1);
    else
        kill(pid, SIGUSR2);
    sigaction(SIGUSR1, &sa, NULL);
    while(1)
        pause();
    return 0;
}