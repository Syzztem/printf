/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <lothieve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 22:40:49 by lothieve          #+#    #+#             */
/*   Updated: 2019/11/22 14:12:18 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEX_LOW "0123456789abcdef"
# define HEX_UPP "0123456789ABCDEF"
# define OCTAL "01234567"
# define DECIMAL "0123456789"
# define HANDLED_PFLAGS "-0.*"
# define HANDLED_FLAGS "cspdiuxX%"
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_fmt
{
	int		padding;
	char	padchar;
	int		precision;
}				t_fmt;

int		get_value(const char *format, va_list args);
int		ft_printf(const char *format, ...);
int		is_in_set(char c);
int		is_nflag(char c);
int		ft_putchar_f(char c, t_fmt fdat, int fd);
int		ft_putnbr_base_f(long long nb, char *base, t_fmt fdat);
int		ft_isalnum(int c);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_atoi(const char *str);
int		ft_putstr_f(const char *s, t_fmt fdat, int fd);
int		ft_putaddr_f(unsigned long long addr, char *base, t_fmt fdat);
size_t	ft_strlen(const char *s);
size_t	ft_print_adress(unsigned long long addr, char mode, int fd);
t_fmt	reformat(t_fmt fdat);

#endif