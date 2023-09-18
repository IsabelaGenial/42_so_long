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

t_map   ft_chain_action(int x,int y, t_game *game);
int ft_check_position(int x, int y, char p, t_game *game);

t_map ft_chain_action(int x,int y, t_game *game)
{
	t_map collect;
	ft_bzero(&collect, sizeof(t_map));
	if (game->map->map_grid[y][x] == '0' || game->map->map_grid[y][x] == 'C')
	{
		collect.exit_counter += ft_check_position(x, y, 'E', game);
		collect.pickup_counter += ft_check_position(x, y, 'C', game);
		collect.player_count += ft_check_position(x, y, 'G', game);
	}
	ft_check_position(x, y, '0', game);
	return (collect);
}
 int ft_check_position(int x, int y, char p, t_game *game)
 {
	int pos;

	pos = 0;
	if (game->map->map_grid[y][x - 1] == p && (x - 1) >= 0)
	{
		pos += 1;
		ft_chain_action((x - 1), y, game);
	}
	if (game->map->map_grid[y][x + 1] == p && (x + 1) <= game->map->axis->x)
	{
		pos += 1;
		ft_chain_action((x + 1), y, game);
	}
	if (game->map->map_grid[y - 1][x] == p && (y - 1) <= 0)
	{
		pos += 1;
		ft_chain_action((x), (y - 1), game);
	}
	if(game->map->map_grid[y + 1][x] == p && (y + 1) >= game->map->axis->y)
	{
		pos += 1;
		ft_chain_action((x), (y + 1), game);
	}
	 return (pos);
 }