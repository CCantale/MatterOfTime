#include "mot.h"

int	get_doors(t_game *game)
{
	int	x;
	int	y;

	x = 64;
	y = 60;

	game->o_door = mlx_xpm_file_to_image(game->init,
		"sprites/o_door.xpm", &x, &y);
	if (!game->o_door)
		return (1);
	game->c_door = mlx_xpm_file_to_image(game->init,
		"sprites/c_door.xpm", &x, &y);
	if (!game->c_door)
		return (1);
	game->c_door_base = mlx_xpm_file_to_image(game->init,
		"sprites/c_door_base.xpm", &x, &y);
	if (!game->c_door)
		return (1);
	return (0);
}

int	get_player(t_game *game)
{
	int	i;
	int	x;
	int	y;

	x = 64;
	y = 56;
	game->player[0] = mlx_xpm_file_to_image(game->init,
		"sprites/time0.xpm", &x, &y);
	game->player[1] = mlx_xpm_file_to_image(game->init,
		"sprites/time1.xpm", &x, &y);
	game->player[2] = mlx_xpm_file_to_image(game->init,
		"sprites/time2.xpm", &x, &y);
	game->player[3] = mlx_xpm_file_to_image(game->init,
		"sprites/time3r.xpm", &x, &y);
	game->player[4] = mlx_xpm_file_to_image(game->init,
		"sprites/time4r.xpm", &x, &y);
	game->player[5] = mlx_xpm_file_to_image(game->init,
		"sprites/time5.xpm", &x, &y);
	i = 0;
	while (i < 6)
	{
		if (!game->player[i])
			return (1);
		++i;
	}
	return (0);
}

int	get_background(t_game *game)
{
	int	x;
	int	y;

	x = 64;
	y = 72;
	game->background = mlx_xpm_file_to_image(game->init,
		"sprites/background.xpm", &x, &y);
	if (!game->background)
		return (1);
	return (0);
}

int	get_collect(t_game *game)
{
	int	x;
	int	y;

	x = 64;
	y = 72;
	game->turner = mlx_xpm_file_to_image(game->init,
		"sprites/turner.xpm", &x, &y);
	if (!game->turner)
		return (1);
	game->jumper = mlx_xpm_file_to_image(game->init,
		"sprites/jumper.xpm", &x, &y);
	if (!game->turner)
		return (1);
	game->key = mlx_xpm_file_to_image(game->init,
		"sprites/key.xpm", &x, &y);
	if (!game->key)
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

int	get_animation(t_game *game)
{
	int	x;
	int	y;

	x = 64;
	y = 72;
	game->flip[0] = mlx_xpm_file_to_image(game->init,
			"sprites/flip0.xpm", &x, &y);
	game->flip[1] = mlx_xpm_file_to_image(game->init,
			"sprites/flip1.xpm", &x, &y);
	game->flip[2] = mlx_xpm_file_to_image(game->init,
			"sprites/flip2.xpm", &x, &y);
	game->flip[3] = mlx_xpm_file_to_image(game->init,
			"sprites/flip3.xpm", &x, &y);
	game->flip[4] = mlx_xpm_file_to_image(game->init,
			"sprites/flip4.xpm", &x, &y);
	game->flip[5] = mlx_xpm_file_to_image(game->init,
			"sprites/flip5.xpm", &x, &y);
	return (0);
}

int	get_title(t_game *game)
{
	int	x;
	int	y;

	x = 166;
	y = 48;
	game->title[0] = mlx_xpm_file_to_image(game->init,
			"sprites/title0.xpm", &x, &y);
	game->title[1] = mlx_xpm_file_to_image(game->init,
			"sprites/title1.xpm", &x, &y);
	game->title[2] = mlx_xpm_file_to_image(game->init,
			"sprites/title2.xpm", &x, &y);
	game->title[3] = mlx_xpm_file_to_image(game->init,
			"sprites/title3.xpm", &x, &y);
	game->title[4] = mlx_xpm_file_to_image(game->init,
			"sprites/title4.xpm", &x, &y);
	game->ending = mlx_xpm_file_to_image(game->init,
			"sprites/ending.xpm", &x, &y);
	return (0);
}

int	get_menu(t_game *game)
{
	int	zero_x;
	int	zero_y;
	int	one_x;
	int	one_y;

	zero_x = 112;
	zero_y = 72;
	one_x = 112;
	one_y = 68;
	game->menu_img[0] = mlx_xpm_file_to_image(game->init,
			"sprites/menu0.xpm", &zero_x, &zero_y);
	game->menu_img[1] = mlx_xpm_file_to_image(game->init,
			"sprites/menu1.xpm", &one_x, &one_y);
	game->the_end = mlx_xpm_file_to_image(game->init,
			"sprites/the_end.xpm", &one_x, &one_y);
	return (0);
}

int	get_credits(t_game *game)
{
	int	x;
	int	y;

	x = 70;
	y = 70;
	game->credits = mlx_xpm_file_to_image(game->init,
			"sprites/credits.xpm", &x, &y);
	if (!game->credits)
		return (1);
	return (0);
}

int	get_warning(t_game *game)
{
	int	x;
	int	y;

	x = 242;
	y = 91;
	game->warning_img = mlx_xpm_file_to_image(game->init,
			"sprites/warning.xpm", &x, &y);
	if (!game->warning_img)
		return (1);
	return (0);
}

int	get_xpm(t_game *game)
{
	int	i;

	i = 0;
	i += get_doors(game);
	i += get_player(game);
	i += get_background(game);
	i += get_collect(game);
	i += get_walls(game);
	i += get_animation(game);
	i += get_title(game);
	i += get_menu(game);
	i += get_credits(game);
	i += get_warning(game);
	return (i);
}
