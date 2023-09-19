/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 05:56:27 by igenial           #+#    #+#             */
/*   Updated: 2023/09/18 16:53:49 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_image_bank_obj(t_game *see)
{
	see->player->obj->path = ft_calloc(5, sizeof(char *));
	see->player->obj->img = ft_calloc(5, sizeof(void *));
	see->ghost->obj->path = ft_calloc(2, sizeof(char *));
	see->collect->obj->path = ft_calloc(2, sizeof(char *));
	see->map->floor->obj->path = ft_calloc(2, sizeof(char *));
	see->map->wall->obj->path = ft_calloc(2, sizeof(char *));
	see->map->exit->path = ft_calloc(1, sizeof(char *));
	if (!see->ghost->obj->path || !see->player->obj->path
		|| !see->collect->obj->path || !see->map->floor->obj->path
		|| !see->map->wall->obj->path)
		ft_printf("ERROR: image bank error.");
	see->player->obj->path[0] = "./images/cat/1.xpm";
	see->player->obj->path[1] = "./images/cat/2.xpm";
	see->player->obj->path[2] = "./images/cat/3.xpm";
	see->player->obj->path[3] = "./images/cat/4.xpm";
	see->player->obj->path[4] = "./images/cat/5.xpm";
	see->ghost->obj->path[0] = "./images/ghost.xpm";
	see->collect->obj->path[0] = "./images/pay.xpm";
	see->map->floor->obj->path[0] = "./images/gram.xpm";
	see->map->wall->obj->path[0] = "./images/tree.xpm";
	see->map->exit->path[0] = "./images/exit.xpm";
	*see->player->axis = ft_position('P', see);
}

void	fill(char **map, t_axis *size, t_axis walk)
{
	if (walk.y < 0 || walk.y >= size->y || walk.x < 0 || walk.x >= size->x
		|| map[walk.y][walk.x] == '1' || map[walk.y][walk.x] == '#')
		return ;
	if (map[walk.y][walk.x] == 'E' || map[walk.y][walk.x] == 'G' )
	{
		map[walk.y][walk.x] = '#';
		return ;
	}
	map[walk.y][walk.x] = '#';
	fill(map, size, (t_axis){walk.x, walk.y + 1});
	fill(map, size, (t_axis){walk.x, walk.y - 1});
	fill(map, size, (t_axis){walk.x - 1, walk.y});
	fill(map, size, (t_axis){walk.x + 1, walk.y});
}

int	ft_collect(char **map_grid)
{
	int	y;
	int	x;

	y = 0;
	while (map_grid[y])
	{
		x = 0;
		while (map_grid[y][x] && map_grid[y][x] != '\n')
		{
			if (map_grid[y][x] == 'C')
				return (ft_printf("ERROR: collect.\n"));
			if (map_grid[y][x] == 'E')
				return (ft_printf("ERROR: exit.\n"));
			if (map_grid[y][x] == 'G')
				return (ft_printf("ERROR: ghost.\n"));
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_route_validation(t_game *game)
{
	t_map	*fake_map;
	t_axis	walker;
	int		i;

	i = 0;
	fake_map = ft_calloc(1, sizeof(t_map));
	fake_map->axis = ft_calloc(1, sizeof(t_axis));
	ft_bzero(&walker, sizeof(t_axis));
	fake_map->map_grid = ft_calloc(game->map->axis->y + 1, sizeof(char *));
	while (i <= game->map->axis->y)
	{
		fake_map->map_grid[i] = ft_substr(game->map->map_grid[i], \
0, game->map->axis->x);
		i++;
	}
	fake_map->axis->y = game->map->axis->y;
	fake_map->axis->x = game->map->axis->x;
	walker.x = game->player->axis->x;
	walker.y = game->player->axis->y;
	fill(fake_map->map_grid, fake_map->axis, walker);
	if (ft_collect(fake_map->map_grid))
		return (ft_flood_free(fake_map));
	ft_flood_free(fake_map);
	return (0);
}
