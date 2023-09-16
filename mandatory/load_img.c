/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:41:18 by igenial           #+#    #+#             */
/*   Updated: 2023/09/16 05:51:10 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_render_wall(t_game *game);
static void	ft_render_floor(t_game *game);
static void	ft_render_player(t_game *game);
static void	ft_render_pickup(t_game *game);
static void	ft_render_ghost(t_game *game);
static void	ft_render_exit(t_game *game);
static void	ft_render_moves(t_game *game);

void	ft_create_sprites(t_game *game)
{
	ft_render_wall(game);
	ft_render_floor(game);
	ft_render_player(game);
	ft_render_pickup(game);
	ft_render_ghost(game);
	ft_render_exit(game);
}

static void	ft_render_ghost(t_game *game)
{
	game->ghost->obj->img = mlx_xpm_file_to_image(game->mlx,
			game->ghost->obj->path[0], &game->ghost->obj->width,
			&game->ghost->obj->height);
	if (!game->ghost->obj->img)
	{
		ft_printf("ERROR: Creating ghost\n");
		exit(0);
	}
}

static void	ft_render_floor(t_game *game)
{
	game->map->floor->obj->img = mlx_xpm_file_to_image(game->mlx,
			game->map->floor->obj->path[0], &game->map->floor->obj->width,
			&game->map->floor->obj->height);
	if (!game->map->floor->obj->img)
	{
		ft_printf("ERROR: Creating floor\n");
		exit(0);
	}
}

static void	ft_render_player(t_game *game)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		game->player->obj->img[i] = mlx_xpm_file_to_image(game->mlx,
				game->player->obj->path[i], &game->player->obj->width,
				&game->player->obj->height);
		if (!game->player->obj->img[i])
		{
			ft_printf("ERROR: Creating brain\n");
			exit(0);
		}
		i++;
	}
}

static void	ft_render_wall(t_game *game)
{
	game->map->wall->obj->img = mlx_xpm_file_to_image(game->mlx,
			game->map->wall->obj->path[0], &game->map->wall->obj->width,
			&game->map->wall->obj->height);
	if (!game->map->wall->obj->img)
	{
		ft_printf("ERROR: Creating wall\n");
		exit(0);
	}
}

static void	ft_render_exit(t_game *game)
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

static void	ft_render_pickup(t_game *game)
{
	game->collect->obj->img = mlx_xpm_file_to_image(game->mlx,
			game->collect->obj->path[0], &game->collect->obj->width,
			&game->collect->obj->height);
	if (!game->collect->obj->img)
	{
		ft_printf("ERROR: render_pickup\n");
		exit(0);
	}
}
