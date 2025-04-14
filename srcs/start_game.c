/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:19:50 by beergin           #+#    #+#             */
/*   Updated: 2025/04/13 23:05:42 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move2(t_game *game, int new_x, int new_y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->floor_img,
		game->player_x * 48, game->player_y * 48);
	if (game->collectibles && game->map[game->player_y][game->player_x] == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->exit_img,
			game->player_x * 48, game->player_y * 48);
	}
	game->player_x = new_x;
	game->player_y = new_y;
	mlx_put_image_to_window(game->mlx, game->win, game->player_img, new_x * 48,
		new_y * 48);
	game->moves++;
	ft_printf("Moves : %d\n", game->moves);
}

int	move_player(t_game *game, int tx, int ty)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + tx;
	new_y = game->player_y + ty;
	if (game->map[new_y][new_x] != '1')
	{
		move2(game, new_x, new_y);
		if (game->map[new_y][new_x] == 'E' && !game->collectibles)
			return (ft_printf("Congratulations! You won in %d moves!",
					game->moves), adv_free_game(game, 1), 0);
	}
	if (game->map[new_y][new_x] == 'C' && game->collectibles > 0)
	{
		game->map[new_y][new_x] = '0';
		game->collectibles--;
	}
	return (1);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
		return (ft_printf("You lost in %d moves! Sad :(\n", game->moves),
			adv_free_game(game, 1), 0);
	else if (keycode == 119)
		move_player(game, 0, -1);
	else if (keycode == 97)
		move_player(game, -1, 0);
	else if (keycode == 100)
		move_player(game, 1, 0);
	else if (keycode == 115)
		move_player(game, 0, 1);
	return (0);
}

void	render_game(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			render2(game, y, x);
			x++;
		}
		y++;
	}
}

int	init_game(t_game *game)
{
	int	h;
	int	w;

	h = 0;
	w = 0;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	init2(game, h, w);
	if (!game->player_img || !game->collect_img || !game->exit_img
		|| !game->wall_img || !game->floor_img)
	{
		ft_printf("Error!\nImage could not be loaded\n");
		adv_free_game(game, 0);
	}
	game->win = mlx_new_window(game->mlx, game->map_width * 48, game->map_height
			* 48, "So Long");
	if (!game->win)
		return (0);
	render_game(game);
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->win, 17, 1L << 17, adv_free_game, game);
	mlx_loop(game->mlx);
	return (1);
}
