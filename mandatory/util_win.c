#include "so_long.h"

int ft_close(t_game *game)
{
	//mlx_clear_window(game->mlx, game->win->win_ptr);
	mlx_destroy_window(game->mlx,game->win->win_ptr);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
	exit(0);
}

int ft_keyboard(int key, t_game *game)
{
	if (key ==  65307)
		ft_close(game);
	if (key == 65363)
		game->player->x += 5;
	return (0);
}

void ft_open_window(t_game *game)
{
	game->win->width = (TILE_SIZE * game->map->x_axis);
	game->win->height = (TILE_SIZE * game->map->y_axis);
	game->win->win_ptr = mlx_new_window(game->mlx,
	                                    game->win->width,
	                                    game->win->height,
	                                    "Magic World of Morrigan");
	if (game->win->win_ptr == NULL)
		return;
}