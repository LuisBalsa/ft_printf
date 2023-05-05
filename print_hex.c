/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:38:43 by luide-so          #+#    #+#             */
/*   Updated: 2023/05/05 16:48:36 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_hex(unsigned int num, const char c)
{
	if (num >= 16)
	{
		ft_print_hex(num / 16, c);
		ft_print_hex(num % 16, c);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd(num + '0', 1);
		else
				ft_putchar_fd(num - 33 + c, 1);
	}
}

static int	hex_len(unsigned int num)
{
	int	i;

	i = 0;
	while (num >= 16)
	{
		num /= 16;
		i++;
	}
	i++;
	return (i);
}



int	print_hex(unsigned int nbr, int *flags, const char c)
{
	int	i;
	int	len;

	len = hex_len(nbr);
	i = 0;
	if (flags[2])
	{
		flags[2] += write(1, "0", 1);
		write(1, &c, 1);
	}
	if (flags[4])
		while (i < flags[7] - flags[2] - len)
			i += write(1, "0", 1);
	else if (flags[5])
		while (i < flags[6] - len)
			i += write(1, "0", 1);
	ft_print_hex(nbr, c);
	return (len + i + flags[2]);
}
