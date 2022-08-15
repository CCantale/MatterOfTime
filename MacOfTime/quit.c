#include "mot.h"

int	quit(t_game *game)
{
//	if (game->music)
//		endAudio();
	free_lvl(game->map, game->map_y);
	free(game);
	exit(0);
	return (0);
}
