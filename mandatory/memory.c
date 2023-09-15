#include "so_long.h"

void ft_memory(t_game *game)
{
	game->win = ft_calloc(1, sizeof(t_win));
	game->map = ft_calloc(1, sizeof(t_map));
	game->map->exit = ft_calloc(1, sizeof(t_img));
	game->map->axis = ft_calloc(1, sizeof(t_axis));
	game->map->floor = ft_calloc(1,sizeof (t_obj));
	game->map->floor->obj = ft_calloc(1,sizeof (t_img));
	game->map->wall = ft_calloc(1,sizeof (t_obj));
	game->map->wall->obj = ft_calloc(1,sizeof (t_img));
	game->player = ft_calloc(1, sizeof(t_obj));
	game->player->obj = ft_calloc(1, sizeof(t_img));
	game->player->axis = ft_calloc(1, sizeof(t_axis));
	game->collect = ft_calloc(1, sizeof(t_obj));
	game->collect->obj = ft_calloc(1, sizeof(t_img));
	game->ghost = ft_calloc(1, sizeof(t_obj ));
	game->ghost->obj = ft_calloc(1, sizeof(t_img ));
	if (!game->map || !game->win|| !game->player || !game->collect ||
	    !game->player->axis || !game->map->axis || !game->player->obj ||
		!game->map->map_grid || !game->ghost || !game->draw ||
		!game->map->floor || !game->map->wall)
		ft_printf("ERROR: Memory allocation failed");
}
void    ft_struct_supply(t_game *game)
{
	game->map->pickup_counter = 0;
	game->map->player_count = 0;
	game->map->exit_counter = 0;
	game->map->rows = 0;
	game->player->direction = 0;
	game->map->wall->obj->width = 0;
	game->map->wall->obj->height = 0;
	game->player->moves_count = 0;
	game->map->map_grid = NULL;
}


