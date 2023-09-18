/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 05:56:27 by igenial           #+#    #+#             */
/*   Updated: 2023/09/16 05:58:25 by igenial          ###   ########.fr       */
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

void fill(char **map, t_axis game, t_axis cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= game.y || cur.x < 0 || cur.x >= game.x ||
	    map[cur.y][cur.x] == '1' || map[cur.y][cur.x] == '#')
		return ;
	if (map[cur.y][cur.x] == 'E')
		return ;
	else if (map[cur.y][cur.x] == 'C')
		return ;
	else if (map[cur.y][cur.x] == 'G')
		return;

	map[cur.y][cur.x] = '#';
	fill(map, game, (t_axis){cur.x - 1, cur.y}, to_fill);
	fill(map, game, (t_axis){cur.x + 1, cur.y}, to_fill);
	fill(map, game, (t_axis){cur.x, cur.y - 1}, to_fill);
	fill(map, game, (t_axis){cur.x, cur.y + 1}, to_fill);
}

void flood_fill(char **map, t_axis game, t_axis start)
{
	fill(map, game, start, map[start.y][start.x]);
}

int	has_walls(char **map, t_axis axis)
{
	int	i;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] == '#')
			return (0);
		i++;
	}
	i = 0;
	while (map[axis.y - 1][i])
	{
		if (map[axis.y - 1][i] == '#')
			return (0);
		i++;
	}
	i = 1;
	while (i < axis.y)
	{
		if (map[i][0] != '#' && map[i][axis.x - 1] != '#')
			i++;
		else
			return (0);
	}
	return (1);
}
int	check_flowage(char **map_copy)
{
	int		i;
	int		j;
	int     index;

	i = 0;
	j = 0;
	index = 0;
	while (map_copy[i])
	{
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == 'E' || map_copy[i][j] == 'C')
			{
				while (map_copy[index])
					free(map_copy[index++]);
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
int	check_fill(char **map_copy, t_axis size)
{
	int index;

	index = 0;
	if (!has_walls(map_copy, size))
	{
		ft_printf("Error\nMap has holes on the wall!\n");
		while (map_copy[index])
			free(map_copy[index++]);
		return (0);
	}
	if (!check_flowage(map_copy))
	{
		ft_printf("Error\nPlayer is trapped\n");
		return (0);
	}
	return (1);
}


int	is_trapped(t_game *game, char **map)
{
	t_axis 	size;
	t_axis	player;
	char	**map_copy;
	int     index;

	size.x = game->map->axis->y;
	size.y = game->map->axis->x;
	player.x = game->player->axis->y;
	player.y = game->player->axis->x;
	while (index <= size.x) {
		ft_strlcpy(map_copy[index], game->map->map_grid[index], size.y);
		index++;
	}
	flood_fill(map_copy, size, player);
	if (!check_fill(map_copy, size))
		return (1);
	index = 0;
	while (game->map->map_grid[index])
	{
		free(game->map->map_grid[index]);
		index++;
	}
	return (0);
}


