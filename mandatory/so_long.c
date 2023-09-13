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
	t_game *world;


	ft_handle_map_input(argc, argv[1],&world);
	world->mlx = mlx_init();
	ft_open_window(&world);
	mlx_key_hook(world->win->win_ptr, ft_keyboard, &world);
	mlx_hook(world->win->win_ptr, 17, 1L << 3, ft_shutdown_game, &world);
	mlx_loop(world->mlx);

}