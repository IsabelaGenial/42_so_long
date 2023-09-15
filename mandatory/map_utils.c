#include "so_long.h"

void ft_save_map(char *map, t_game *game)
{
	int fd;
	int y;

	y = 0;
	fd = open(map, O_RDONLY);
	game->map->axis->y = (ft_line_count(fd));
	game->map->map_grid = ft_calloc ((game->map->axis->y + 1), sizeof (char *));
	close(fd);
	if(!game->map->map_grid)
	{
		ft_printf("error in malloc map path\n");
		exit(1);
	}
	open (map, O_RDONLY);
	if (!fd) {
		ft_printf("error in open file map\n");
		exit(1);
	}
	game->map->map_grid[y] = get_next_line(fd);
	while(game->map->map_grid[y])
	{
		y++;
		game->map->map_grid[y] = get_next_line(fd);
	}
	close(fd);
}

int ft_check_wall(t_game *game)
{
	int y_axis;
	int x_axis;

	y_axis = 0;
	game->map->axis->x = ((int)ft_strlen(game->map->map_grid[0]) - 1);
	while (game->map->map_grid[y_axis])
	{
		x_axis = 0;
		while(game->map->map_grid[y_axis][x_axis] != '\n' && \
				game->map->map_grid[y_axis][x_axis] != '\0')
		{
			if (y_axis == 0 || y_axis == game->map->axis->y ||
			    x_axis == 0 || x_axis == game->map->axis->x)
			{
				if (game->map->map_grid[y_axis][x_axis] != '1')
				{
					ft_printf("ERROR: in WALL\n");
					exit(1);
				}
			}
			x_axis++;
		}
		y_axis++;
	}
	return (0);
}

int ft_line_count(int fd)
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
