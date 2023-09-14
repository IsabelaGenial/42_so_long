#include "so_long.h"


void ft_image_bank_obj (t_game *see)
{
	see->player->obj->path = ft_calloc(4,sizeof(char *));
	see->ghost->obj->path = ft_calloc(2, sizeof(char *));
	see->collect->obj->path = ft_calloc(2, sizeof(char *));
	see->map->floor->obj->path = ft_calloc(2, sizeof(char *));
	see->map->wall->obj->path = ft_calloc(2, sizeof(char *));
	see->map->wall->obj->img = ft_calloc(1, sizeof(void *));
	if (!see->ghost->obj->path || !see->player->obj->path || !see->collect->obj->path
		|| !see->map->floor->obj->path || !see->map->wall->obj->path)
		ft_printf("ERROR: image bank error.");
	see->player->obj->path[0] = "./images/cat/1.xpm";
	see->player->obj->path[1] = "./images/cat/2.xpm";
	see->player->obj->path[2] = "./images/cat/3.xpm";
	see->player->obj->path[3] = "./images/cat/4.xpm";
	see->ghost->obj->path[0] = "./images/ghost.xpm";
	see->collect->obj->path[0] = "./images/pay.xpm";
	see->map->floor->obj->path[0] = "./images/gram.xpm";
	see->map->wall->obj->path[0] = "./images/tree.xpm";
	*see->player->axis = ft_position('P',see);
}

void ft_print_map (t_game *game)
{
	int y;
	int x;

	y = 0;
	while (game->map->map_grid[y])
	{
		x = 0;
		while (game->map->map_grid[y][x])
		{
			if (game->map->map_grid[y][x] == '1')
				mlx_put_image_to_window(game->mlx,game->win->win_ptr,
										game->map->wall->obj->img, (TILE_SIZE * x), (TILE_SIZE * y));
			else
				mlx_put_image_to_window(game->mlx,game->win->win_ptr,
										game->map->floor->obj->img, (TILE_SIZE * x), (TILE_SIZE * y));
			x++;
		}
		y++;
	}
}



