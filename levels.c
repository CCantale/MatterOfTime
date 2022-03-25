#include "mot.h"

static void	level0(t_game *game)
{
	char map[33];

	ft_strlcpy(map,	"1111111111\n"
			"1P   C  E1\n"
			"1111111111", 33);
	game->map = ft_split(map, '\n');
	game->map_x = 10;
	game->map_y = 3;
	game->y_start = 170;
}

static void	level1(t_game *game)
{
	char map[45];

	ft_strlcpy(map,	"11111111\n"
			"1  C   1\n"
			"1 1111E1\n"
			"2P C   1\n"
			"11111111", 45);
	game->map = ft_split(map, '\n');
	game->map_x = 8;
	game->map_y = 5;
}

static void	level2(t_game *game)
{
	char map[49];

	ft_strlcpy(map,	"111111\n"
			"1    1\n"
			"1C11C1\n"
			"1 C  1\n"
			"1 1111\n"
			"2PC E1\n"
			"111111", 49);
	game->map = ft_split(map, '\n');
	game->map_x = 6;
	game->map_y = 7;
}

static void	level3(t_game *game)
{
	char map[73];

	ft_strlcpy(map,	"1111111\n"
			"1     E\n"
			"1C1C 11\n"
			"1  C  1\n"
			"1C1C111\n"
			"2P  C 1\n"
			"1111111", 66);
	game->map = ft_split(map, '\n');
	game->map_x = 7;
	game->map_y = 7;
}

static void	level4(t_game *game)
{
	char map[90];

	ft_strlcpy(map,	"111111111\n"
			"1D1K C  1\n"
			"1 1  C  1\n"
			"1 1J    1\n"
			"1111 11C1\n"
			"1 E     1\n"
			"111 1 1 1\n"
			"2P   C  1\n"
			"111111111", 90);
	game->map = ft_split(map, '\n');
	game->map_x = 9;
	game->map_y = 9;
}

static void	level5(t_game *game)
{
	char map[49];

	ft_strlcpy(map,	"111111\n"
			"1CK  1\n"
			"1  111\n"
			"1C DP1\n"
			"1 11 1\n"
			"1 1J 1\n"
			"111111", 49);
	game->map = ft_split(map, '\n');
	game->map_x = 6;
	game->map_y = 7;
}

static void	level6(t_game *game)
{
	char map[90];

	ft_strlcpy(map,	"111111111\n"
			"1D1K C  1\n"
			"1 1  C  1\n"
			"1 1J    1\n"
			"1111 11C1\n"
			"1 2P    1\n"
			"111 1 1 1\n"
			"2    C  1\n"
			"111111111", 90);
	game->map = ft_split(map, '\n');
	game->map_x = 9;
	game->map_y = 9;
}

void	get_level(t_game *game)
{
	if (game->level == 0)
		level0(game);
	else if (game->level == 1)
		level1(game);
	else if (game->level == 2)
		level2(game);
	else if (game->level == 3)
		level3(game);
	else if (game->level == 4)
		level4(game);
	else if (game->level == 5)
		level5(game);
	else if (game->level == 6)
		level6(game);
	else
	{
		game->start = 4;
	}
	game->x_start = (WINDOW_X - (game->map_x * 64)) / 2;
	game->sand = 0;	
}
