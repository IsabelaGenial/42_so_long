#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

#define MAP_WIDTH 15
#define MAP_HEIGHT 15
#define TILE_SIZE 1000

typedef struct s_data
{
    void *mlx;
    void *win;
    void *img;
}   t_data;

int ft_keyboard(int key, t_data *t_mlx);
int ft_close(t_data *t_mlx);
int ft_animation(t_data *t_mlx);
void draw_map(t_data *t_mlx, char *map[MAP_WIDTH], int y);
void ft_print_map(t_data *t_mlx);
char	*get_next_line(int fd);
#endif