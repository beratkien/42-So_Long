/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_co.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:50:44 by beergin           #+#    #+#             */
/*   Updated: 2024/10/27 00:53:18 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(char a)
{
	write(1, &a, 1);
	return (1);
}

int	ft_print_str(const char *str)
{
	int		i;
	int		count;
	char	*new;

	count = 0;
	if (!str)
	{
		new = "(null)";
		while (*new)
			count += ft_print_c(*new ++);
		return (count);
	}
	i = 0;
	while (str[i])
		count += ft_print_c(str[i++]);
	return (count);
}
