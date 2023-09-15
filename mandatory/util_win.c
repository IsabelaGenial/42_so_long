#include "so_long.h"

int ft_shutdown_game(t_game *game)
{
	ft_close(game);
	exit(1);
}
void ft_clear_grid(t_game *game)
{
	int clear;

	clear = 0;
	while (game->map->map_grid[clear])
	{
		free(game->map->map_grid[clear]);
		clear++;
	}
}

void ft_close(t_game *game)
{
	ft_clear_grid(game);
	free_alloc(game);
	mlx_destroy_window(game->mlx, game->win->win_ptr);
	mlx_destroy_display(game->mlx);
}

void free_alloc(t_game *game)
{
mlx_destroy_image(game->mlx, game->map->floor->obj->img);
mlx_destroy_image(game->mlx, game->ghost->obj->img);
mlx_destroy_image(game->mlx, game->player->obj->img);
mlx_destroy_image(game->mlx, game->map->wall->obj->img);
mlx_destroy_image(game->mlx, game->map->exit->img);
mlx_destroy_image(game->mlx, game->collect->obj->img);
	free(game->ghost->obj->path);
	free(game->ghost->obj);
	free(game->ghost);
	free(game->player->obj->path);
	free(game->player->obj);
	free(game->player->axis);
	free(game->player);
	free(game->collect->obj->path);
	free(game->collect->obj);
	free(game->collect);
	free(game->map->wall->obj->path);
	free(game->map->wall->obj);
	free(game->map->wall);
	free(game->map->axis);
	free(game->map->exit->path);
	free(game->map->exit);
	free(game->map->floor->obj->path);
	free(game->map->floor->obj);
	free(game->map->floor);
	free(game->map->map_grid);
	free(game->win);
	free(game->map);
	free(game);


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