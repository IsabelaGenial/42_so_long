/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 00:54:40 by igenial           #+#    #+#             */
/*   Updated: 2023/09/16 05:56:07 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*world;

	world = malloc(sizeof(t_game) * 1);
	ft_input_validation(argc, argv[1], world);
	world->mlx = mlx_init();
	ft_open_window(world);
	ft_event_win(world);
	mlx_loop(world->mlx);
}
