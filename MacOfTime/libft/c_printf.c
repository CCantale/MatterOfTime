#include "libft.h"

int	call_char_department(const char *str, va_list arg)
{
	int		fake;
	int		i;
	char	*reprint;
	char	c;

	c = va_arg(arg, int);
	fake = 1;
	i = 0;
	reprint = i_dont_like_it_change_it(str - 1, 'c', 'a');
	i += ft_printf(reprint, fake);
	i += write(1, &c, 1);
	if (str[0] == '-')
	{
		fake = ft_atoi(str + 1);
		while (--fake > 0)
			i += write(1, " ", 1);
	}
	free(reprint);
	return (i);
}
