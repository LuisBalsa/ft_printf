/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:31:10 by luide-so          #+#    #+#             */
/*   Updated: 2023/05/05 19:46:35 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(long long nb)
{
	if (nb < 0)
	{
		ft_putchar_fd('-', 1);
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar_fd(nb % 10 + '0', 1);
}

static int	print_nbr_right(long nbr, int *flags, int len, int neg)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < flags[7])
		i += write(1, " ", 1);
	if (neg)
		flags[1] = write(1, "-", 1);
	if (flags[1] && !neg)
		write(1, "+", 1);
	while (j < flags[6])
		j += write(1, "0", 1);
	if (flags[5] < 2)
		ft_putnbr(nbr);
	return (len + i + j + flags[1]);
}

static int	print_nbr_left(long nbr, int *flags, int len, int neg)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (neg)
		flags[1] = write(1, "-", 1);
	if (flags[1] && !neg)
		write(1, "+", 1);
	else if (flags[0] && !neg)
		flags[1] = write(1, " ", 1);
	while (j < flags[6])
		j += write(1, "0", 1);
	if (flags[5] < 2)
		ft_putnbr(nbr);
	while (i < flags[7])
		i += write(1, " ", 1);
	return (len + i + j + flags[1]);
}

static int	ft_intlen(long long n)
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

int	print_nbr(long long n, int *flags)
{
	int			len;
	bool		neg;
	long long	nbr;

	neg = n < 0;
	nbr = n;
	if (n < 0)
		nbr = -nbr;
	len = ft_intlen(n);
	if (flags[5] && !flags[6] && !nbr)
		flags[5] += len--;
	if (flags[4] && !flags[5])
	{
		flags[6] = flags[7];
		flags[7] = 0;
	}
	if (flags[6] > len)
		flags[7] -= flags[6] + flags[1] + flags[0] + neg;
	else
		flags[7] -= len + flags[1] + flags[0] + neg;
	if (flags[5])
		flags[6] -= flags[1] + flags[0] + len;
	else
		flags[6] -= flags[1] + flags[0] + len + neg;
	if (flags[3])
		return (print_nbr_left(nbr, flags, len, neg));
	return (print_nbr_right(nbr, flags, len, neg));
}
