/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:50:33 by beergin           #+#    #+#             */
/*   Updated: 2024/10/26 21:24:42 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int num)
{
	char	*result;
	int		count;

	count = 0;
	result = ft_itoa(num);
	if (!result)
		return (0);
	count = ft_print_str(result);
	free(result);
	return (count);
}
