#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned int	num;
	int				i;
	int				sign;

	num = 0;
	sign = 1;
	i = 0;
	while (*(str + i) == ' ' || *(str + i) == '\t' || *(str + i) == '\f'
		|| *(str + i) == '\r' || *(str + i) == '\n' || *(str + i) == '\v')
		++i;
	if (*(str + i) == '+' || *(str + i) == '-')
		if (*(str + i++) == '-')
			sign = -1;
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		num = num * 10 + (*(str + i) - '0');
		++i;
	}
	return ((int)(sign * num));
}
