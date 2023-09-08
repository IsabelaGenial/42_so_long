/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:17:21 by igenial           #+#    #+#             */
/*   Updated: 2023/09/06 21:17:26 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_print_map (int fd, char *map, t_game *game)
{
    int y;
    int x;


    while (y < (WIN_HEIGHT/TILE_SIZE))
    {
        x = 0;
        line = get_next_line(fd);
        while (x < (WIN_WIDTH/TILE_SIZE)) {
            if(line != NULL)
            {
                if (line[x] == '1') {
                    t_mlx->img->path = mlx_xpm_file_to_image(t_mlx->mlx, (char*)relative_path, &t_mlx->img->width, &t_mlx->img->height); //talvez &.
                    mlx_put_image_to_window(t_mlx->mlx, t_mlx->win, t_mlx->img->path, (x * TILE_SIZE), (y * TILE_SIZE));
                }
            }x++;
        }
        free(line);
        y++;
    }

}
