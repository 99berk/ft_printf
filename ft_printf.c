/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:22:54 by bakgun            #+#    #+#             */
/*   Updated: 2023/07/22 17:57:41 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(char format, va_list args);
static int	ft_print_num(char *num);

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len = len + ft_format(format[i], args);
		}
		else
			len = len + ft_putchar_fd(&format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}

static int	ft_format(char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar_fd(va_args(args, int), 1), 1);
	else if (format == 's')
		return (0);
	else if (format == 'p')
		return (0);
	else if (format == 'd')
		return (ft_print_num(va_args(args, int)));
	else if (format == 'i')
		return (ft_print_num(va_args(args, int)));
	else if (format == 'u')
		return (0);
	else if (format == 'x')
		return (0);
	else if (format == 'X')
		return (0);
	if (format == '%')
		return (ft_putchar_fd("%", 1));
	return (0);
}

static int	ft_print_num(char *num)
{
	ft_putnbr_fd(ft_atoi(num), 1);
}
