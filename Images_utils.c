/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Images_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 01:06:14 by igenial           #+#    #+#             */
/*   Updated: 2023/08/29 01:25:45 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_animation(void *arg)
{
	char	*img_pt[13];
	int		w;
	int		h;
	int		i;
	t_data	*t_mlx;

	img_pt[13] = {"images/1.xpm", "images/2.xpm", "images/3.xpm",
		"images/4.xpm", "images/5.xpm", "images/6.xpm",
		"images/7.xpm", "images/8.xpm", "images/9.xpm",
		"images/10.xpm", "images/11.xpm", "images/12.xpm"};
	t_mlx = (t_data *)arg;
	i = 0;
	while (img_print[i] && i < 12)
	{
		t_mlx->img = mlx_xpm_file_to_image(t_mlx->mlx, img_pt[i], &w, &h);
		mlx_put_image_to_window(t_mlx->mlx, t_mlx->win, t_mlx->img, 172, 172);
		i++;
		usleep(200000);
	}
	return (0);
}
