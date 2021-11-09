#include "minitalk.h"

char	*ft_strchr(char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_check_error(char *base)
{
	int i;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i] && ft_strchr(&base[i + 1], base[i]) == NULL)
		i++;
	if (base[i])
		return (0);
	if (ft_strchr(base, '+') || ft_strchr(base, '-')
			|| ft_strchr(base, '\t') || ft_strchr(base, '\n')
			|| ft_strchr(base, '\r') || ft_strchr(base, '\v')
			|| ft_strchr(base, '\f') || ft_strchr(base, ' '))
		return (0);
	return (1);
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int sign;
	int nbr;

	if (ft_check_error(base) == 0)
		return (0);
	i = 0;
	nbr = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (ft_strchr(base, str[i]))
	{
		nbr = nbr * ft_strlen(base);
		nbr = nbr + (ft_strchr(base, str[i]) - base);
		i++;
	}
	return (nbr * sign);
}