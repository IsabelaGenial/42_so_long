
#include "so_long.h"

void ft_input_validation(int count_arg, char * arg, t_game *game)
{
	ft_handle_map_input(count_arg, arg,game);
	ft_save_map(arg, game);
	ft_check_map(game);
	ft_check_object(game);
	ft_check_wall(game);
	ft_image_bank_obj(game);
}

void ft_open_window(t_game *game)
{
	game->win->width = (TILE_SIZE * (game)->map->axis->x);
	game->win->height = (TILE_SIZE * (game)->map->axis->y);
	game->win->win_ptr = mlx_new_window(game->mlx,game->win->width,
	                                    game->win->height,"Magic World of Morrigan");
	if (game->win->win_ptr == NULL)
	{
		ft_printf("ERROR: mlx_error while opening window");
		exit(1);
	}
	ft_create_sprites(game);
}


void ft_event_win(t_game *game)
{
	mlx_hook(game->win->win_ptr, 17, 1L << 3,&ft_shutdown_game, game);
	mlx_hook(game->win->win_ptr, 0, 0,&ft_keyboard, game);
	mlx_loop_hook(game->mlx, &ft_render_window, game);
}

int ft_keyboard(int key, t_game *game)
{
	if (key ==  65307)
		ft_shutdown_game(game);
	if (key == 65363 )
		ft_walk_right(game);
//	if (key == up || key == W)
//		ft_walk_up(game);
//	if (key ==  left || key == A)
//		ft_walk_left(game);
//	if (key == down || key == S)
//		ft_walk_left(game);
	ft_printf("tecla %i\n", key);
	return (0);
}

