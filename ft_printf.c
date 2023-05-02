/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:25:34 by luide-so          #+#    #+#             */
/*   Updated: 2023/05/02 21:35:29 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	flags_nbr(char *param, int *flags)
{
	int	i;

	return (i);
}

static int	check_flags(char *param, int *flags, char *cflags)
{
	int	i;
	int	j;

	i = 0;
	while (param[i] && !ft_strchr("%csdixXup", param[i]))
	{
		j = 0;
		while (cflags[j])
		{
			if (param[i] == cflags[j])
				flags[j] = 1;
			j++;
		}
		if (param[i] >= '1' && param[i] <= '9')
			i += flags_nbr(param[i], flags);
		i++;
	}
	return (i);
}

static int	(*check_conversion(char *param))(va_list, t_list)
{
	if (!(*param))
		return (NULL);
	if (*param == '%')
		return (print_perc);
	if (*param == 'c')
		return (print_chr);
	if (*param == 's')
		return (print_str);
	if (*param == 'd' || *param == 'i')
		return (print_nbr);
	if (*param == 'x' || *param == 'X')
		return (print_hex);
	if (*param == 'u')
		return (print_unsigned);
	if (*param == 'p')
		return (print_pointer);
	return (NULL);
}

int	ft_printf(const char *param, ...)
{
	int		count;
	int		flags[8];
	char	*cflags;
	va_list	ap;
	int		(*f)(va_list, t_flags);

	va_start(ap, param);
	cflags = " +#-0.";
	count = 7;
	while (count + 1)
		flags[count--] = 0;
	while (*param)
	{
		if (*param == '%')
		{
			param++;
			/* code */
		}
		else
			count += write(1, param, 1);
		param++;
	}
	va_end(ap);
	return (count);
}
