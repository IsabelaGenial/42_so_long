#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

//#define MAP_WIDTH 20
//#define MAP_HEIGHT 20
#define TILE_SIZE 66
#define WIN_WIDTH 1188
#define WIN_HEIGHT 990
typedef struct s_data
{
    void *mlx;
    void *win;
    void *img;
    void *img2;
}   t_data;

int ft_keyboard(int key, t_data *t_mlx);
int ft_close(t_data *t_mlx);
int ft_animation(void *arg);
void ft_print_map(int fd, t_data *t_mlx);
char	*get_next_line(int fd);
void ft_print_objects(int fd, t_data *t_mlx);
#endif