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
	ft_clear_grid(game->map->map_grid);
	free_alloc(game);
	free(game->win);
	free(game);
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

int	ft_close(t_game *game)
{
	int	i;

	i = -1;
	ft_free_img(game);
	ft_clear_grid(game->map->map_grid);
	free_alloc(game);
	ft_free_win(game);
	free(game->win);
	free(game);
	ft_printf("aqui");
	exit(1);
	return (1);
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
