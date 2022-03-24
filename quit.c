#include "mot.h"

void	quit(t_game *game)
{
	if (game->base)
	{
		endAudio();
		freeAudio(game->base);
	}
	free(game);
	exit(0);
}
