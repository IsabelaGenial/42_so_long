
#include "so_long.h"


int main ()
{
    t_data t_mlx;
    void *mlx;
    void *win;


    mlx = mlx_init();
    win = mlx_new_window(mlx, 1000, 1000, "so_long");
    t_mlx.mlx = mlx;
    t_mlx.win = win;
    mlx_key_hook(t_mlx.win, &ft_keyboard, &t_mlx);
    mlx_hook(t_mlx.win, 17,1L<<3, ft_close, &t_mlx);
    ft_print_map(&t_mlx);
    mlx_loop(t_mlx.mlx);
}


