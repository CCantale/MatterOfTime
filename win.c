#include "mot.h"

void	win(t_game *game)
{
	mlx_clear_window(game->init, game->win);
	mlx_string_put(game->init, game->win, 300, 390, 0xFFFFFF, "YOU WON!");
	mlx_string_put(game->init, game->win, 300, 600, 0xFFFFFF, "Bye :)");
	game->end = 1;
}
