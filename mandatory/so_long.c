/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 00:54:40 by igenial           #+#    #+#             */
/*   Updated: 2023/08/29 01:03:36 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game world;

	if(argc != 2) {
		ft_printf("we need input map");
		return (0);
	}
	ft_save_map (argv[1], &world);
	ft_printf("good");
	ft_check_wall(&world);
	ft_printf("the map have wall");
	world.mlx = mlx_init ();
	world.win->win_ptr = mlx_new_window (world.mlx, (TILE_SIZE * world.map->x_axis),(TILE_SIZE * world.map->y_axis) , "so_long");
	ft_print_map(&world);
	mlx_key_hook (world.win->win_ptr, ft_keyboard, &world);
	mlx_hook (world.win->win_ptr, 17, 1L << 3, ft_close, &world);
	mlx_loop (world.mlx);
}