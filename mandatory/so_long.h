#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../GNL/get_next_line.h"
# include "../Printf/ft_printf.h"


# define TILE_SIZE 66
//#define WIN_WIDTH 1188
//#define WIN_HEIGHT 990

typedef struct S_IMG
{
	char    **path;
	void    *img;
	int     width;
	int     height;

}			t_img;

typedef struct S_PLAYER
{
	t_img   *player;
	int     x;
	int     y;
	int     moves_count;
}			t_player;

typedef struct S_MAP
{
	int     x_axis;
	int     y_axis;
	int     pickup_counter;
	int     player_count;
	int     exit_counter;
	char    **map_path;
	char	*exit_path;
	void	*exit_img;
	char	*floor_path;
	void	*floor_img;
	char	*wall_path;
	void	*wall_img;
}			t_map;

typedef struct S_WIN
{
	void    *win_ptr;
	int     width;
	int     height;
}           t_win;

typedef struct 	S_GAME
{
	void        *mlx;
	t_win       *win;
	t_player    *player;
	t_img       *img;
	t_map       *map;
}               t_game;

//image bank.//
void	ft_image_bank_player (t_game *see);
void	ft_image_bank_map (t_game *see);

//map.//
int		ft_check_wall (t_game *game);
void	ft_print_map (t_game *game);
void    ft_save_map(char *map, t_game *game);

//window//
int     ft_keyboard(int key, t_game *game);
int    ft_close(t_game *game);

#endif