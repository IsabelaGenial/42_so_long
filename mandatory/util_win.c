#include "so_long.h"

int ft_shutdown_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win->win_ptr);
	game->win->win_ptr = NULL;
	ft_close(game);
	exit(1);
}

int ft_keyboard(int key, t_game *game)
{
	if (key ==  65307)
		ft_shutdown_game(game);
	if (key == 65363)
		game->player->axis->x += 5;
	return (0);
}

void ft_open_window(t_game *game)
{
	game->win->width = (TILE_SIZE * (game)->map->axis->x);
	game->win->height = (TILE_SIZE * (game)->map->axis->y);
	game->win->win_ptr = mlx_new_window(game->mlx,game->win->width,
										   game->win->height,"Magic World of Morrigan");
	if (game->win->win_ptr == NULL)
	{
		ft_printf("ERROR: mlx_error while opening window");
		exit(1);
	}
	ft_create_sprites(game);
	ft_print_map (game);

}

void ft_clear_grid(t_game *game)
{
	int clear;

	clear = 0;
	while (game->map->map_path[clear])
	{
		free(game->map->map_grid[clear]);
		clear++;
	}
	game->map->map_path = NULL;
}

void ft_close(t_game *game)
{
	ft_clear_grid(game);
	mlx_destroy_display(game->mlx);
}

t_axis ft_position(char element, t_game *game)
{
	t_axis coords;

	coords = (t_axis){.x = 0, .y = 0};
	while(game->map->map_grid[coords.y])
	{
		while(game->map->map_grid[coords.y][coords.x])
		{
			if(game->map->map_grid[coords.y][coords.x] == element)
				return (coords);
			coords.x++;
		}
		coords.x = 0;
		coords.y++;
	}
	coords.x = 0;
	coords.y = 0;
	return (coords);
}