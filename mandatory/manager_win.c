/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 04:56:22 by igenial           #+#    #+#             */
/*   Updated: 2023/09/18 16:56:18 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_input_validation(int count_arg, char *arg, t_game *game)
{
	ft_handle_map_input(count_arg, arg, game);
	if (ft_save_map(arg, game))
	{
		ft_printf("Error: Save map");
		return (1);
	}
	if (ft_check_map(game) || ft_check_object(game) || ft_check_wall(game))
	{
		ft_printf("Error: check map");
		return (1);
	}
	ft_image_bank_obj(game);
	if (ft_route_validation(game))
	{
		ft_printf("ERROR: ROUTE");
		return (1);
	}
	return (0);
}

void	ft_open_window(t_game *game)
{
	game->win->width = (TILE_SIZE * (game)->map->axis->x);
	game->win->height = (TILE_SIZE * (game)->map->axis->y);
	game->win->win_ptr = mlx_new_window(game->mlx, game->win->width,
			game->win->height, "Magic World of Morrigan");
	if (game->win->win_ptr == NULL)
	{
		ft_printf("ERROR: mlx_error while opening window");
		exit(1);
	}
	ft_create_sprites(game);
}

void	ft_event_win(t_game *game)
{
	mlx_hook(game->win->win_ptr, 17, 1L << 3, ft_close, game);
	mlx_hook(game->win->win_ptr, 02, (1L << 0), &ft_keyboard, game);
	mlx_loop_hook(game->mlx, &ft_render_window, game);
}

int	ft_keyboard(int key, t_game *game)
{
	if (key == 65307)
		ft_close(game);
	if (key == 65363 || key == 100)
		ft_walk_right(game);
	if (key == 65362 || key == 119)
		ft_walk_up(game);
	if (key == 65361 || key == 97)
		ft_walk_left(game);
	if (key == 65364 || key == 115)
		ft_walk_down(game);
	ft_printf("tecla %i\n", game->player->moves_count);
	return (0);
}
