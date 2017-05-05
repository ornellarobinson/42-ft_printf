/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 18:46:22 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/05 14:24:45 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*reminder : # define STR_CONVERSION "sSpdDi%oOuUxXcC" */

int		display_padding(t_option *option)
{
	int i;
	int result;

	i = 1;
	result = 0;
	while (i < option->padding)
	{
		result += ft_putchar_int(' ');
		i++;
	}
	return (result);
}

int		ft_convert_char(t_option *option, long long nb)
{
	int		result;
	char	c;

	result = 0;
	c = (char)nb;
	if (option->minuszero != '-' && option->padding != -1)
		result += display_padding(option);
	result += ft_putchar_int(c);
	if (option->padding != -1)
		result += display_padding(option);
	return (result);
}

int		ft_convert_int(t_option *option, char *format, long long nb)
{
	int result;

	result = 0;
	if (*format == 'c')
		result += ft_convert_char(option, nb);
	else if (*format == 'u')
		result += ft_convert_unsigned_decimal(option, nb);
	return (result);
}

int		conversion(char *format, t_option *option, va_list lst)
{
	int	i;
	int	(*convert[6])(va_list, t_option *);

	i = 0;
	convert[0] = &ft_convert_s;
	// convert[1] = &ft_convert_S;
	// convert[2] = &ft_convert_p;
	convert[3] = &ft_convert_d;
	// convert[4] = &ft_convert_D;
	convert[5] = &ft_convert_s;
	while (STR_CONVERSION[i])
	{
		if (i < 6 && STR_CONVERSION[i] == *format)
			return (convert[i](lst, option));
		else if (*format == '%')
			return (ft_percent(option));
		else if (i >= 6 && STR_CONVERSION[i] == *format)
			return (ft_convert_int(option, format, va_arg(lst, long long)));
		i++;
	}
	return (0);
}
