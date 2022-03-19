#include "so_long.h"

static void	level0(t_game *game)
{
	char map[33];

	ft_strlcpy(map,	"1111111111\n"
			"1P   C  E1\n"
			"1111111111", 33);
	game->map = ft_split(map, '\n');
	game->map_x = 10;
	game->map_y = 3;
	game->x_start = (WINDOW_X - (game->map_x * 64)) / 2;
	game->y_start = (WINDOW_Y - (game->map_y * 64 + 8)) / 2;
	game->sand = 0;
}

static void	level1(t_game *game)
{
	char map[45];

	ft_strlcpy(map,	"11111111\n"
			"1  C   1\n"
			"1 1111E1\n"
			"1P C   1\n"
			"11111111", 45);
	game->map = ft_split(map, '\n');
	game->map_x = 8;
	game->map_y = 5;
	game->x_start = (WINDOW_X - (game->map_x * 64)) / 2;
	game->y_start = (WINDOW_Y - (game->map_y * 64 + 8)) / 2;
	game->sand = 0;
}

void	get_level(t_game *game)
{
	if (game->level == 0)
		level0(game);
	else if (game->level == 1)
		level1(game);
	else
		quit(game);
}
