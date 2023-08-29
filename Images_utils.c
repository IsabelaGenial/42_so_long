
#include "so_long.h"


int ft_animation(t_data *t_mlx){
    char *relative_path[8] = {"images/1.xpm", "images/2.xpm", "images/3.xpm", "images/4.xpm", "images/5.xpm", "images/6.xpm", "images/7.xpm"};
    int img_width;
    int img_height;
    int index;

    while (1)
    {
        index = 0;
        while(relative_path[index] && index < 7) {
            t_mlx->img = mlx_xpm_file_to_image(t_mlx->mlx, relative_path[index], &img_width, &img_height);
            mlx_put_image_to_window(t_mlx->mlx, t_mlx->win, t_mlx->img, 500, 500);
            index++;
            usleep(200000);
        }
    }
    return (0);
}
void draw_map(t_data *t_mlx, char *map[MAP_WIDTH], int y) {
    int x;
    char *relative_path = {"gram.xpm"};
    int img_width;
    int img_height;

    x = 0;
    while ( x < MAP_WIDTH) {
        if (*map[x] == '1') {
            t_mlx->img = mlx_xpm_file_to_image(t_mlx->mlx, relative_path, &img_width, &img_height);
            mlx_put_image_to_window(t_mlx->mlx, t_mlx->win, t_mlx->img, x * TILE_SIZE, y * TILE_SIZE);
        }
        x++;
    }

}

void ft_print_map(t_data *t_mlx)
{
    char *read_map;
    int y;

    y = 0;
    int fd = open("map1.txt", O_RDONLY);
    if (fd != -1) {
        while (y < MAP_HEIGHT) {
            read_map = get_next_line(fd);
            draw_map(t_mlx, &read_map, y);
            free(read_map);
            lseek(fd, 1, SEEK_CUR); // Pular o caractere de nova linha
            y++;
        }
        close(fd);
    }
}