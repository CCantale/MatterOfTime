#ifndef MOT_H
# define MOT_H

# define GAME_NAME	"Matter of Time"
# define WINDOW_X	670	
# define WINDOW_Y	790

# include "libft/libft.h"
# include "keys_and_mlx.h"
# include "audio.h"

typedef struct game
{
	void	*init;
	void	*win;
	int		start;
	int		intro;
	int		end;
	int		warning;
	int		menu;
	int		level;
	int		time;
	int		music;
	char	**map;
	int		map_x;
	int		map_y;
	int		x_start;
	int		y_start;
	int		animation;
	void	*player[6];
	int		player_x;
	int		player_y;
	int		backwards_x;
	int		backwards_y;
	int		sand;
	void	*flip[6];
	void	*title[5];
	void	*menu_img[2];
	void	*warning_img;
	void	*out_block;
	void	*s_block;
	void	*t_block;
	void	*o_door;
	void	*c_door;
	void	*c_door_base;
	void	*turner;
	void	*jumper;
	void	*key;
	void	*background;
	void	*ending;
	void	*the_end;
	void	*credits;
}	t_game;

char	**ft_check_map(t_game *game, char *path);
int	quit(t_game *game);
void	*error_msg(char *msg);
int	error_int(char *msg);
int	update(t_game *game);
int	get_xpm(t_game *game);
void	put_whatever(t_game *game, int i, int j);
void	move(t_game *game, int key);
int	scan_for_coll(char **map);
void	get_level(t_game *game);
void	main_menu(t_game *game);
void	intro(t_game *game);
void	play_animation(t_game *game);
void	ft_open_door(t_game *game);
void	win(t_game *game);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t count, size_t size);

#endif
