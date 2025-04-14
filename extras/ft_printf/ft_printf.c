/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:50:37 by beergin           #+#    #+#             */
/*   Updated: 2024/10/27 02:44:49 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_type(char type, va_list arg_list)
{
	int	count;

	count = 0;
	if (type == '%')
		count += ft_print_c('%');
	else if (type == 'c')
		count += ft_print_c(va_arg(arg_list, int));
	else if (type == 's')
		count += ft_print_str(va_arg(arg_list, const char *));
	else if (type == 'd' || type == 'i')
		count += ft_print_int(va_arg(arg_list, int));
	else if (type == 'p')
		count += ft_print_hex(va_arg(arg_list, void *));
	else if (type == 'u')
		count += ft_print_u(va_arg(arg_list, unsigned int));
	else if (type == 'x')
		count += ft_print_x(va_arg(arg_list, unsigned int), 0);
	else if (type == 'X')
		count += ft_print_x(va_arg(arg_list, unsigned int), 1);
	return (count);
}

static int	ft_isspecifiers(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

static int	ft_printf_count(const char *content, va_list arg_list)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (content[i])
	{
		if (content[i] == '%' && content[i + 1] != '\0')
		{
			if (ft_isspecifiers(content[i + 1]))
				count += ft_type(content[(i++) + 1], arg_list);
			else if (content[i])
				count += ft_print_c(content[i]);
		}
		else
			count += ft_print_c(content[i]);
		i++;
	}
	return (count);
}

int	ft_printf(const char *content, ...)
{
	va_list	arg_list;
	int		count;

	if (!content || *content == '\0')
		return (0);
	va_start(arg_list, content);
	count = ft_printf_count(content, arg_list);
	va_end(arg_list);
	return (count);
}
