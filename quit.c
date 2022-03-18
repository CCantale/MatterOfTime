#include "so_long.h"

int	scan_for_coll(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}

void	quit(t_game *game)
{
	int		i;
	char	**map;
	
	map = game->map;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		++i;
	}
	free(map);
	exit(0);
}
