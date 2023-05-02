/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:25:30 by luide-so          #+#    #+#             */
/*   Updated: 2023/05/02 16:10:13 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_flags
{
	int	space;
	int	plus;
	int	hashtag;
	int	minus;
	int	zero;
	int	dot;
	int	width;
	int	precision;
	int	numbers;
	int	only_number;
}		t_flags;

int	ft_printf(const char *param, ...);
int	print_perc(va_list, t_flags);
int	print_chr(va_list, t_flags);
int	print_str(va_list, t_flags);
int	print_nbr(va_list, t_flags);
int	print_hex(va_list, t_flags);
int	print_unsigned(va_list, t_flags);
int	print_pointer(va_list, t_flags);

#endif