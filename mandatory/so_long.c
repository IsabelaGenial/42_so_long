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

	if(argc || *argv[1])
		;
	world.mlx = mlx_init ();
	world.win->win_ptr = mlx_new_window (world.mlx, WIN_WIDTH, WIN_HEIGHT, "so_long");
	mlx_key_hook (world.win->win_ptr, &ft_keyboard, &world);
	mlx_hook (world.win->win_ptr, 17, 1L << 3, ft_close, &world);
	mlx_loop (world.mlx);
}
