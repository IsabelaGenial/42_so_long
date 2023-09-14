
#include "so_long.h"

static void	ft_render_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win->win_ptr,
	                        game->player->obj->img,
	                        TILE_SIZE * game->player->axis->y,
	                        TILE_SIZE * game->player->axis->x);
	return ;
}

int	ft_render_window(t_game *game)
{
	int		x;
	int		y;

	if (game->win->win_ptr != NULL)
	{
		ft_print_map(game);
		x = 0;
		while (game->map->map_grid[x])
		{
			y = 0;
			while (game->map->map_grid[x][y])
			{
				ft_render_object(x, y, game);
				y++;
			}
			x++;
		}
		ft_render_player(game);
		print_moves_count(game);
	}
	return (0);
}

void	ft_render_object(int x, int y, t_game *game)
{
	if (game->map->map_grid[x][y] == 'E')
		mlx_put_image_to_window(game->mlx, game->win->win_ptr,
		                        game->map->exit->path[0], TILE_SIZE * x,
		                        TILE_SIZE * y);
	if (game->map->map_grid[x][y] == 'C')
		mlx_put_image_to_window(game->mlx, game->win->win_ptr,
		                        game->collect->obj->path[0], TILE_SIZE * x,
		                        TILE_SIZE * y);
	if (game->map->map_grid[x][y] == 'G')
		mlx_put_image_to_window(game->mlx, game->win->win_ptr,
		                        game->ghost->obj->path[0], TILE_SIZE * x,
		                        TILE_SIZE * y);
	return ;
}