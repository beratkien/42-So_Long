/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:58:57 by beergin           #+#    #+#             */
/*   Updated: 2025/04/13 23:13:06 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../extras/ft_printf/ft_printf.h"
# include "../extras/get_next_line/get_next_line.h"
# include "../extras/minilibx-linux/mlx.h"
# include "fcntl.h"
# include "unistd.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		moves;
	void	*wall_img;
	void	*player_img;
	void	*collect_img;
	void	*exit_img;
	void	*floor_img;

}			t_game;

void		get_map_codes(char **map, int pos, char *line, t_game *game);
void		set_line(char *line);
int			init_game(t_game *game);
void		render_game(t_game *game);
int			adv_free_game(t_game *game, int status);
void		adv_free_2(t_game *game);
void		simple_free_game(t_game *game, int status, char *text);
void		fill(char **map, int player_x, int player_y);
void		find_player(t_game *game);
void		tmp_map_free(char **map);
void		check_map_length(t_game *game);
void		check_map_wall(t_game *game);
void		get_height(t_game *game, char *f_name);
void		c_map_cont(t_game *game, char **map);
void		first_process(t_game *game, int fd, char *f_name);
int			validate_map(char **map, int i, int j);
void		render2(t_game *game, int y, int x);
void		init2(t_game *game, int h, int w);
void		check_extension(t_game *game, char *str);
#endif