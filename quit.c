#include "mot.h"

void	quit(t_game *game)
{
	if (game->music)
		endAudio();
	free(game);
	exit(0);
}
