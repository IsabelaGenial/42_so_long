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

#include "../mandatory/so_long.h"


//mlx_loop_hook (t_mlx.mlx, ft_animation, &t_mlx);

int	ft_animation(void *arg)
{
	const char	*img_pt[13] = {"images/1.xpm", "images/2.xpm", "images/3.xpm",
	                       "images/4.xpm", "images/5.xpm", "images/6.xpm",
	                       "images/7.xpm", "images/8.xpm", "images/9.xpm",
	                       "images/10.xpm", "images/11.xpm", "images/12.xpm"};
	int		i;
	t_data	*t_mlx;

	t_mlx = (t_data *)arg;
	i = 0;
	while (img_pt[i] && i < 12)
	{
		if (t_mlx->img->path != NULL)
			mlx_destroy_image(t_mlx->mlx, t_mlx->img->path);
		t_mlx->img->path = mlx_xpm_file_to_image(t_mlx->mlx, (char*)img_pt[i], &t_mlx->img->width, &t_mlx->img->height);
		mlx_put_image_to_window(t_mlx->mlx, t_mlx->win, t_mlx->img->path, t_mlx->img->x, t_mlx->img->y);
		i++;
	}
	return (0);
}
