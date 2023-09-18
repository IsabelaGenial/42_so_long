/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 05:01:58 by igenial           #+#    #+#             */
/*   Updated: 2023/09/18 18:30:51 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_walk_left(t_game *game)
{
	char	walker;

	walker = game->map->map_grid[game->player->axis->y][
		game->player->axis->x - 1];
	game->player->direction = 2;
	ft_walker_left(game);
	if (walker == 'G')
		ft_close(game);
}

void	ft_walk_right(t_game *game)
{
	char	walker;

	walker = game->map->map_grid[game->player->axis->y][
		game->player->axis->x + 1];
	game->player->direction = 4;
	ft_walker_right(game);
	if (walker == 'G')
		ft_close(game);
}

void	ft_walk_up(t_game *game)
{
	char	walker;

	walker = game->map->map_grid[game->player->axis->y - 1][
		game->player->axis->x];
	game->player->direction = 1;
	ft_walker_up(game);
	if (walker == 'G')
		ft_close(game);
}

void	ft_walk_down(t_game *game)
{
	char	walker;

	walker = game->map->map_grid[game->player->axis->y + 1][
		game->player->axis->x];
	game->player->direction = 3;
	ft_walker_down(game);
	if (walker == 'G')
		ft_close(game);
}
