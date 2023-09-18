/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 05:29:22 by igenial           #+#    #+#             */
/*   Updated: 2023/09/18 17:00:14 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_shutdown_game(t_game *game)
{
	ft_free_img(game);
	free_alloc(game);
	exit(1);
}

void	ft_clear_grid(char **game)
{
	int	clear;

	clear = 0;
	while (game[clear])
	{
		free(game[clear]);
		clear++;
	}
}

void	ft_close(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 5)
	{
		mlx_destroy_image(game->mlx, game->player->obj->img[i]);
	}
	ft_clear_grid(game->map->map_grid);
	free_alloc(game);
	free(game->mlx);
	free(game->win);
	free(game);
	exit(1);
}

t_axis	ft_position(char element, t_game *game)
{
	t_axis	coords;

	coords = (t_axis){.x = 0, .y = 0};
	while (game->map->map_grid[coords.y])
	{
		while (game->map->map_grid[coords.y][coords.x])
		{
			if (game->map->map_grid[coords.y][coords.x] == element)
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
