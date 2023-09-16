/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 04:53:24 by igenial           #+#    #+#             */
/*   Updated: 2023/09/16 04:56:07 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_handle_map_input(int count_arg, char *map, t_game *game)
{
	if (count_arg != 2)
	{
		if (count_arg < 2)
		{
			ft_printf("ERROR: We need input map {./program_name map}\n");
			return (1);
		}
		else
		{
			ft_printf("ERROR: We need only the "
				"program name and a map {./program_name map}\n");
			return (1);
		}
	}
	else if (!ft_strnstr(map, ".ber", ft_strlen(map)))
	{
		ft_printf("ERROR: Okay, now the map needs to be in \".ber\" format\n");
		return (1);
	}
	ft_memory(game);
	ft_struct_supply(game);
	return (0);
}

int     ft_check_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map->map_grid[y])
	{
		x = 0;
		while (game->map->map_grid[y][x] && game->map->map_grid[y][x] != '\n')
		{
			if (game->map->map_grid[y][x] == 'C')
					game->map->pickup_counter++;
			if (game->map->map_grid[y][x] == 'E')
					game->map->exit_counter++;
			if (game->map->map_grid[y][x] == 'P')
					game->map->player_count++;
			if (!ft_strchr(CHAR_MAP, game->map->map_grid[y][x]))
			{
				ft_printf("ERROR: An unallowed character was found.\n");
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_check_object(t_game *game)
{
	if (game->map->player_count != 1)
	{
		ft_printf("ERROR: The number of players is incorrect\n");
		return(1);
	}
	if (game->map->exit_counter != 1)
	{
		ft_printf("ERROR: The number of exit is incorrect\n");
		return(1);
	}
	if (game->map->pickup_counter < 1)
	{
		ft_printf("ERROR: The number of collectible is incorrect\n");
		return(1);
	}
	return (0);
}
