/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_f.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <lothieve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 15:30:54 by lothieve          #+#    #+#             */
/*   Updated: 2019/11/21 16:51:22 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int
	ft_putnbr_base_f2(unsigned long long nb, char *base, int blen, int p)
{
	int	l;

	if (nb == 0 && p <= 0)
		return (0);
	l = ft_putnbr_base_f2(nb / blen, base, blen, p - 1);
	write(1, base + nb % blen, 1);
	return (l + 1);
}

int
	num_len(unsigned long long nb, int bsize)
{
	int l;

	l = 0;
	while (nb > 0)
	{
		nb /= bsize;
		l++;
	}
	return (l);
}

int
	ft_putaddr_f(unsigned long long addr, char *base, t_fmt fdat)
{
	int	l;
	int i;

	l = num_len(addr, ft_strlen(base)) + 2;
	i = l;
	while (fdat.padding > i++)
		write(1, &fdat.padchar, 1);
	write(1, "0x", 2);
	ft_putnbr_base_f2(addr, base, ft_strlen(base), fdat.precision);
	if (fdat.padding < 0)
	{
		fdat.padding *= -1;
		while (fdat.padding >= i++)
			write(1, &fdat.padchar, 1);
	}
	return (fdat.padding > l ? fdat.padding : l);
}

int
	ft_putnbr_base_f(long long nb, char *base, t_fmt fdat)
{
	unsigned long long	n;
	int					l;
	int					i;

	if (fdat.precision != -1)
		fdat.padchar = ' ';
	if (nb == 0 && fdat.precision < 0)
		return (ft_putchar_f(*base, fdat, 1));
	n = nb < 0 ? -nb : nb;
	l = num_len(n, ft_strlen(base));
	l = l > fdat.precision ? l : fdat.precision;
	i = nb >= 0 ? l : l + 1;
	while (fdat.padding > i++)
		write(1, &fdat.padchar, 1);
	if (nb < 0)
		write(1, "-", 1);
	ft_putnbr_base_f2(n, base, ft_strlen(base), fdat.precision);
	if (fdat.padding < 0)
	{
		fdat.padding *= -1;
		while (fdat.padding >= i++)
			write(1, &fdat.padchar, 1);
	}
	return (fdat.padding > l ? fdat.padding : l);
}
