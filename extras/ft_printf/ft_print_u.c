/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:15:06 by beergin           #+#    #+#             */
/*   Updated: 2024/10/26 23:52:05 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_utoa_len(unsigned int num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static char	*ft_utoa(unsigned int num)
{
	size_t	len;
	char	*result;

	len = ft_utoa_len(num);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (0);
	result[len] = '\0';
	while (len > 0)
	{
		result[--len] = (num % 10) + '0';
		num /= 10;
	}
	return (result);
}

int	ft_print_u(unsigned int num)
{
	char	*result;
	int		count;

	result = ft_utoa(num);
	if (!result)
		return (0);
	count = ft_print_str(result);
	free(result);
	return (count);
}
