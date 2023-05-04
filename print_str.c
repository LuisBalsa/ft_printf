/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 00:32:08 by luide-so          #+#    #+#             */
/*   Updated: 2023/05/04 02:12:06 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(va_list ap, int *flags)
{
	char	*str;
	int		i;
	int		len;

	str = va_arg(ap, char *);
	len = (int)ft_strlen(str);
	i = 0;
	if (flags[5] && len > flags[6])
		len = flags[6];
	str = ft_substr(str, 0, len);
	if (flags[3])
	{
		ft_putstr_fd(str, 1);
		while (i < flags[7] - len)
			i += write(1, " ", 1);
	}
	else
	{
		while (i < flags[7] - len)
			i += write(1, " ", 1);
		ft_putstr_fd(str, 1);
	}
	free(str);
	return (len + i);
}
