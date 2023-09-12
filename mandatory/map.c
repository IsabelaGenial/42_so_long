
#include "so_long.h"


void ft_save_map(char *map, t_game *game)
{
	int fd;
	int count;
	int y;

	y = 0;
	fd = open(map, O_RDONLY);
	game->map->y_axis = ft_fd_len(fd);
	if (!fd) {
		ft_printf("error in open file map");
		return;
	}
	game->map->map_path = ft_calloc ((game->map->y_axis + 1), sizeof (char *));
	close(fd);
	if(!game->map->map_path)
	{
		ft_printf("error in malloc map path");
		return;
	}
	open (map, O_RDONLY);
	game->map->map_path[y] = get_next_line(fd);
	while(game->map->map_path[y])
	{
		y++;
		game->map->map_path[y] = get_next_line(fd);
	}
	close(fd);
}

int ft_check_wall (t_game **game)
{
		int y_axis;
		int x_axis;

		y_axis = 0;
	(*game)->map->x_axis = (int)ft_strlen((*game)->map->map_path[0]);
		while ((*game)->map->map_path[y_axis])
		{
			x_axis = 0;
			while ((*game)->map->map_path[y_axis][x_axis])
			{
				if(y_axis == 0 || y_axis == (*game)->map->y_axis ||
				   x_axis == 0 || x_axis == (*game)->map->x_axis)
				{
					if ((*game)->map->map_path[y_axis][x_axis] == 1)
						x_axis++;
					else
						return(ft_printf ("ERROR in WALL"));
				}
				x_axis++;
			}
			y_axis++;
		}
		return(1);
}

int ft_fd_len(int fd)
{
	int n;
	char *line;

	line = get_next_line(fd);
	n = 0;
	while (line != NULL)
	{
		n++;
		free(line);
		line = get_next_line(fd);

	}
	free(line);
	return (n);
}

void ft_memory(t_game **game)
{
	*game = ft_calloc(1, sizeof (t_game));
	(*game)->map = ft_calloc(1, sizeof(t_map));
	(*game)->player = ft_calloc(1, sizeof(t_player));
	(*game)->img = ft_calloc(1, sizeof(t_img));
	(*game)->win = ft_calloc(1, sizeof(t_win));
	if(!*game || !(*game)->map || !(*game)->img || !(*game)->player || !(*game)->win)
		return;
}