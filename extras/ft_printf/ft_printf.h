/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:50:40 by beergin           #+#    #+#             */
/*   Updated: 2024/10/26 20:30:18 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *content, ...);
int	ft_print_c(char a);
int	ft_print_str(const char *str);
int	ft_print_int(int num);
int	ft_print_hex(void *ptr);
int	ft_print_u(unsigned int num);
int	ft_print_x(unsigned int x, int upper);
#endif