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
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
char	*ft_strchr(char *str, int c);
int		ft_strlen(char *str);
int		ft_check_error(char *base);
int		ft_atoi_base(char *str, char *base);



#endif 