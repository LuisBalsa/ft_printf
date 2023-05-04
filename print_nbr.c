/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:31:10 by luide-so          #+#    #+#             */
/*   Updated: 2023/05/05 00:23:39 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_nbr_right(int nbr, int *flags, int len)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (nbr < 0)
		flags[1] = 1;
	while (i < flags[7] - flags[1] - flags[6] - len)
		i += write(1, " ", 1);
	if (flags[1] && nbr > 0)
		write(1, "+", 1);
	while (j < flags[6])
		j += write(1, "0", 1);
	ft_putnbr_fd(nbr, 1);
	return (len + i + j + flags[1]);
}

static int	print_nbr_left(int nbr, int *flags, int len)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (flags[1] && nbr > 0)
		write(1, "+", 1);
	else if (flags[0] && nbr > 0)
		flags[1] = write(1, " ", 1);
	if (nbr < 0)
		flags[1] = 1;
	while (j < flags[6])
		j += write(1, "0", 1);
	ft_putnbr_fd(nbr, 1);
	while (i < flags[7] - flags[1] - flags[6] - len)
		i += write(1, " ", 1);
	return (len + i + j + flags[1]);
}

static int	ft_intlen(int n)
{
	int	len;

	len = !n;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	print_nbr(int nbr, int *flags)
{
	int		len;

	len = ft_intlen(nbr);
	if (flags[5] && !flags[6] && !nbr)
		flags[6] = len;
	else
	{
		flags[6] = flags[6] - len;
		if (flags[6] < 0)
			flags[6] = 0;
	}
	if (flags[3])
		return (print_nbr_left(nbr, flags, len));
	return (print_nbr_right(nbr, flags, len));
}

// Falta ver caso .0 (não devia imprimir nenhum digito)