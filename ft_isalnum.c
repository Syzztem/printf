/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <lothieve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:04:03 by lothieve          #+#    #+#             */
/*   Updated: 2019/11/18 18:15:30 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int
	ft_isupper(int c)
{
	return (c <= 'Z' && c >= 'A' ? 1 : 0);
}

static int
	ft_islower(int c)
{
	return (c <= 'z' && c >= 'a' ? 1 : 0);
}

int
	ft_isalpha(int c)
{
	return (ft_islower(c) + ft_isupper(c));
}

int	ft_isdigit(int c)
{
	return (c <= '9' && c >= '0' ? 1 : 0);
}

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) + ft_isdigit(c));
}
