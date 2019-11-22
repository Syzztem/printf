/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <lothieve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:10:02 by lothieve          #+#    #+#             */
/*   Updated: 2019/11/22 14:10:49 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int
	get_value(const char *format, va_list args)
{
	if (*format == '*')
		return (va_arg(args, int));
	else
		return (ft_atoi(format));
}

t_fmt
	reformat(t_fmt fdat)
{
	if (fdat.padding < 0 || fdat.precision > 0)
		fdat.padchar = ' ';
	return (fdat);
}

int
	is_in_set(char c)
{
	int i;
	int l;

	i = 0;
	l = ft_strlen(HANDLED_FLAGS);
	while (i < l)
	{
		if (c == HANDLED_FLAGS[i])
			return (1);
		i++;
	}
	return (0);
}

int
	is_nflag(char c)
{
	if (c == '*' || ft_isdigit(c))
		return (1);
	return (0);
}
