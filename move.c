#include "mot.h"

void	move_u(t_game *game)
{
	int		x;
	int		y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y - 1][x] != '1'
		&& game->map[y - 1][x] != 'E' && game->map[y - 1][x] != 'B')
	{
		game->sand++;
		if (game->map[y - 1][x] == 'C')
			game->animation = 1;
		game->map[y][x] = 'B';
		game->map[y - 1][x] = 'P';
		if (game->backwards_x && game->backwards_y)
			game->map[game->backwards_y][game->backwards_x] = ' ';
		put_whatever(game, y, x);
		put_whatever(game, y - 1, x);
		put_whatever(game, game->backwards_y, game->backwards_x);
		game->backwards_x = x;
		game->backwards_y = y;
		if (game->animation == 1)
			play_animation(game);
	}
	else if (game->map[y - 1][x] == 'E')
	{
		game->level++;
		game->start = 0;
	}
	else if (game->map[y - 1][x] == 'B')
		game->warning = 1;
}

void	move_d(t_game *game)
{
	int		x;
	int		y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y + 1][x] != '1'
		&& game->map[y + 1][x] != 'E' && game->map[y + 1][x] != 'B')
	{
		game->sand++;
		if (game->map[y + 1][x] == 'C')
			game->animation = 1;
		game->map[y][x] = 'B';
		game->map[y + 1][x] = 'P';
		if (game->backwards_x && game->backwards_y)
			game->map[game->backwards_y][game->backwards_x] = ' ';
		put_whatever(game, y, x);
		put_whatever(game, y + 1, x);
		put_whatever(game, game->backwards_y, game->backwards_x);
		game->backwards_x = x;
		game->backwards_y = y;
		if (game->animation == 1)
			play_animation(game);
	}
	else if (game->map[y + 1][x] == 'E')
	{
		game->level++;
		game->start = 0;
	}
	else if (game->map[y + 1][x] == 'B')
		game->warning = 1;
}

void	move_l(t_game *game)
{
	int		x;
	int		y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y][x - 1] != '1'
		&& game->map[y][x - 1] != 'E' && game->map[y][x - 1] != 'B')
	{
		game->sand++;
		if (game->map[y][x - 1] == 'C')
			game->animation = 1;
		game->map[y][x] = 'B';
		game->map[y][x - 1] = 'P';
		if (game->backwards_x && game->backwards_y)
			game->map[game->backwards_y][game->backwards_x] = ' ';
		put_whatever(game, y, x);
		put_whatever(game, y, x - 1);
		put_whatever(game, game->backwards_y, game->backwards_x);
		game->backwards_x = x;
		game->backwards_y = y;
		if (game->animation == 1)
			play_animation(game);
	}
	else if (game->map[y][x - 1] == 'E')
	{
		game->level++;
		game->start = 0;
	}
	else if (game->map[y][x - 1] == 'B')
		game->warning = 1;
}

void	move_r(t_game *game)
{
	int		x;
	int		y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y][x + 1] != '1'
		&& game->map[y][x + 1] != 'E' && game->map[y][x + 1] != 'B')
	{
		game->sand++;
		if (game->map[y][x + 1] == 'C')
			game->animation = 1;
		game->map[y][x] = 'B';
		game->map[y][x + 1] = 'P';
		if (game->backwards_x && game->backwards_y)
			game->map[game->backwards_y][game->backwards_x] = ' ';
		put_whatever(game, y, x);
		put_whatever(game, y, x + 1);
		put_whatever(game, game->backwards_y, game->backwards_x);
		game->backwards_x = x;
		game->backwards_y = y;
		if (game->animation == 1)
			play_animation(game);
	}
	else if (game->map[y][x + 1] == 'E')
	{
		game->level++;
		game->start = 0;
	}
	else if (game->map[y][x + 1] == 'B')
		game->warning = 1;
}

void	move(t_game *game, int key)
{
	if (key == UP)
		move_u(game);
	else if (key == DOWN)
		move_d(game);
	else if (key == LEFT)
		move_l(game);
	else if (key == RIGHT)
		move_r(game);	
}
