/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:57:27 by beergin           #+#    #+#             */
/*   Updated: 2025/04/11 05:05:18 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	c_map_cont(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	fill(map, game->player_x, game->player_y);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P' || map[i][j] == 'E' || map[i][j] == 'C')
			{
				tmp_map_free(map);
				simple_free_game(game, 0,
					"Error!\nUnable to access exit door or item");
			}
			j++;
		}
		i++;
	}
}

void	first_process(t_game *game, int fd, char *f_name)
{
	int		i;
	char	*line;

	i = 0;
	if (fd < 0)
		simple_free_game(game, 0, "Error!\nFailed to open map file");
	get_height(game, f_name);
	game->map = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
		simple_free_game(game, 0, "Error!\nCould not open space for map");
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line)
			set_line(line);
		get_map_codes(game->map, i, line, game);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	game->map[i] = NULL;
	if (!validate_map(game->map, 0, 0))
	{
		simple_free_game(game, 0, "Error!\nMap content is not correct");
	}
}

void	render2(t_game *game, int y, int x)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall_img, x * 48, y
			* 48);
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->floor_img, x * 48, y
			* 48);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->player_img, x * 48,
			y * 48);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->collect_img, x * 48,
			y * 48);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit_img, x * 48, y
			* 48);
}

void	init2(t_game *game, int h, int w)
{
	game->player_img = mlx_xpm_file_to_image(game->mlx, "./assets/player.xpm",
			&w, &h);
	game->collect_img = mlx_xpm_file_to_image(game->mlx, "./assets/collect.xpm",
			&w, &h);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "./assets/door.xpm", &w,
			&h);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "./assets/wall.xpm", &w,
			&h);
	game->floor_img = mlx_xpm_file_to_image(game->mlx, "./assets/floor.xpm", &w,
			&h);
}

void	adv_free_2(t_game *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
}
