/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 23:07:31 by beergin           #+#    #+#             */
/*   Updated: 2025/04/13 23:27:29 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_extension(t_game *game, char *str)
{
	int		len;
	char	*tmp;

	tmp = str;
	len = ft_strlen(str) - 4;
	tmp += len;
	if (ft_strncmp(tmp, ".ber", 4))
		simple_free_game(game, 0, "Error!\nThe map file must end with '.ber'");
	else if (str[ft_strlen(str) - 4] == '.' && str[ft_strlen(str) - 5] == '/')
		simple_free_game(game, 0,
			"Error!\nThe name of the map file should not be just '.ber'");
}
