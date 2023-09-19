/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 04:48:04 by igenial           #+#    #+#             */
/*   Updated: 2023/09/18 18:25:09 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libfstonk/libft.h"

# define TILE_SIZE 66
# define CHAR_MAP	"EPC10G"

typedef struct S_AXIS
{
	int	x;
	int	y;
}		t_axis;

//typedef struct s_draw{
////	void	*img;
////	char	*addr;
////	int		bits_per_pixel;
////	int		line_width;
////	int		endian;
////}			t_draw;

typedef struct S_IMG
{
	char	**path;
	void	**img;
	int		width;
	int		height;
}			t_img;

typedef struct S_obj
{
	t_img	*obj;
	t_axis	*axis;
	int		moves_count;
	int		pickup_count;
	int		direction;
}			t_obj;

typedef struct S_MAP
{
	size_t	cols;
	size_t	rows;
	int		pickup_counter;
	int		player_count;
	int		exit_counter;
	int		ghost_counter;
	char	**map_grid;
	t_axis	*axis;
	t_img	*exit;
	t_obj	*floor;
	t_obj	*wall;
	t_list	*rows_list;
}			t_map;

typedef struct S_WIN
{
	void	*win_ptr;
	int		width;
	int		height;
}			t_win;

typedef struct S_GAME
{
	void	*mlx;
	t_win	*win;
	t_obj	*player;
	t_obj	*ghost;
	t_obj	*collect;
	t_map	*map;
}			t_game;

//images.//
void	ft_render_wall(t_game *game);
void	ft_render_floor(t_game *game);
void	ft_render_player(t_game *game);
void	ft_render_pickup(t_game *game);
void	ft_create_player(t_game *game);
void	ft_render_ghost(t_game *game);
void	ft_render_exit(t_game *game);
int		ft_render_window(t_game *game);
void	ft_render_object(int x, int y, t_game *game);
void	ft_image_bank_obj(t_game *see);
void	ft_create_sprites(t_game *game);
void	ft_print_map(t_game *game);
void	ft_render_img(t_game *game);
//map.//
int		ft_handle_map_input(int count_arg, char *map, t_game *game);
int		ft_route_validation(t_game *game);
int		ft_line_count(int fd);
int		ft_save_map(char *map, t_game *game);
int		ft_check_map(t_game *game);
int		ft_check_object(t_game *game);
int		ft_check_wall(t_game *game);
int		ft_input_validation(int count_arg, char *arg, t_game *game);
t_axis	ft_position(char element, t_game *game);
//manager.//
void	ft_open_window(t_game *game);
void	ft_event_win(t_game *game);
int		ft_keyboard(int key, t_game *game);
int		ft_close(t_game *game);
void	ft_clear_grid(char **game);
void	ft_memory(t_game *game);
void	ft_walk_left(t_game *game);
void	ft_walk_right(t_game *game);
void	ft_walk_up(t_game *game);
void	ft_walk_down(t_game *game);
void	ft_walker_down(t_game *game);
void	ft_walker_up(t_game *game);
void	ft_walker_left(t_game *game);
void	ft_walker_right(t_game *game);
void	ft_struct_supply(t_game *game);
int		ft_shutdown_game(t_game *game);
void	free_alloc(t_game *game);
void	ft_free_img(t_game *game);
void	ft_free_win(t_game *game);
int		ft_flood_free(t_map *fake_map);
#endif
