/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <lothieve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 22:29:03 by lothieve          #+#    #+#             */
/*   Updated: 2019/11/21 15:10:22 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <limits.h>

size_t	ft_strlen(const char *s)
{
	size_t l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

int	ft_putchar_f(char c, t_fmt fdat, int fd)
{
	int		p;

	p = fdat.padding > 0 ? fdat.padding : -fdat.padding;
	while (fdat.padding-- > 1)
		write(fd, &fdat.padchar, 1);
	write(fd, &c, 1);
	while (++fdat.padding < -1)
		write(fd, &fdat.padchar, 1);
	return (p > 1 ? p : 1);
}

int	ft_putstr_f(const char *s, t_fmt fdat, int fd)
{
	size_t	l;
	int		p;

	if (!s)
		return(ft_putstr_f("(null)", fdat, fd));
	p = fdat.padding > 0 ? fdat.padding : -fdat.padding;
	l = ft_strlen(s);
	l = l > fdat.precision ? fdat.precision : l;
	while (fdat.padding > 0 && fdat.padding-- > l)
		write(fd, &fdat.padchar, 1);
	write(1, s, l);
	while (fdat.padding < 0 && fdat.padding++ < -l)
		write(fd, &fdat.padchar, 1);
	return (p > l ? p : l);
}
