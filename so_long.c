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

int	ft_map_init(t_game *game, char **map)
{
	if (!map)
	{
		ft_printf("Error\nMap check failed\n");
		return (0);
	}
	game->map = map;
	if (!game->init)
		return (0);
	return(1);
}

int	ft_get_key(int key, t_game *game)
{
	if (!game)
		return (0);
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		move(game, key);
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
	mlx_key_hook(game.win, ft_get_key, &game);
	mlx_loop_hook(game.init, update, &game);
	mlx_loop(game.init);
	return (0);
}
