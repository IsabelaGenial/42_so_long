/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 05:51:50 by igenial           #+#    #+#             */
/*   Updated: 2023/09/18 18:32:48 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_memory(t_game *game)
{
	game->win = ft_calloc(1, sizeof(t_win));
	game->map = ft_calloc(1, sizeof(t_map));
	game->map->exit = ft_calloc(1, sizeof(t_img));
	game->map->axis = ft_calloc(1, sizeof(t_axis));
	game->map->floor = ft_calloc(1, sizeof (t_obj));
	game->map->floor->obj = ft_calloc(1, sizeof (t_img));
	game->map->wall = ft_calloc(1, sizeof (t_obj));
	game->map->wall->obj = ft_calloc(1, sizeof (t_img));
	game->player = ft_calloc(1, sizeof(t_obj));
	game->player->obj = ft_calloc(1, sizeof(t_img));
	game->player->axis = ft_calloc(1, sizeof(t_axis));
	game->collect = ft_calloc(1, sizeof(t_obj));
	game->collect->obj = ft_calloc(1, sizeof(t_img));
	game->ghost = ft_calloc(1, sizeof(t_obj));
	game->ghost->obj = ft_calloc(1, sizeof(t_img));
	if (!game->map || !game->win || !game->player || !game->collect
		|| !game->player->axis || !game->map->axis || !game->player->obj
		|| !game->ghost || !game->map->floor || !game->map->wall)
		ft_printf("ERROR: Memory allocation failed");
}

void	ft_struct_supply(t_game *game)
{
	game->map->pickup_counter = 0;
	game->map->player_count = 0;
	game->map->exit_counter = 0;
	game->map->rows = 0;
	game->player->direction = 0;
	game->map->wall->obj->width = 0;
	game->map->wall->obj->height = 0;
	game->player->moves_count = 0;
	game->map->map_grid = NULL;
}

void	ft_free_img(t_game *game)
{
	int	i;

	i = -1;
	mlx_destroy_image(game->mlx, game->map->floor->obj->img);
	mlx_destroy_image(game->mlx, game->ghost->obj->img);
	mlx_destroy_image(game->mlx, game->map->wall->obj->img);
	mlx_destroy_image(game->mlx, game->collect->obj->img);
	mlx_destroy_image(game->mlx, game->map->exit->img);
	while (++i < 5)
	{
		mlx_destroy_image(game->mlx, game->player->obj->img[i]);
	}
}

void	ft_free_win(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win->win_ptr);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

void	free_alloc(t_game *game)
{
	ft_clear_grid(game->map->map_grid);
	free(game->ghost->obj->path);
	free(game->ghost->obj);
	free(game->ghost);
	free(game->player->obj->path);
	free(game->player->obj->img);
	free(game->player->obj);
	free(game->player->axis);
	free(game->player);
	free(game->collect->obj->path);
	free(game->collect->obj);
	free(game->collect);
	free(game->map->wall->obj->path);
	free(game->map->wall->obj);
	free(game->map->wall);
	free(game->map->axis);
	free(game->map->exit->path);
	free(game->map->exit);
	free(game->map->floor->obj->path);
	free(game->map->floor->obj);
	free(game->map->floor);
	free(game->map->map_grid);
	free(game->map);
	ft_free_win(game);
	free(game->win);
	free(game);
}
