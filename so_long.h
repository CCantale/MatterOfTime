#ifndef SO_LONG_H
# define SO_LONG_H

# define GAME_NAME	"Matter of Time"
# define WINDOW_X	640	
# define WINDOW_Y	640

# include <fcntl.h>
# include "libft/libft.h"
# include "keys_and_mlx.h"

typedef struct game
{
	void	*init;
	void	*win;
	int		start;
	int		menu;
	int		level;
	char	**map;
	int		map_x;
	int		map_y;
	int		x_start;
	int		y_start;
	void	*player[6];
	int		player_x;
	int		player_y;
	int		backwards_x;
	int		backwards_y;
	int		sand;
	void	*out_block;
	void	*s_block;
	void	*t_block;
	void	*o_door;
	void	*turner;
	void	*background;
}	t_game;

char	**ft_check_map(t_game *game, char *path);
void	quit(t_game *game);
void	*error_msg(char *msg);
int		error_int(char *msg);
int		update(t_game *game);
int		get_xpm(t_game *game);
void	put_whatever(t_game *game, int i, int j);
void	move(t_game *game, int key);
int		scan_for_coll(char **map);
void	get_level(t_game *game);
void	main_menu(t_game *game);

#endif
