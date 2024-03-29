#include "mot.h"

void	play_animation(t_game *game)
{
	if (game->time <= 700)
	{
		game->time++;
	}
	else if (game->animation > 0 && game->time > 700)
	{
		mlx_put_image_to_window(game->init, game->win, game->flip[game->animation - 1],
			game->player_x * 64 + game->x_start, game->player_y * 64 + 8 + game->y_start);
//		if (game->animation == 1)
//			playSound("music/flip.wav", SDL_MIX_MAXVOLUME);
		game->time = 0;
		game->animation++;
		if (game->animation > 6)
			game->animation = -1;
	}
	else if (game->animation == -1)
	{
		game->sand = 5 - game->sand;
		put_whatever(game, game->player_y, game->player_x);
		mlx_put_image_to_window(game->init, game->win, game->title[game->sand], 71, 10);
		game->animation = 0;
	}
}

