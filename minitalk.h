#ifndef MINITALK_H_
# define MINITALK_H_

#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


typedef   struct  s_write{
    char    c;
}       t_write;
/*
** Prototypes for client binary
*/

void			ft_putnbr(int n);
void			ft_putchar(char c);
void			ft_putstr(char *s);
int	ft_atoi(char *str);

#endif 