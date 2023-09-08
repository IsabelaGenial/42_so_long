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

int	main(int argv, char **argc)
{
	if(argv != 2)
		return (write(1, "Sorry, we need a map description {./so_long [map]}",51));
	t_data	t_mlx;
	void	*mlx;
	void	*win;
	int		fd;

	mlx = mlx_init ();
	win = mlx_new_window (mlx, WIN_WIDTH, WIN_HEIGHT, "so_long");
	t_mlx.mlx = mlx;
	t_mlx.win = win;
	t_mlx.img = ft_calloc(sizeof(t_img), 1);
	t_mlx.img->x = 132;
	t_mlx.img->y = 132;
	mlx_key_hook (t_mlx.win, &ft_keyboard, &t_mlx);
	mlx_hook (t_mlx.win, 17, 1L << 3, ft_close, &t_mlx);
	fd = open (*argc, O_RDONLY);
	if (fd != -1)
	{
		mlx_clear_window(t_mlx.mlx, t_mlx.win);
		ft_print_map (fd, &t_mlx);
		ft_print_objects (fd, &t_mlx);
		close (fd);
	}
	mlx_loop (t_mlx.mlx);
}
