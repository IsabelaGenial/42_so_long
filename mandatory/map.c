#include "so_long.h"

void ft_print_map(int fd, t_data *t_mlx)
{
    int y;
    int x;
    const char *relative_path = {"gram.xpm"};

    y = 0;
	while (y < (WIN_HEIGHT/TILE_SIZE))
    {
        x = 0;
        while (x < (WIN_WIDTH/TILE_SIZE))
        {
            t_mlx->img->path = mlx_xpm_file_to_image(t_mlx->mlx, (char *)relative_path, &t_mlx->img->width, &t_mlx->img->height); //talvez &.
            mlx_put_image_to_window(t_mlx->mlx, t_mlx->win, t_mlx->img->path, (x * TILE_SIZE), (y * TILE_SIZE));
            x++;
        }
        y++;
    }

}

void ft_print_objects(int fd, t_data *t_mlx)
{
    int y;
    int x;
    char *line;
    const char *relative_path = {"tree.xpm"};

    y = 0;

    while (y < (WIN_HEIGHT/TILE_SIZE))
    {
        x = 0;
        line = get_next_line(fd);
        while (x < (WIN_WIDTH/TILE_SIZE)) {
            if(line != NULL)
            {
                if (line[x] == '1') {
                    t_mlx->img->path = mlx_xpm_file_to_image(t_mlx->mlx, (char*)relative_path, &t_mlx->img->width, &t_mlx->img->height); //talvez &.
                    mlx_put_image_to_window(t_mlx->mlx, t_mlx->win, t_mlx->img->path, (x * TILE_SIZE), (y * TILE_SIZE));
                }
            }x++;
        }
        free(line);
        y++;
    }

}