/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:45:11 by luide-so          #+#    #+#             */
/*   Updated: 2023/05/06 16:59:17 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int	i;

	ft_printf("ft_%c", 'i');
	i = ft_printf(" %#.0x ", 0);
	ft_printf("%c", 'i');
	printf("\n%d\n", i);
	printf("%4c", 'i');
	i = printf(" %#.0x ", 0);
	printf("%c", 'i');
	printf("\n%d\n", i);
	return (0);
}
