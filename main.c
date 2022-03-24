#include "mot.h"

void	main_menu(t_game *game)
{
	if (game->music == 0)
	{
		playMusic("ost.wav", 90);
		game->music = 1;
	}
	game->start = 2;
	mlx_clear_window(game->init, game->win);
	if (game->menu == 0)
	{
		mlx_string_put(game->init, game->win, 250, 250, 0xFFFFFF, "MATTER OF TIME");
		mlx_string_put(game->init, game->win, 300, 340, 0xFFFFFF, "> Play");
		mlx_string_put(game->init, game->win, 300, 380, 0xFFFFFF, "Exit");
	}
	else if (game->menu == 1)
	{
		mlx_string_put(game->init, game->win, 250, 250, 0xFFFFFF, "MATTER OF TIME");
		mlx_string_put(game->init, game->win, 300, 340, 0xFFFFFF, "Play");
		mlx_string_put(game->init, game->win, 300, 380, 0xFFFFFF, "> Exit");
	}
}	


int	get_key(int key, t_game *game)
{
	if (game->start == 1 && game->animation == 0 && (key == UP || key == DOWN || key == LEFT || key == RIGHT))
		move(game, key);
	else if (game->start == 2 && (key == UP || key == DOWN))
	{
		game->menu = 1 - game->menu;
		main_menu(game);
	}
	else if (game->start == 2 && key == ENTER)
	{
		if (game->menu == 0)
		{
			game->level = 0;
			game->start = 0;
		}
		else if (game->menu == 1)
			quit(game);
	}
	else if (game->start == 3 && key == ENTER)
	{
		game->start = 2;
		main_menu(game);
	}
	if (key == KEY_ESC)
		quit(game);
	return (0);
}

int	main(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	game->init = mlx_init();
	if(!game->init)
		return (error_int("Game doesn't init\n"));
	if (get_xpm(game))
		return (error_int("images not correctly loaded"));
	game->win = mlx_new_window(game->init, WINDOW_X,
		WINDOW_Y, GAME_NAME);
	if (!game->win)
	{
		quit(game);
		return (error_int("Window doesn't init\n"));
	}
	SDL_Init(SDL_INIT_AUDIO);
	initAudio();
//	game->animation = 0;
//	game->intro = 0;
	intro(game);
	mlx_key_hook(game->win, get_key, game);
	mlx_loop_hook(game->init, update, game);
	mlx_loop(game->init);
	return (0);
}
