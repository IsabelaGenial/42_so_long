#include "so_long.h"

void ft_memory(t_game **game)
{
	(*game) = ft_calloc(1, sizeof (t_game));
	(*game)->map = ft_calloc(1, sizeof(t_map));
	(*game)->player = ft_calloc(1, sizeof(t_player));
	(*game)->img = ft_calloc(1, sizeof(t_img));
	(*game)->win = ft_calloc(1, sizeof(t_win));
	if(!(*game) || !(*game)->map || !(*game)->img || !(*game)->player || !(*game)->win)
		return;
}
void    ft_struct_supply(t_game **game)
{
	(*game)->map->pickup_counter = 0;
	(*game)->map->player_count = 0;
	(*game)->map->exit_counter = 0;
	(*game)->player->moves_count = 0;

}