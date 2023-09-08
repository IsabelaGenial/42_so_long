#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../GNL/get_next_line.h"


#define TILE_SIZE 66
#define WIN_WIDTH 1188
#define WIN_HEIGHT 990

typedef struct s_img
{
	char    *path;
	void    *img;
	int     width;
	int     height;

} t_img;
typedef struct s_palyer
{
	t_img   *player;
	int     x;
	int     y;
	int     moves_count;
}   t_player;

typedef struct s_map
{
	size_t  x_axis;
	size_t  y_axis;
	int     pickup_counter;
	int     player_count;
	int     exit_counter;
	char    *map_path;
	char	*exit_path;
	void	*exit_img;
	char	*floor_path;
	void	*floor_img;
	char	*wall_path;
	void	*wall_img;
} t_map;

typedef struct s_win
{
    void    *win_ptr;
	int     width;
	int     height;
}           t_win;

typedef struct s_game
{
	void        *mlx;
	t_win       *win;
	t_player    *player;
	t_img       *img;
	t_map       *map;
}               t_game;


int ft_keyboard(int key, t_data *t_mlx);
int ft_close(t_data *t_mlx);
int ft_animation(void *arg);
void ft_print_map(int fd, t_data *t_mlx);
char	*get_next_line(int fd);
void ft_print_objects(int fd, t_data *t_mlx);
#endif