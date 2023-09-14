/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:41:18 by igenial           #+#    #+#             */
/*   Updated: 2023/09/13 17:53:11 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void    ft_render_wall(t_game *game);
static void    ft_render_floor(t_game *game);
static void    ft_render_player(t_game *game);
static void    ft_render_pickup(t_game *game);
static void    ft_render_ghost(t_game *game);
static void    ft_render_exit(t_game *game);
static void ft_render_moves(t_game *game);

static void	my_mlx_pixel_put(t_draw *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_width + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
	return ;
}

void ft_create_sprites (t_game *game)
{
	ft_render_wall(game);
	ft_render_floor(game);
	ft_render_player(game);
	ft_render_pickup(game);
	ft_render_ghost(game);
	ft_render_moves(game);
}

static void ft_render_ghost(t_game *game)
{
	game->ghost->obj->img = mlx_xpm_file_to_image(game->mlx,
	                                              game->ghost->obj->path[0],
	                                              &game->ghost->obj->width,
												  &game->ghost->obj->height);
	if(!game->ghost->obj->img)
	{
		ft_printf("ERROR: Creating ghost\n");
		exit(0);
	}
}

static void ft_render_floor(t_game *game)
{
	game->map->floor->obj->img = mlx_xpm_file_to_image(game->mlx,
	                                              game->map->floor->obj->path[0],
	                                              &game->map->floor->obj->width,
												  &game->map->floor->obj->height);
	if(!game->map->floor->obj->img)
	{
		ft_printf("ERROR: Creating floor\n");
		exit(0);
	}
}

static void ft_render_player(t_game *game)
{
	game->player->obj->img = mlx_xpm_file_to_image(game->mlx,
	                                             game->player->obj->path[0],
	                                             &game->player->obj->width,
												 &game->player->obj->height);
	if(!game->player->obj->img)
	{
		ft_printf("ERROR: Creating brain\n");
		exit(0);
	}
}

static void ft_render_wall(t_game *game)
{
	int width;
	int height;

	void *img;
	char *s = "../images/tree.xpm";

	game->map->wall->obj->img = mlx_xpm_file_to_image(game->mlx,
	                                                   game->map->wall->obj->path[0],
	                                                   &game->map->wall->obj->width,
	                                                   &game->map->wall->obj->height);
	if(!game->map->wall->obj->img)
	{
		ft_printf("ERROR: Creating wall\n");
		exit(0);
	}
}

static void ft_render_exit(t_game *game)
{
	game->map->exit->img = mlx_xpm_file_to_image(game->mlx,
	                                             game->map->exit->path[0],
	                                             &game->map->exit->width,&game->map->exit->height);
	if(!game->map->exit->img)
	{
		ft_printf("ERROR: Creating exit\n");
		exit(0);
	}
}

static void ft_render_moves(t_game *game)
{
	int	x;
	int	y;

	game->draw->img = mlx_new_image(game->mlx, 56, 30);
	if (game->draw->img == NULL)
		ft_printf("MLX_ERROR: creat moves image");
	game->draw->addr = mlx_get_data_addr(game->draw->img,
	                                     &game->draw->bits_per_pixel, &game->draw->line_width,
	                                     &game->draw->endian);
	x = -1;
	while (++x < 56)
	{
		y = -1;
		while (++y < 30)
		{
			my_mlx_pixel_put(game->draw, x, y, 0xffffff);
			if (x < 4 || x > 51 || y < 4 || y > 25)
				my_mlx_pixel_put(game->draw, x, y, 0x000000);
		}
	}
}

static void    ft_render_pickup(t_game *game)
{
	game->collect->obj->img = mlx_xpm_file_to_image(game->mlx,
	                                             game->collect->obj->path[0],
	                                             &game->collect->obj->width,&game->collect->obj->height);
	if(!game->collect->obj->img)
	{
		ft_printf("ERROR: render_pickup\n");
		exit(0);
	}
}