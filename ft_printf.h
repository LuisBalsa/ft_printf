/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:25:30 by luide-so          #+#    #+#             */
/*   Updated: 2023/05/03 20:36:21 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"

int	ft_printf(const char *param, ...);
int	print_chr(va_list args, int *flags);
int	print_str(va_list args, int *flags);
int	print_nbr(va_list args, int *flags);
int	print_hex(va_list args, int *flags);
int	print_unsigned(va_list args, int *flags);
int	print_pointer(va_list args, int *flags);

#endif