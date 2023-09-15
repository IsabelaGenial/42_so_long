#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libfstonk/libft.h"


# define TILE_SIZE 66
# define CHAR_MAP	"EPC10G"

typedef struct S_AXIS
{
	int x;
	int y;
}       t_axis;

typedef struct s_draw{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_width;
	int		endian;
}				t_draw;


typedef struct S_IMG
{
	char    **path;
	void    *img;
	int     width;
	int     height;

}			t_img;

typedef struct S_obj
{
	t_img   *obj;
	t_axis  *axis;
	int     moves_count;
	int     pickup_count;
	int     direction;
}			t_obj;

typedef struct S_MAP
{
	size_t  cols;
	size_t  rows;
	int     pickup_counter;
	int     player_count;
	int     exit_counter;
	char    **map_grid;
	t_axis  *axis;
	t_img 	*exit;
	t_obj	*floor;
	t_obj	*wall;
	t_list	*rows_list;
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
	t_obj       *player;
	t_obj       *ghost;
	t_obj       *collect;
	t_map       *map;
	t_draw      *draw;
}               t_game;

//image bank.//
void    ft_image_bank_obj (t_game *see);
void    ft_create_sprites (t_game *game);
int     ft_render_window(t_game *game);
void	ft_render_object(int x, int y, t_game *game);

//map.//
int     ft_handle_map_input (int count_arg, char *map, t_game *game);
int     ft_line_count(int fd);
void    ft_save_map(char *map, t_game *game);
void    ft_check_map(t_game *game);
void    ft_check_object (t_game *game);
int     ft_check_wall(t_game *game);


//window//
void    ft_input_validation(int count_arg, char * arg, t_game *game);
void    ft_open_window(t_game *game);
void    ft_event_win(t_game *game);
void    ft_close(t_game *game);
void    ft_clear_grid(t_game *game);
t_axis  ft_position(char element, t_game *game);
void    ft_memory(t_game *game);
int     ft_keyboard(int key, t_game *game);

void    ft_walk_left(t_game *game);
void    ft_walk_right(t_game *game);

void    ft_walk_up(t_game *game);
void    ft_struct_supply(t_game *game);
void    ft_render_img(t_game *game);
int     ft_shutdown_game(t_game *game);
void	ft_print_map (t_game *game);
void    free_alloc(t_game *game);
#endif