#include "mot.h"

int	quit(t_game *game)
{
	if (game->music)
		endAudio();
	free(game);
	exit(0);
	return (0);
}
