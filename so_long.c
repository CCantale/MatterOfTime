/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:42:38 by ccantale          #+#    #+#             */
/*   Updated: 2022/03/18 17:50:51 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	main_menu(t_game *game)
{
	game->start = 2;
	mlx_clear_window(game->init, game->win);
	if (game->menu == 0)
	{
		mlx_string_put(game->init, game->win, 300, 300, 0xFFFFFF, "> Play");
		mlx_string_put(game->init, game->win, 300, 340, 0xFFFFFF, "Exit");
	}
	else if (game->menu == 1)
	{
		mlx_string_put(game->init, game->win, 300, 300, 0xFFFFFF, "Play");
		mlx_string_put(game->init, game->win, 300, 340, 0xFFFFFF, "> Exit");
	}
}	


int	get_key(int key, t_game *game)
{
	if (game->start != 2 && (key == UP || key == DOWN || key == LEFT || key == RIGHT))
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
	if (key == KEY_ESC)
		quit(game);
	return (0);
}

int	main(void)
{
	t_game	game;

	game.init = mlx_init();
	if(!game.init)
		return (error_int("Game doesn't init\n"));
	if (get_xpm(&game))
		return (error_int("images not correctly loaded"));
	game.win = mlx_new_window(game.init, WINDOW_X,
		WINDOW_Y, GAME_NAME);
	if (!game.win)
	{
		quit(&game);
		return (error_int("Window doesn't init\n"));
	}
	main_menu(&game);
	mlx_key_hook(game.win, get_key, &game);
	mlx_loop_hook(game.init, update, &game);
	mlx_loop(game.init);
	return (0);
}
