/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:25:34 by luide-so          #+#    #+#             */
/*   Updated: 2023/05/04 02:39:16 by luide-so         ###   ########.fr       */
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

static int	flags_nbr(const char *param, int *flags)
{
	int	i;
	int	n;

	n = ft_atoi(param);
	i = ft_intlen(n) - 1;
	if (flags[5])
		flags[6] = n;
	else
		flags[7] = n;
	return (i);
}

static int	*check_flags(const char *param, int *flags, int *k)
{
	int		j;
	char	*cflags;

	cflags = " +#-0.";
	j = 8;
	while (j)
		flags[--j] = 0;
	while (param[*k] && !ft_strchr("csdixXup", param[*k]))
	{
		j = 0;
		while (cflags[j])
		{
			if (param[*k] == cflags[j])
				flags[j] = 1;
			j++;
		}
		if (param[*k] >= '1' && param[*k] <= '9')
			*k += flags_nbr(&param[*k], flags);
		(*k)++;
	}
	return (flags);
}

static int	check_conversion(const char param, va_list ap, int *flags)
{
	if (!(param))
		return (0);
	if (param == 'c')
		return (print_chr(ap, flags));
	if (param == 's')
		return (print_str(ap, flags));
/* 	if (*param == 'd' || *param == 'i')
		return (print_nbr);
	if (*param == 'x' || *param == 'X')
		return (print_hex);
	if (*param == 'u')
		return (print_unsigned);
	if (*param == 'p')
		return (print_pointer); */
	return (0);
}

int	ft_printf(const char *param, ...)
{
	int		count;
	int		k;
	int		flags[8];
	va_list	ap;

	va_start(ap, param);
	count = 0;
	k = 0;
	while (param[k])
	{
		if (param[k] == '%' && param[k + 1] && param[k + 1] != '%')
		{
			k++;
			check_flags(param, flags, &k);
			count += check_conversion(param[k], ap, flags);
		}
		else
			count += write(1, &param[k], 1);
		k++;
	}
	printf("\n0.1.2.3.4.5.6.7.\n");
	va_end(ap);
	k = 0;
	while (k < 8)
		printf("%d.", flags[k++]);
	return (count);
}

int	main(void)
{
	int	i;

	i = ft_printf("I%7.2sI", "'abc'");
	printf("\n%d\n", i);
	i = printf("I%7.2sI", "'abc'");
	printf("\n%d\n", i);
	return (0);
}
