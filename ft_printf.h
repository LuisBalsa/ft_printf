/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:25:30 by luide-so          #+#    #+#             */
/*   Updated: 2023/05/05 19:46:30 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"

int	ft_printf(const char *param, ...);
int	print_chr(char c, int *flags);
int	print_str(char *s, int *flags);
int	print_nbr(long long n, int *flags);
int	print_hex(unsigned int nbr, int *flags, const char c);
int	print_unsigned(unsigned int nbr, int *flags);
int	print_pointer(unsigned long long ptr, int *flags);

#endif