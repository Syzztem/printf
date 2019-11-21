/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <lothieve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 08:01:42 by lothieve          #+#    #+#             */
/*   Updated: 2019/11/18 18:16:17 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int
	ft_isspace(int c)
{
	if (c == '\t'
			|| c == '\n'
			|| c == '\v'
			|| c == '\f'
			|| c == '\r'
			|| c == ' ')
		return (1);
	return (0);
}

static void
	addto(unsigned int *out, char c)
{
	*out *= 10;
	*out += c - '0';
}

int
	ft_atoi(const char *str)
{
	int				sign;
	unsigned int	out;

	sign = 1;
	out = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		addto(&out, *str);
		str++;
	}
	return (out * sign);
}
