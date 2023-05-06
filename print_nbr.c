/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:31:10 by luide-so          #+#    #+#             */
/*   Updated: 2023/05/06 17:10:04 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_nbr_right(char *nbr, int *flags, int neg)
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
	else if (flags[0] && !neg)
		flags[1] = write(1, " ", 1);
	while (j < flags[6])
		j += write(1, "0", 1);
	if (flags[5] < 2)
		ft_putstr_fd(nbr, 1);
	free(nbr);
	return (i + j + flags[1]);
}

static int	print_nbr_left(char *nbr, int *flags, int neg)
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
		ft_putstr_fd(nbr, 1);
	free(nbr);
	while (i < flags[7])
		i += write(1, " ", 1);
	return (i + j + flags[1]);
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

static char	*itoa_positive(long long n)
{
	char		*c;
	bool		sign;
	long long	len;

	sign = n < 0;
	len = ft_intlen(n);
	c = (char *)malloc(sizeof(char) * (len + 1));
	if (!c)
		return (NULL);
	c[len] = '\0';
	if (sign)
	{
		c[--len] = -(n % 10) + '0';
		n = -(n / 10);
	}
	while (len--)
	{
		c[len] = n % 10 + '0';
		n = n / 10;
	}
	return (c);
}

int	print_nbr(int n, int *flags)
{
	int		len;
	bool	neg;
	char	*nbr;

	nbr = itoa_positive(n);
	len = ft_intlen(n);
	neg = n < 0;
	if (flags[5] && !flags[6] && !n)
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
		return (len + print_nbr_left(nbr, flags, neg));
	return (len + print_nbr_right(nbr, flags, neg));
}
