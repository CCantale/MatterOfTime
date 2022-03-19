#include "so_long.h"

int	get_sprites(t_game *game)
{
	int	x;
	int	y;

	x = 64;
	y = 60;
	game->o_door = mlx_xpm_file_to_image(game->init,
		"sprites/o_door.xpm", &x, &y);
	if (!game->o_door)
		return (1);
	return (0);
}

int	get_player(t_game *game)
{
	int	x;
	int	y;

	x = 64;
	y = 56;
	game->player[0] = mlx_xpm_file_to_image(game->init,
		"sprites/sandy0.xpm", &x, &y);
	game->player[1] = mlx_xpm_file_to_image(game->init,
		"sprites/sandy1.xpm", &x, &y);
	game->player[2] = mlx_xpm_file_to_image(game->init,
		"sprites/sandy2.xpm", &x, &y);
	game->player[3] = mlx_xpm_file_to_image(game->init,
		"sprites/sandy3.xpm", &x, &y);
	game->player[4] = mlx_xpm_file_to_image(game->init,
		"sprites/sandy4.xpm", &x, &y);
	game->player[5] = mlx_xpm_file_to_image(game->init,
		"sprites/sandy5.xpm", &x, &y);
	if (!game->player)
		return (1);
	game->turner = mlx_xpm_file_to_image(game->init,
		"sprites/turner.xpm", &x, &y);
	if (!game->turner)
		return (1);
	return (0);
}

int	get_background(t_game *game)
{
	int	size;

	size = 64;
	game->background = mlx_xpm_file_to_image(game->init,
		"sprites/background.xpm", &size, &size);
	if (!game->background)
		return (1);
	return (0);
}

int	get_walls(t_game *game)
{
	int	x;
	int	y;

	x = 64;
	y = 72;
	game->out_block = mlx_xpm_file_to_image(game->init,
		"sprites/out_block.xpm", &x, &y);
	if (!game->out_block)
		return (1);
	game->t_block = mlx_xpm_file_to_image(game->init,
		"sprites/t_block.xpm", &x, &y);
	if (!game->t_block)
		return (1);
	game->s_block = mlx_xpm_file_to_image(game->init,
		"sprites/s_block.xpm", &x, &y);
	if (!game->s_block)
		return (1);
	return (0);
}

int	get_xpm(t_game *game)
{
	int	i;

	i = 0;
	i += get_walls(game);
	i += get_background(game);
	i += get_player(game);
	i += get_sprites(game);
	return (i);
}
