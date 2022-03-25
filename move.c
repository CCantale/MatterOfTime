#include "mot.h"

void	move_u(t_game *game)
{
	int		x;
	int		y;
	char	*next;

	x = game->player_x;
	y = game->player_y;
	next = &game->map[y - 1][x];
	if (*next != '1' && *next != '2' && *next  != 'E' && *next != 'B' && *next  != 'D')
	{
		if (game->backwards_x && game->backwards_y)
			game->map[game->backwards_y][game->backwards_x] = ' ';
		game->sand++;
		if (*next == 'C')
			game->animation = 1;
		else if (*next == 'K')
			ft_open_door(game);
		if (game->sand < 5)
			mlx_put_image_to_window(game->init, game->win, game->title[game->sand], 71, 10);
		if (*next == 'J' && game->map[y][x + 3] != '1')
		{
			playSound("jump.wav", SDL_MIX_MAXVOLUME);
			game->map[y][x] = ' ';
			*next = ' ';
			game->map[y - 3][x] = 'P';
			put_whatever(game, y - 1, x);
			put_whatever(game, y - 3, x);
		}
		else if (*next == 'J' && game->map[y - 2][x] != '1')
		{
			playSound("jump.wav", SDL_MIX_MAXVOLUME);
			game->map[y][x] = ' ';
			*next = ' ';
			game->map[y - 2][x] = 'P';
			put_whatever(game, y - 1, x);
			put_whatever(game, y - 2, x);
		}
		else
		{
			game->map[y][x] = 'B';
			game->backwards_x = x;
			game->backwards_y = y;
			*next = 'P';
			put_whatever(game, y - 1, x);
		}
		put_whatever(game, y, x);
	}
	else if (*next == 'E')
	{
		game->level++;
		game->start = 0;
		playSound("vortex.wav", SDL_MIX_MAXVOLUME - 30);
	}
	else if (*next == 'B')
		game->warning = 1;
}

void	move_d(t_game *game)
{
	int		x;
	int		y;
	char	*next;

	x = game->player_x;
	y = game->player_y;
	next = &game->map[y + 1][x];
	if (*next != '1' && *next != '2' && *next != 'E' && *next != 'B' && *next != 'D')
	{
		if (game->backwards_x && game->backwards_y)
			game->map[game->backwards_y][game->backwards_x] = ' ';
		game->sand++;
		if (*next == 'C')
			game->animation = 1;
		else if (*next == 'K')
			ft_open_door(game);
		if (game->sand < 5)
			mlx_put_image_to_window(game->init, game->win, game->title[game->sand], 71, 10);
		if (*next == 'J' && game->map[y + 3][x] != '1')
		{
			playSound("jump.wav", SDL_MIX_MAXVOLUME);
			game->map[y][x] = ' ';
			*next = ' ';
			game->map[y + 3][x] = 'P';
			put_whatever(game, y + 1, x);
			put_whatever(game, y + 3, x);
		}
		else if (*next == 'J' && game->map[y + 2][x] != '1')
		{
			playSound("jump.wav", SDL_MIX_MAXVOLUME);
			game->map[y][x] = ' ';
			*next = ' ';
			game->map[y + 2][x] = 'P';
			put_whatever(game, y + 1, x);
			put_whatever(game, y + 2, x);
		}
		else
		{
			game->map[y][x] = 'B';
			game->backwards_x = x;
			game->backwards_y = y;
			*next = 'P';
			put_whatever(game, y + 1, x);
		}
		put_whatever(game, y, x);
	}
	else if (*next == 'E')
	{
		game->level++;
		game->start = 0;
		playSound("vortex.wav", SDL_MIX_MAXVOLUME - 30);
	}
	else if (*next == 'B')
		game->warning = 1;
}

void	move_l(t_game *game)
{
	int		x;
	int		y;
	char	*next;

	x = game->player_x;
	y = game->player_y;
	next = &game->map[y][x - 1];
	if (*next != '1' && *next != '2' && *next != 'E' && *next != 'B' && *next != 'D')
	{
		if (game->backwards_x && game->backwards_y)
			game->map[game->backwards_y][game->backwards_x] = ' ';
		game->sand++;
		if (*next == 'C')
			game->animation = 1;
		else if (*next == 'K')
			ft_open_door(game);
		if (game->sand < 5)
			mlx_put_image_to_window(game->init, game->win, game->title[game->sand], 71, 10);
		if (*next == 'J' && game->map[y][x - 3] != '1')
		{
			playSound("jump.wav", SDL_MIX_MAXVOLUME);
			game->map[y][x] = ' ';
			*next = ' ';
			game->map[y][x - 3] = 'P';
			put_whatever(game, y, x - 1);
			put_whatever(game, y, x - 3);
		}
		else if (*next == 'J' && game->map[y][x - 2] != '1')
		{
			playSound("jump.wav", SDL_MIX_MAXVOLUME);
			game->map[y][x] = ' ';
			*next = ' ';
			game->map[y][x - 2] = 'P';
			put_whatever(game, y, x - 1);
			put_whatever(game, y, x - 2);
		}
		else
		{
			game->map[y][x] = 'B';
			game->backwards_x = x;
			game->backwards_y = y;
			*next = 'P';
			put_whatever(game, y, x - 1);
		}
		put_whatever(game, y, x);
	}
	else if (*next == 'E')
	{
		game->level++;
		game->start = 0;
		playSound("vortex.wav", SDL_MIX_MAXVOLUME - 30);
	}
	else if (*next == 'B')
		game->warning = 1;
}

void	move_r(t_game *game)
{
	int		x;
	int		y;
	char	*next;

	x = game->player_x;
	y = game->player_y;
	next = &game->map[y][x + 1];
	if (*next != '1' && *next != '2' && *next != 'E' && *next != 'B' && *next != 'D')
	{
		if (game->backwards_x && game->backwards_y)
			game->map[game->backwards_y][game->backwards_x] = ' ';
		game->sand++;
		if (*next == 'C')
			game->animation = 1;
		else if (*next == 'K')
			ft_open_door(game);
		if (game->sand < 5)
			mlx_put_image_to_window(game->init, game->win, game->title[game->sand], 71, 10);
		if (*next == 'J' && game->map[y][x + 3] != '1')
		{
			playSound("jump.wav", SDL_MIX_MAXVOLUME);
			game->map[y][x] = ' ';
			*next = ' ';
			game->map[y][x + 3] = 'P';
			put_whatever(game, y, x + 1);
			put_whatever(game, y, x + 3);
		}
		else if (*next == 'J' && game->map[y][x + 2] != '1')
		{
			playSound("jump.wav", SDL_MIX_MAXVOLUME);
			game->map[y][x] = ' ';
			*next = ' ';
			game->map[y][x + 2] = 'P';
			put_whatever(game, y, x + 1);
			put_whatever(game, y, x + 2);
		}
		else
		{
			game->map[y][x] = 'B';
			game->backwards_x = x;
			game->backwards_y = y;
			*next = 'P';
			put_whatever(game, y, x + 1);
		}
		put_whatever(game, y, x);
	}
	else if (*next == 'E')
	{
		game->level++;
		game->start = 0;
		playSound("vortex.wav", SDL_MIX_MAXVOLUME - 30);
			
	}
	else if (*next == 'B')
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
