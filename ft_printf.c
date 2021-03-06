/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <lothieve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 21:37:05 by lothieve          #+#    #+#             */
/*   Updated: 2019/11/22 14:35:13 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int
	print_format(char f, va_list args, t_fmt fdat)
{
	if (f == 'c')
		return (ft_putchar_f(va_arg(args, int), fdat, 1));
	else if (f == 's')
		return (ft_putstr_f(va_arg(args, char *), fdat, 1));
	else if (f == 'p')
		return (ft_putaddr_f((unsigned long long)va_arg(args, void *),
		HEX_LOW, fdat));
	else if (f == 'd' || f == 'i')
		return (ft_putnbr_base_f(va_arg(args, int), DECIMAL, fdat));
	else if (f == 'u')
		return (ft_putnbr_base_f(va_arg(args, unsigned int), DECIMAL, fdat));
	else if (f == 'x')
		return (ft_putnbr_base_f(va_arg(args, unsigned int), HEX_LOW, fdat));
	else if (f == 'X')
		return (ft_putnbr_base_f(va_arg(args, unsigned int), HEX_UPP, fdat));
	else
		return (ft_putchar_f(f, fdat, 1));
}

int
	handle_format2(const char *format, va_list args, t_fmt fdat)
{
	while (*format && (!is_in_set(*format)))
	{
		if (*format == '.')
			fdat.precision = get_value(format + 1, args);
		else if (*format == '-')
			fdat.padding = -ft_abs(get_value(format + 1, args));
		else if (*format == '0' && fdat.padding >= 0 && fdat.precision < 0)
		{
			fdat.padchar = '0';
			fdat.padding = get_value(format + 1, args);
		}
		if (*format == '.' || *format == '0' || *format == '-')
			format += is_nflag(*(format + 1)) ? 1 : 0;
		else if (ft_isdigit(*format) || *format == '*')
			fdat.padding = get_value(format, args);
		if (ft_isdigit(*format) && *format != '0')
			while (ft_isdigit(*format))
				format++;
		else if (!is_in_set(*format))
			format++;
	}
	return (print_format(*format, args, reformat(fdat)));
}

int
	handle_format(const char *format, va_list args)
{
	t_fmt	fdat;

	fdat.padchar = ' ';
	fdat.precision = -1;
	fdat.padding = 0;
	return (handle_format2(format, args, fdat));
}

int
	ft_printf(const char *format, ...)
{
	int			i;
	va_list		args;

	i = 0;
	va_start(args, format);
	while (*format)
	{
		while (*format && *format != '%')
		{
			write(1, format++, 1);
			i++;
		}
		if (*format == '%')
		{
			i += handle_format(++format, args);
			format++;
			while (*format && !is_in_set(*(format - 1)))
				format++;
		}
	}
	return (i);
}
