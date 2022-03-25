#include "mot.h"

void	ft_open_door(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_y)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'D')
			{	
				playSound("door.wav", SDL_MIX_MAXVOLUME);
				game->map[i][j] = 'E';
				put_whatever(game, i, j);
				break ;
			}
			++j;
		}
		++i;
	}
}
