/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:04:31 by beergin           #+#    #+#             */
/*   Updated: 2024/10/26 21:17:21 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_lowercase(char a)
{
	if (a >= 'a' && a <= 'f')
		return (1);
	return (0);
}

static void	ft_add_hex(unsigned int x)
{
	char	*hex;
	int		tmp;

	hex = "0123456789abcdef";
	if (!ft_isdigit(hex[x % 16]) && ft_is_lowercase(hex[x % 16]))
	{
		tmp = hex[x % 16] - 32;
		write(1, &tmp, 1);
	}
	else
		write(1, &hex[x % 16], 1);
}

int	ft_print_x(unsigned int x, int upper)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789abcdef";
	if (x >= 16)
		count += ft_print_x(x / 16, upper);
	if (upper)
		ft_add_hex(x);
	else
		write(1, &hex[x % 16], 1);
	count++;
	return (count);
}
