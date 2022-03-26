#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*map;

	map = (void *)malloc(count * size);
	if (!map)
		return (NULL);
	i = 0;
	while (i < size * count)
	{
		*((char *)map + i) = 0;
		++i;
	}
	return (map);
}
