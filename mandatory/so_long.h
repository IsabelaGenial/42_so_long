#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libfstonk/libft.h"


# define TILE_SIZE 66
# define CHAR_MAP	"EPC10G"

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
	t_img 	*exit;
	t_img	*ghost;
	t_img	*floor;
	t_img	*wall;
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
int     ft_handle_map_input (int count_arg, char *map, t_game **game);
int     ft_line_count(int fd);
void    ft_save_map(char *map, t_game **game);
void    ft_check_map(t_game **game);
void    ft_check_object (t_game **game);
int     ft_check_wall(t_game **game);

//window//
void    ft_memory(t_game **game);
void    ft_open_window(t_game **game);
int     ft_keyboard(int key, t_game **game);
void     ft_close(t_game **game);
void    ft_clear_grid(t_game **game);
int     ft_shutdown_game(t_game **game);
void	ft_print_map (t_game **game);

//back windows.//
void    ft_struct_supply(t_game **game);
void ft_render_img(t_game **game);

#endif