#ifndef MINITALK_H_
# define MINITALK_H_

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

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
char	*ft_itoa(int n, int base);
char	*ft_strcat(char *dest, char *src);
char	**ft_split(char *s, char c);

#endif 