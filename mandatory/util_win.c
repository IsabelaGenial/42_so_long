#include "so_long.h"

int ft_close(t_data *t_mlx)
{
    mlx_destroy_window(t_mlx->mlx,t_mlx->win);
    mlx_destroy_display(t_mlx->mlx);
	free(t_mlx->img);
    free(t_mlx->mlx);
    exit(0);
}

int ft_keyboard(int key, t_data *t_mlx)
{
    if (key ==  65307)
        ft_close(t_mlx);
	if (key == 65363)
		t_mlx->img->x += 5;
    return (0);
}