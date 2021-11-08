#include "minitalk.h"

int	ft_count(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i = 1;
	if (n == 0)
	{
		i = 1;
		return (i);
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_strrev(char *str)
{
	int		i;
	int		y;
	char	*tmp;

	y = 0;
	i = 0;
	while (str[i] != '\0')
		i++;
	tmp = (char *)malloc(sizeof(char) * (i + 1));
	if (tmp == NULL)
		return (0);
	i--;
	while (i >= 0)
	{
		tmp[y] = str[i];
		i--;
		y++;
	}
	tmp[y] = '\0';
	return (tmp);
}

char	*ft_itoa(int n, int base)
{
	char	*alpha;
	char	*str;
	char	*test;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (8));
	if (str == NULL)
		return (0);
	alpha = "0123456789abcdef";
	while (n > 0)
	{
		str[i] = alpha[n % base];
		i++;
		n = n / base;
	}
    str[i] = '\0';
	test = ft_strrev(str);
	free(str);
	return (test);
}