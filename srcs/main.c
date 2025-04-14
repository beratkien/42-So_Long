/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:27:09 by beergin           #+#    #+#             */
/*   Updated: 2025/04/13 23:32:30 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	c_map2(t_game *game)
{
	char	**map;
	int		i;

	map = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	if (!map)
		simple_free_game(game, 0, "Error!\nCould not create malloc");
	i = 0;
	while (game->map[i])
	{
		map[i] = ft_strdup(game->map[i]);
		if (!map[i])
		{
			tmp_map_free(map);
			simple_free_game(game, 0, "Error!\nDoesn't copied");
		}
		i++;
	}
	map[i] = NULL;
	c_map_cont(game, map);
	tmp_map_free(map);
}

static int	v_map2(char c, int *p, int *e, int *cc)
{
	if (c == 'P')
		(*p)++;
	else if (c == 'E')
		(*e)++;
	else if (c == 'C')
		(*cc)++;
	else if (c != '0' && c != '1' && c != '\n')
		return (0);
	return (1);
}

int	validate_map(char **map, int i, int j)
{
	int	player_count;
	int	c_count;
	int	exit_count;

	player_count = 0;
	c_count = 0;
	exit_count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!v_map2(map[i][j], &player_count, &exit_count, &c_count))
				return (0);
			j++;
		}
		i++;
	}
	if (player_count != 1 || exit_count != 1 || c_count < 1)
		return (0);
	return (1);
}

static void	check_map(char *f_name, t_game *game)
{
	int	fd;

	fd = open(f_name, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error!\nCould not open map file");
		close(fd);
		free(game);
		exit(1);
	}
	check_extension(game, f_name);
	first_process(game, fd, f_name);
	check_map_length(game);
	find_player(game);
	check_map_wall(game);
	c_map2(game);
	close(fd);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (ft_printf("Error!\nInvalid arguments.",
				"Usage : ./so_long <map.ber>"));
	game = malloc(sizeof(t_game));
	if (!game)
	{
		return (1);
	}
	game->win = NULL;
	game->map = NULL;
	game->mlx = NULL;
	check_map(argv[1], game);
	if (!init_game(game))
		return (adv_free_game(game, 0), 1);
	return (0);
}
