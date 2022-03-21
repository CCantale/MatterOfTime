#include "so_long.h"

void	intro(t_game *game)
{
	game->start = 3;
	if (game->intro == 0)
	{
		mlx_string_put(game->init, game->win, 80, 130, 0xFFFFFF, "Welcome to playtesting mode.");
		mlx_string_put(game->init, game->win, 80, 160, 0xFFFFFF, "We wish you a fun and satisfying game experience.");
		mlx_string_put(game->init, game->win, 80, 190, 0xFFFFFF, "Press ENTER to start and remember:");
		mlx_string_put(game->init, game->win, 80, 250, 0xFFFFFF, "Time never walks backwards,");
		mlx_string_put(game->init, game->win, 80, 280, 0xFFFFFF, "it only comes back to the very beginning...");
	}
	else
	{
		game->intro = 0;
		game->start = 2;
	}
}
