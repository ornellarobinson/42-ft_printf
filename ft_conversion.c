/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 18:46:22 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/02 14:04:59 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	display_space(t_option *option, char *res)
{
	int space;

	space = 0;
	while (space < option->padding - (int)ft_strlen(res))
	{
		ft_putchar(' ');
		space++;
	}
}

int		ft_s(va_list lst, t_option *option)
{
	char *res;
	int result;
	int i;

	printf("padding = %d || precision = %d\n", option->padding, option->precision);
	i = -1;
	if (!(res = va_arg(lst, char *)))
		res = "(null)";
	if (option->precision == 0 || (option->precision > 0
	&& (option->padding > option->precision)))
		result = option->padding;
	else if ((option->precision > 0 && option->padding <= option->precision)
	|| (option->precision == -1 && option->padding == -1))
		result = ft_strlen(res);
	if (option->padding > option->precision && option->precision > -1)
		while (++i < option->padding - option->precision)
			ft_putchar(' ');
	i = -1;
	if (option->precision > 0 && option->precision < (int)ft_strlen(res))
		while (++i < option->precision)
			ft_putchar(res[i]);
	else if (option->precision != 0)
		ft_putstr(res);
	printf("\nVRAI PRINTF = format = %16.5sok", "bonjour");
	return (result);
}

int		conversion(char *format, t_option *option, va_list lst)
{
	int	i;
	int	(*convert[6])(va_list, t_option *);

	i = 0;
	convert[0] = &ft_s;
	// convert[1] = &ft_S;
	// convert[2] = &ft_p;
	// convert[3] = &ft_d;
	// convert[4] = &ft_D;
	// convert[5] = &ft_i;
	while (STR_CONVERSION[i])
	{
		if (i < 6 && STR_CONVERSION[i] == *format)
			return (convert[i](lst, option));
		else if (i >= 6 && STR_CONVERSION[i] == *format)
			return (1);
		i++;
	}
	return (0);
}
