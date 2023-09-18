/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:26:18 by igenial           #+#    #+#             */
/*   Updated: 2023/09/18 18:30:02 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_create_sprites(t_game *game)
{
	ft_render_wall(game);
	ft_render_floor(game);
	ft_create_player(game);
	ft_render_pickup(game);
	ft_render_ghost(game);
	ft_render_exit(game);
}

void	ft_render_exit(t_game *game)
{
	game->map->exit->img = mlx_xpm_file_to_image(game->mlx,
			game->map->exit->path[0], &game->map->exit->width,
			&game->map->exit->height);
	if (!game->map->exit->img)
	{
		ft_printf("ERROR: Creating exit\n");
		exit(0);
	}
}

void	ft_render_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win->win_ptr,
		game->player->obj->img[game->player->direction],
		TILE_SIZE * game->player->axis->x,
		TILE_SIZE * game->player->axis->y);
	return ;
}

void	ft_render_object(int x, int y, t_game *game)
{
	if (game->map->map_grid[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win->win_ptr,
			game->map->exit->img, TILE_SIZE * x, TILE_SIZE * y);
	if (game->map->map_grid[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win->win_ptr,
			game->collect->obj->img, TILE_SIZE * x, TILE_SIZE * y);
	if (game->map->map_grid[y][x] == 'G')
		mlx_put_image_to_window(game->mlx, game->win->win_ptr,
			game->ghost->obj->img, TILE_SIZE * x, TILE_SIZE * y);
	if (game->map->map_grid[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win->win_ptr,
			game->map->wall->obj->img, (TILE_SIZE * x), (TILE_SIZE * y));
	if (game->map->map_grid[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->win->win_ptr,
			game->map->floor->obj->img, (TILE_SIZE * x), (TILE_SIZE * y));
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
