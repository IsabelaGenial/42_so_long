#include "so_long.h"

int ft_close(t_game *game)
{
    mlx_destroy_window(game->mlx,game->win);
    mlx_destroy_display(game->mlx);
	free(game->img);
	free(game->player);
    free(game->mlx);
    exit(0);
}

int ft_keyboard(int key, t_game *game)
{
    if (key ==  65307)
        ft_close(game->mlx);
	if (key == 65363)
		game->player->x += 5;
	if (key == 65363)
    return (0);
}

void ft_image_bank_player (t_game *see)
{
	see->player->player->path = ft_calloc(12,sizeof(char *));
	if (!see->player->player->path)
		return;
	see->player->player->path[0] = "./image/cat/1.xpm";
	see->player->player->path[1] = "./image/cat/2.xpm";
	see->player->player->path[2] = "./image/cat/3.xpm";
	see->player->player->path[3] = "./image/cat/4.xpm";
	see->player->player->path[4] = "./image/cat/5.xpm";
	see->player->player->path[5] = "./image/cat/6.xpm";
	see->player->player->path[6] = "./image/cat/7.xpm";
	see->player->player->path[7] = "./image/cat/8.xpm";
	see->player->player->path[8] = "./image/cat/9.xpm";
	see->player->player->path[9] = "./image/cat/10.xpm";
	see->player->player->path[10] = "./image/cat/11.xpm";
	see->player->player->path[11] = "./image/cat/12.xpm";
}

void ft_image_bank_map (t_game *see)
{
	see->img->path = ft_calloc(4, sizeof(char *));
	if(!see->img->path)
		return;
	see->img->path[0] = "./images/gram.xpm";
	see->img->path[1] = "./images/tree.xpm";
	see->img->path[2] = "./images/pay.xpm";
	see->img->path[3] = "./images/ghost.xpm";
}
