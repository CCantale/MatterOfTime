#include "so_long.h"

void	put_background(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == ' ' || game->map[i][j] == 'B')
				mlx_put_image_to_window(game->init, game->win,
					game->background, j * 64 + game->x_start, i * 64 + game->y_start);
			++j;
		}
		++i;
	}
}

void	put_collect(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'C')
	{
		mlx_put_image_to_window(game->init, game->win,
			game->turner, j * 64 + game->x_start, i * 64 + game->y_start);
		if (game->map[i - 1][j] == '1' || game->map[i - 1][j] == 'E')
			put_whatever(game, i - 1, j);
		if (game->map[i + 1][j] == '1')
			put_whatever(game, i + 1, j);
	}
	else if (game->map[i][j] == 'K')
		mlx_put_image_to_window(game->init, game->win,
			game->key, j * 64 + game->x_start, i * 64 + game->y_start);
	else if (game->map[i][j] == 'J')
		mlx_put_image_to_window(game->init, game->win,
			game->background, j * 64 + game->x_start, i * 64 + game->y_start);
}

void	put_sprites(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'P')
	{
		mlx_put_image_to_window(game->init, game->win, game->player[game->sand],
			j * 64 + game->x_start, i * 64 + 8 + game->y_start);
		game->player_x = j;
		game->player_y = i;
		if (game->map[i + 1][j] == '1')
			put_whatever(game, i + 1, j);
	}
	if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->init, game->win,
			game->o_door, j * 64 + game->x_start, i * 64 + 8 + game->y_start);
	if (game->map[i][j] == 'C' || game->map[i][j] == 'K' || game->map[i][j] == 'J')
		put_collect(game, i, j);
	if ((game->map[i][j] == ' ' || game->map[i][j] == 'B') && game->start != 0)
	{
		mlx_put_image_to_window(game->init, game->win,
			game->background, j * 64 + game->x_start, i * 64 + game->y_start);
		if (game->map[i - 1][j] == '1' || game->map[i - 1][j] == 'E')
			put_whatever(game, i - 1, j);
		if (game->map[i + 1][j] == '1')
			put_whatever(game, i + 1, j);
	}
}

void	put_whatever(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1' && i)
	{
		if (game->map[i - 1][j] == 'P')
			mlx_put_image_to_window(game->init, game->win,
				game->s_block, j * 64 + game->x_start, i * 64 + game->y_start);
		else if (game->map[i - 1][j] == 'C')
			mlx_put_image_to_window(game->init, game->win,
				game->t_block, j * 64 + game->x_start, i * 64 + game->y_start);
		else
			mlx_put_image_to_window(game->init, game->win,
				game->out_block, j * 64 + game->x_start, i * 64 + game->y_start);
	}
	else if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->init, game->win,
			game->out_block, j * 64 + game->x_start, i * 64 + game->y_start);
	else if (game->map[i][j] == 'D')
		mlx_put_image_to_window(game->init, game->win,
			game->c_door, j * 64 + game->x_start, i * 64 + game->y_start);
	else
		put_sprites(game, i, j);
	if (i && game->start != 0 && game->map[i][j] == '1'
		&& (game->map[i - 1][j] == '1' || game->map[i - 1][j] == 'E'))
		put_whatever(game, i - 1, j);
}

void	put_start(t_game *game)
{
	int	i;
	int	j;

	put_background(game);
	i = game->map_y - 1;
	while (i >= 0)
	{
		j = 0;
		while (game->map[i][j])
		{
			put_whatever(game, i, j);
			++j;
		}
		--i;
	}
}

int	update(t_game *game)
{
	if (game->start == 0)
	{
		get_level(game);
		mlx_clear_window(game->init, game->win);
		put_start(game);
		game->start = 1;
		game->sand = 0;
		game->backwards_x = 0;
		game->backwards_y = 0;
		mlx_string_put(game->init, game->win, 30, 5, 0xFFFFFF, "More sand will fall down at every step.");
		mlx_string_put(game->init, game->win, 30, 35, 0xFFFFFF, "Walk on arrows to turn Time upside down.");
		mlx_string_put(game->init, game->win, 30, 65, 0xFFFFFF, "No turning animation yet. Sorry.");
	}
	if (game->warning == 1)
	{
		mlx_string_put(game->init, game->win, 80, 730, 0xFFFFFF, "Time never walks backwards!");
		game->warning++;
	}
	else if (game->warning > 1)
	{
		if (game->warning < 25000)
			game->warning++;
		else
		{
			game->warning = 0;
		mlx_string_put(game->init, game->win, 80, 730, 0x000000, "Time never walks backwards!");
		}
	}
	if (game->start != 2 && game->sand >=5)
	{
		game->warning = 0;
		main_menu(game);
	}
	return (1);
}
