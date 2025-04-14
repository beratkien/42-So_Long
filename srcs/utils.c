/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:32:41 by beergin           #+#    #+#             */
/*   Updated: 2025/04/13 23:33:49 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(char **map, int player_x, int player_y)
{
	if (map[player_y][player_x] == '1' || map[player_y][player_x] == 'B')
	{
		return ;
	}
	map[player_y][player_x] = 'B';
	fill(map, player_x + 1, player_y);
	fill(map, player_x - 1, player_y);
	fill(map, player_x, player_y + 1);
	fill(map, player_x, player_y - 1);
}

void	get_map_codes(char **map, int pos, char *line, t_game *game)
{
	int	i;

	i = 0;
	if (line[ft_strlen(line)] == '\n')
		map[pos] = malloc(ft_strlen(line));
	else
		map[pos] = malloc(ft_strlen(line) + 1);
	if (!map[pos])
		simple_free_game(game, 0, "Error!\nCould not open space for map codes");
	while (line[i] && line[i] != '\n')
	{
		map[pos][i] = line[i];
		i++;
	}
	map[pos][i] = '\0';
}

void	set_line(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

int	adv_free_game(t_game *game, int status)
{
	adv_free_2(game);
	if (game->player_img)
		mlx_destroy_image(game->mlx, game->player_img);
	if (game->collect_img)
		mlx_destroy_image(game->mlx, game->collect_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->floor_img)
		mlx_destroy_image(game->mlx, game->floor_img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
	if (!status)
		exit(1);
	exit(0);
}

void	simple_free_game(t_game *game, int status, char *text)
{
	int	i;

	i = 0;
	ft_printf("%s", text);
	if (game->map)
	{
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
	if (game)
		free(game);
	if (!status)
		exit(1);
	exit(0);
}
