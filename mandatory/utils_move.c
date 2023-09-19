/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:15:04 by igenial           #+#    #+#             */
/*   Updated: 2023/09/18 18:23:13 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_walker_down(t_game *game)
{
	char	walker;

	walker = game->map->map_grid[game->player->axis->y + 1][
		game->player->axis->x];
	if (walker == 'E'
		&& game->player->pickup_count == game->map->pickup_counter)
	{
		game->player->axis->y++;
		game->player->moves_count++;
		ft_close(game);
	}
	if (walker != '1' && walker != 'E')
	{
		game->map->map_grid[game->player->axis->y][
			game->player->axis->x] = '0';
		game->player->axis->y++;
		game->player->moves_count++;
		if (game->map->map_grid[game->player->axis->y][
			game->player->axis->x] == 'C')
		{
			game->map->map_grid[game->player->axis->y][
				game->player->axis->x] = '0';
			game->player->pickup_count++;
		}
	}
}

void	ft_walker_up(t_game *game)
{
	char	walker;

	walker = game->map->map_grid[game->player->axis->y - 1][
		game->player->axis->x];
	if (walker == 'E'
		&& game->player->pickup_count == game->map->pickup_counter)
	{
		game->player->axis->y--;
		game->player->moves_count++;
		ft_close(game);
	}
	if (walker != '1' && walker != 'E')
	{
		game->map->map_grid[game->player->axis->y][
			game->player->axis->x] = '0';
		game->player->axis->y--;
		game->player->moves_count++;
		if (game->map->map_grid[game->player->axis->y][
			game->player->axis->x] == 'C')
		{
			game->map->map_grid[game->player->axis->y][
				game->player->axis->x] = '0';
			game->player->pickup_count++;
		}
	}
}

void	ft_walker_right(t_game *game)
{
	char	walker;

	walker = game->map->map_grid[game->player->axis->y][
		game->player->axis->x + 1];
	if (walker == 'E'
		&& game->player->pickup_count == game->map->pickup_counter)
	{
		game->player->axis->x++;
		game->player->moves_count++;
		ft_close(game);
	}
	if (walker != '1' && walker != 'E')
	{
		game->map->map_grid[game->player->axis->y][
			game->player->axis->x] = '0';
		game->player->axis->x++;
		game->player->moves_count++;
		if (game->map->map_grid[game->player->axis->y][
			game->player->axis->x] == 'C')
		{
		game->map->map_grid[game->player->axis->y][
				game->player->axis->x] = '0';
		game->player->pickup_count++;
		}
	}
}

void	ft_walker_left(t_game *game)
{
	char	walker;

	walker = game->map->map_grid[game->player->axis->y][
		game->player->axis->x - 1];
	if (walker == 'E'
		&& game->player->pickup_count == game->map->pickup_counter)
	{
		game->player->axis->x--;
		game->player->moves_count++;
		ft_close(game);
	}
	if (walker != '1' && walker != 'E')
	{
		game->map->map_grid[game->player->axis->y][game->player->axis->x] = '0';
		game->player->axis->x--;
		game->player->moves_count++;
		if (game->map->map_grid[game->player->axis->y][
			game->player->axis->x] == 'C')
		{
			game->map->map_grid[game->player->axis->y][
				game->player->axis->x] = '0';
			game->player->pickup_count++;
		}
	}
}

int	ft_flood_free(t_map *fake_map)
{
	ft_clear_grid(fake_map->map_grid);
	free(fake_map->axis);
	free(fake_map->map_grid);
	free(fake_map);
	return (1);
}
