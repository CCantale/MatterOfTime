#include "mot.h"

void	main_menu(t_game *game)
{
/*	if (game->music == 0)
	{
		playMusic("music/ost.wav", 90);
		game->music = 1;
	}		*/
	mlx_clear_window(game->init, game->win);
	if (game->start != 3)
	{
		game->start = 2;
		mlx_put_image_to_window(game->init, game->win, game->title[0], 71, 10); 
		if (game->menu == 0)
		{
			mlx_put_image_to_window(game->init, game->win, game->menu_img[0], 250, 372); 
			mlx_string_put(game->init, game->win, 270, 730, 0xFFFFFF, "If you get stuck, press ESC to reset");
		}
		else if (game->menu == 1)
		{
			mlx_put_image_to_window(game->init, game->win, game->menu_img[1], 250, 380); 
			mlx_string_put(game->init, game->win, 270, 730, 0xFFFFFF, "If you get stuck, press ESC to reset");
		}
	}
	else
	{
		mlx_put_image_to_window(game->init, game->win, game->ending, 71, 10);
		mlx_put_image_to_window(game->init, game->win, game->the_end, 280, 380); 
		mlx_put_image_to_window(game->init, game->win, game->credits, 40, 615); 
		mlx_string_put(game->init, game->win, 450, 730, 0xFFFFFF, "Press ESC to quit");
	}
}	


int	get_key(int key, t_game *game)
{
	if (game->start == 1)
	{
		if (game->animation == 0 && (key == UP || key == DOWN || key == LEFT || key == RIGHT))
			move(game, key);
		else if (key == KEY_ESC)
		{
			game->level = 0;
			main_menu(game);
		}
	}
	else if (game->start == 2)
	{
		if (key == UP || key == DOWN)
		{
			game->menu = 1 - game->menu;
			main_menu(game);
		}
		else if (key == ENTER)
		{
			if (game->menu == 0)
			{
				game->level = 0;
				game->start = 0;
			}
			else if (game->menu == 1)
				quit(game);
		}
		else if (key == KEY_ESC)
			quit(game);
	}
	else if (key == KEY_ESC)
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
//	SDL_Init(SDL_INIT_AUDIO);
//	initAudio();
	main_menu(game);
	mlx_key_hook(game->win, get_key, game);
	mlx_loop_hook(game->init, update, game);
	mlx_hook(game->win, 33, 1L << 17, quit, game);
	mlx_loop(game->init);
	return (0);
}
