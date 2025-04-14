/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 07:59:08 by beergin           #+#    #+#             */
/*   Updated: 2025/04/11 05:05:47 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_height(t_game *game, char *f_name)
{
	int		i;
	char	*line;
	int		fd;

	fd = open(f_name, O_RDWR);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	game->map_height = i;
	free(line);
	close(fd);
}

void	find_player(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	game->map_width = ft_strlen(game->map[0]);
	game->collectibles = 0;
	game->moves = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
			else if (game->map[y][x] == 'C')
				game->collectibles++;
			x++;
		}
		y++;
	}
}

void	tmp_map_free(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	check_map_length(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_height - 1)
	{
		if (ft_strlen(game->map[i]) != ft_strlen(game->map[i + 1]))
			simple_free_game(game, 0, "Error!\nThe map must be rectangular");
		i++;
	}
}

void	check_map_wall(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (i == 0 || i == game->map_height - 1 || j == 0
				|| j == game->map_width - 1)
			{
				if (game->map[i][j] != '1')
					simple_free_game(game, 0,
						"Error!\nBorders should just be walls");
			}
			j++;
		}
		i++;
	}
}
