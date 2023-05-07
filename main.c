/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:45:11 by luide-so          #+#    #+#             */
/*   Updated: 2023/05/07 17:23:49 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int	i;

	ft_printf("ft_%c", '|');
	i = ft_printf("%-30.10p", NULL);
	ft_printf("%c", '|');
	printf("\n%d\n", i);
	printf("%4c", '|');
	i = printf("%30p", NULL);
	printf("%c", '|');
	printf("\n%d\n", i);
	return (0);
}
