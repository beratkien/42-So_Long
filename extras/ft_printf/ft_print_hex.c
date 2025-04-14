/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:09:16 by beergin           #+#    #+#             */
/*   Updated: 2024/10/27 02:45:20 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_to_hex(unsigned long ptr)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (ptr >= 16)
		ft_to_hex(ptr / 16);
	write(1, &hex[ptr % 16], 1);
}

int	ft_print_hex(void *ptr)
{
	int				len;
	unsigned long	to_hex;

	to_hex = (unsigned long)ptr;
	len = 0;
	len += write(1, "0x", 2);
	if (to_hex == 0)
		len += write(1, "0", 1);
	else
	{
		ft_to_hex(to_hex);
		while (to_hex)
		{
			to_hex /= 16;
			len++;
		}
	}
	return (len);
}
