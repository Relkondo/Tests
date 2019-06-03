#include "libft.h"

long int	ft_atol(const char *s)
{
	unsigned int	i;
	long int		a;
	int				neg;

	i = 0;
	a = 0;
	neg = 0;
	while (ft_isspace(s[i]))
	{
		i++;
	}
	if (s[i] == '-' || s[i] == '+')
		i++;
	neg = i;
	while (ft_isdigit(s[i]))
	{
		a = (a * 10) + (s[i] - '0');
		i++;
	}
	if (s[neg - 1] == '-')
		a *= -1;
	return (a);
}
