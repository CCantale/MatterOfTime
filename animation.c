#include "mot.h"

void	play_animation(t_game *game)
{
	int	i;
	int	wait;

	wait = 0;
	i = 0;
	while (i < 6 || wait < 10000)
	{
		if (wait > 10000)
		{
			mlx_put_image_to_window(game->init, game->win, game->flip[i],
				game->player_x * 64 + game->x_start, game->player_y * 64 + 8 + game->y_start);
			wait = 0;
			++i;
		}
		++wait;
	}
	game->sand = 5 - game->sand;
	put_whatever(game, game->player_y, game->player_x);
	game->animation = 0;
}

