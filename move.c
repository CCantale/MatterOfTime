#include "so_long.h"

void	move_u(t_game *game)
{
	int		x;
	int		y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y - 1][x] == 'C')
		game->sand = 5 - game->sand;
	if (game->map[y - 1][x] != '1' && game->map[y - 1][x] != 'E')
	{
		game->map[y][x] = ' ';
		game->map[y - 1][x] = 'P';
		put_whatever(game, y, x);
		put_whatever(game, y - 1, x);
	}
	else if (game->map[y - 1][x] == 'E')
	{
		game->level++;
		game->start = 0;
	}
}

void	move_d(t_game *game)
{
	int		x;
	int		y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y + 1][x] == 'C')
		game->sand = 5 - game->sand;
	if (game->map[y + 1][x] != '1' && game->map[y + 1][x] != 'E')
	{
		game->map[y][x] = ' ';
		game->map[y + 1][x] = 'P';
		put_whatever(game, y, x);
		put_whatever(game, y + 1, x);
	}
	else if (game->map[y + 1][x] == 'E')
	{
		game->level++;
		game->start = 0;
	}
}

void	move_l(t_game *game)
{
	int		x;
	int		y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y][x - 1] == 'C')
		game->sand = 5 - game->sand;
	if (game->map[y][x - 1] != '1' && game->map[y][x - 1] != 'E')
	{
		game->map[y][x] = ' ';
		game->map[y][x - 1] = 'P';
		put_whatever(game, y, x);
		put_whatever(game, y, x - 1);
	}
	else if (game->map[y][x - 1] == 'E')
	{
		game->level++;
		game->start = 0;
	}
}

void	move_r(t_game *game)
{
	int		x;
	int		y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y][x + 1] == 'C')
		game->sand = 5 - game->sand;
	if (game->map[y][x + 1] != '1' && game->map[y][x + 1] != 'E')
	{
		game->map[y][x] = ' ';
		game->map[y][x + 1] = 'P';
		put_whatever(game, y, x);
		put_whatever(game, y, x + 1);
	}
	else if (game->map[y][x + 1] == 'E')
	{
		game->level++;
		game->start = 0;
	}
}

void	move(t_game *game, int key)
{
	game->sand++;
	if (key == UP)
		move_u(game);
	else if (key == DOWN)
		move_d(game);
	else if (key == LEFT)
		move_l(game);
	else if (key == RIGHT)
		move_r(game);
		
}
