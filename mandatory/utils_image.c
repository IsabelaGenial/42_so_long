#include "so_long.h"


void ft_image_bank_player (t_game *see)
{
	see->player->player->path = ft_calloc(4,sizeof(char *));
	if (!see->player->player->path)
		return;
	see->player->player->path[0] = "../image/cat/1.xpm";
	see->player->player->path[1] = "../image/cat/2.xpm";
	see->player->player->path[2] = "../image/cat/3.xpm";
	see->player->player->path[3] = "../image/cat/4.xpm";
	return;

}

void ft_image_bank_map (t_game *see)
{
	see->map->floor->path = ft_calloc(1, sizeof(char *));
	see->map->wall->path = ft_calloc(1, sizeof(char *));
	see->map->ghost->path = ft_calloc(1, sizeof(char *));
	if(!see->map->floor->path || !see->map->wall->path || !see->map->ghost->path)
		return;
	see->map->floor->path[0] = "../images/gram.xpm";
	see->map->wall->path[0] = "../images/tree.xpm";
	see->map->ghost->path[0] = "../images/ghost.xpm";
	return;
}

void ft_print_map (t_game **game)
{
	int y;
	int x;

	y = 0;
	while ((*game)->map->map_path[y])
	{
		x = 0;
		while ((*game)->map->map_path[y][x])
		{
			if ((*game)->map->map_path[y][x] == 1)
			{
				mlx_put_image_to_window((*game)->mlx,(*game)->win->win_ptr,
						(*game)->map->wall->path[0], (TILE_SIZE * x), (TILE_SIZE * y));
			}
			else
				mlx_put_image_to_window((*game)->mlx, (*game)->win->win_ptr,
										(*game)->map->floor->path[0], (TILE_SIZE * x), (TILE_SIZE * y));
			x++;
		}
		y++;
	}
	return;
}

void ft_render_wall(t_game **game)
{
	(*game)->map->wall->img = mlx_xpm_file_to_image((*game)->mlx,
													(*game)->map->wall->path[0],
													&(*game)->map->wall->width,&(*game)->map->wall->height);
	if(!(*game)->map->wall->img)
	{
		ft_printf("ERROR: Creating wall");
		exit(0);
	}
	return;
}

void ft_render_floor(t_game **game)
{
	(*game)->map->floor->img = mlx_xpm_file_to_image((*game)->mlx,
	                                                (*game)->map->floor->path[0],
	                                                &(*game)->map->floor->width,&(*game)->map->floor->height);
	if(!(*game)->map->floor->img)
	{
		ft_printf("ERROR: Creating floor");
		exit(0);
	}
	return;
}

void ft_render_Ghost(t_game **game)
{
	(*game)->map->ghost->img = mlx_xpm_file_to_image((*game)->mlx,
	                                                 (*game)->map->ghost->path[0],
	                                                 &(*game)->map->ghost->width,&(*game)->map->ghost->height);
	if(!(*game)->map->ghost->img)
	{
		ft_printf("ERROR: Creating ghost");
		exit(0);
	}
	return;
}
