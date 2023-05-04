/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:31:10 by luide-so          #+#    #+#             */
/*   Updated: 2023/05/04 14:51:31 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	int		i;
	int		len;
	char	s;

	len = ft_intlen(nbr);
	i = 0;
	s = ' ';
	if (flags[5] || flags[4])
		s = '0';
	if (flags[5] && flags[6])
		flags[7] = flags[6];
	if (flags[3])
	{
		ft_putnbr_fd(nbr, 1);
		while (i < flags[7] - len - flags[1])
			i += write(1, &s, 1);
	}
	else
	{
		while (i < flags[7] - len - flags[1])
			i += write(1, &s, 1);
		ft_putnbr_fd(nbr, 1);
	}
	return (len + i + flags[1]);
}

//Falta tratar caso do + e ' ', dividir em mais funções, verificar tamanho quando negativo...