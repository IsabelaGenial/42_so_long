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

int	main(void)
{
	t_data	t_mlx;
	void	*mlx;
	void	*win;
	int		fd;

	mlx = mlx_init ();
	win = mlx_new_window (mlx, WIN_WIDTH, WIN_HEIGHT, "so_long");
	t_mlx.mlx = mlx;
	t_mlx.win = win;
	mlx_key_hook (t_mlx.win, &ft_keyboard, &t_mlx);
	mlx_hook (t_mlx.win, 17, 1L << 3, ft_close, &t_mlx);
	fd = open ("map1.txt", O_RDONLY);
	if (fd != -1)
	{
		ft_print_map (fd, &t_mlx);
		close (fd);
	}
	fd = open("map1.txt", O_RDONLY);
	if (fd != -1)
	{
		ft_print_objects (fd, &t_mlx);
		close (fd);
	}
	mlx_loop_hook (t_mlx.mlx, ft_animation, &t_mlx);
	mlx_loop (t_mlx.mlx);
}
