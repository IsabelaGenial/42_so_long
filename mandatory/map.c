
#include "so_long.h"

void ft_print_map (t_game *game) {
	int y;
	int x;

	y = 0;
	ft_image_bank_map(game);
	while (game->map->map_path[y]) {
		x = 0;
		while (game->map->map_path[y][x]) {
			if (game->map->map_path[y][x] == '1') {
				game->img->img = mlx_xpm_file_to_image(game->mlx, game->img->path[1], &game->img->width,
				                                       &game->img->height); //talvez &.
				mlx_put_image_to_window(game->mlx, game->win, game->img->path, (x * TILE_SIZE), (y * TILE_SIZE));
			}
			x++;
		}
		y++;
	}
}

void ft_save_map(char *map, t_game *game)
{
	int fd;
	int count;
	int y;

	fd = open(map, O_RDONLY);
	count = 0;
	if (!fd) {
		ft_printf("error in open file map");
	}
	y = 0;
	game->map->map_path = ft_calloc ((count + 1), sizeof (char *));
	open (map, O_RDONLY);
	while(game->map->map_path[y])
	{
		game->map->map_path[y] = get_next_line(fd);
		y++;
	}
	game->map->y_axis = y;
	close(fd);
}

int ft_check_wall (t_game *game)
{
		int y_axis;
		int x_axis;

		y_axis = 0;
		game->map->x_axis = (int)ft_strlen(game->map->map_path[0]);
		while (game->map->map_path[y_axis])
		{
			x_axis = 0;
			while (game->map->map_path[y_axis][x_axis])
			{
				if(y_axis == 0 || y_axis == game->map->y_axis ||
				   x_axis == 0 || x_axis == game->map->x_axis)
				{
					if (game->map->map_path[y_axis][x_axis] == 1)
						x_axis++;
					else
						return(ft_printf ("ERROR in WALL"));
				}
				x_axis++;
			}
			y_axis++;
		}
		return(1);
}

int ft_close(t_game *game)
	{
		mlx_destroy_window(game->mlx,game->win);
		mlx_destroy_display(game->mlx);
		free(game->img);
		free(game->player);
		free(game->mlx);
		return (0);
	}

int ft_keyboard(int key, t_game *game)
{
	if (key ==  65307)
		ft_close(game->mlx);
	if (key == 65363)
		game->player->x += 5;
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