#include "so_long.h"


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

void ft_print_map (t_game *game)
{
	int y;
	int x;

	y = 0;
	while (game->map->map_path[y])
	{
		x = 0;
		while (game->map->map_path[y][x])
		{
			if (game->map->map_path[y][x] == 1)
			{
				mlx_put_image_to_window(&game->win->win_ptr,
				                        &game->map->wall_img,
				                        (TILE_SIZE * x),
				                        (TILE_SIZE * y));
			}
			else
				mlx_put_image_to_window(&game->win->win_ptr,
										&game->map->floor_img,
										(TILE_SIZE * x),
										(TILE_SIZE * y));
			x++;
		}
		y++;
	}
}