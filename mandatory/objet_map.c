
#include "so_long.h"

static void	ft_render_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win->win_ptr,
	                        game->player->obj->img,
	                        TILE_SIZE * game->player->axis->x,
	                        TILE_SIZE * game->player->axis->y);
	return ;
}
int	ft_render_window(t_game *game)
{
	int		x;
	int		y;

	if (game->win->win_ptr != NULL)
	{
		y = 0;
		while (game->map->map_grid[y])
		{
			x = 0;
			while (game->map->map_grid[y][x])
			{
				ft_render_object(x, y, game);
				x++;
			}
			y++;
		}
		ft_render_player(game);
	}
	return (0);
}

void	ft_render_object(int x, int y, t_game *game)
{
	if (game->map->map_grid[y][x] == 'E')
		mlx_put_image_to_window(
				game->mlx,
				game->win->win_ptr, game->map->exit->img,
								TILE_SIZE * x,
		                        TILE_SIZE * y);
	if (game->map->map_grid[y][x] == 'C')
		mlx_put_image_to_window(
				game->mlx, game->win->win_ptr,
		                        game->collect->obj->img,
								TILE_SIZE * x,
		                        TILE_SIZE * y);
	if (game->map->map_grid[y][x] == 'G')
		mlx_put_image_to_window(game->mlx, game->win->win_ptr,
		                        game->ghost->obj->img, TILE_SIZE * x,
		                        TILE_SIZE * y);
	if (game->map->map_grid[y][x] == '1')
		mlx_put_image_to_window(game->mlx,game->win->win_ptr,
		                        game->map->wall->obj->img, (TILE_SIZE * x), (TILE_SIZE * y));
	if (game->map->map_grid[y][x] == '0')
		mlx_put_image_to_window(game->mlx,game->win->win_ptr,
		                        game->map->floor->obj->img, (TILE_SIZE * x), (TILE_SIZE * y));
}

void    ft_walk_left(t_game *game)
{
	char	walker;

	walker = game->map->map_grid[game->player->axis->y][game->player->axis->x - 1];
	if (walker == 'E' && game->player->pickup_count == game->map->pickup_counter)
	{
		game->player->axis->x--;
		game->player->moves_count++;
	}
	if (walker == 'G')
		ft_close(game);
	if (walker != '1' && walker != 'E')
	{
		game->player->axis->x--;
		game->player->moves_count++;
		if (game->map->map_grid[game->player->axis->y][game->player->axis->x] == 'C')
		{
			game->map->map_grid[game->player->axis->y][game->player->axis->x] = '0';
			game->player->pickup_count++;
		}
	}
}

void    ft_walk_right(t_game *game)
{
	char	walker;

	walker = game->map->map_grid[game->player->axis->y][game->player->axis->x + 1];
	if (walker == 'E' && game->player->pickup_count == game->map->pickup_counter)
	{
		game->player->axis->x++;
		game->player->moves_count++;
	}
	if (walker == 'G')
		ft_close(game);
	if (walker != '1' && walker != 'E')
	{
		game->player->axis->x++;
		game->player->moves_count++;
		if (game->map->map_grid[game->player->axis->y][game->player->axis->x] == 'C')
		{
			game->map->map_grid[game->player->axis->y][game->player->axis->x] = '0';
			game->player->pickup_count++;
		}
	}
}

void    ft_walk_up(t_game *game)
{
	char	walker;

	walker = game->map->map_grid[game->player->axis->y - 1][game->player->axis->x];
	//game->player->direction = 'j';
	if (walker == 'E' && game->player->pickup_count == game->map->pickup_counter)
	{
		game->player->axis->y--;
		game->player->moves_count++;
		//ft_render_you_won(game);
	}
	if (walker == 'G')
		ft_close(game);
	if (walker != '1' && walker != 'E')
	{
		game->player->axis->y--;
		game->player->moves_count++;
		if (game->map->map_grid[game->player->axis->y][game->player->axis->x] == 'C')
		{
			game->map->map_grid[game->player->axis->y][game->player->axis->x] = '0';
			game->player->pickup_count++;
		}
	}
}

void    ft_walk_down(t_game *game)
{
	char	walker;

	walker = game->map->map_grid[game->player->axis->y + 1][game->player->axis->x];
	if (walker == 'E' && game->player->pickup_count == game->map->pickup_counter)
	{
		game->player->axis->y++;
		game->player->moves_count++;
		//ft_render_you_won(game);
	}
	if (walker == 'G')
		ft_close(game);
	if (walker != '1' && walker != 'E')
	{
		game->player->axis->y++;
		game->player->moves_count++;
		if (game->map->map_grid[game->player->axis->y][game->player->axis->x] == 'C')
		{
			game->map->map_grid[game->player->axis->y][game->player->axis->x] = '0';
			game->player->pickup_count++;
		}
	}
}