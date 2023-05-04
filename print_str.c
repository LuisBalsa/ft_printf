/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 00:32:08 by luide-so          #+#    #+#             */
/*   Updated: 2023/05/04 17:51:01 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *s, int *flags)
{
	char	*str;
	int		i;
	int		len;

	if (!s)
		return (print_str("(null)", flags));
	len = (int)ft_strlen(s);
	i = 0;
	if (flags[5] && len > flags[6])
		len = flags[6];
	str = ft_substr(s, 0, len);
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
