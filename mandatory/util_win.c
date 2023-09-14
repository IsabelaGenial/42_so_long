#include "so_long.h"

int ft_shutdown_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win->win_ptr);
	game->win->win_ptr = NULL;
	ft_close(game);
	exit(1);
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