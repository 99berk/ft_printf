/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:22:54 by bakgun            #+#    #+#             */
/*   Updated: 2023/07/24 16:18:18 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(char format, va_list args);
static int	ft_print_num(int num);
static int	ft_print_str(char *str);
static int	ft_print_unum(unsigned int num);

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
			len = len + write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}

static int	ft_format(char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1), 1);
	else if (format == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	else if (format == 'd') 
		return (ft_print_num(va_arg(args, int)));
	else if (format == 'i')
		return (ft_print_num(va_arg(args, int)));
	else if (format == 'u')
		return (ft_print_unum(va_arg(args, unsigned int)));
	else if (format == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), 0));
	else if (format == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), 1));
	if (format == '%')
		return (write(1, "%", 1));
	return (0);
}

static int	ft_print_str(char *str)
{
	char	*s;

	s = str;
	if (!str)
		s = "(null)";
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

static int	ft_print_num(int num)
{
	char	*str_num;
	int		i;

	str_num = ft_itoa(num);
	i = 0;
	ft_putnbr_fd(num, 1);
	while (str_num[i])
		i++;
	free(str_num);
	return (i);
}

static int	ft_print_unum(unsigned int num)
{
	int	i;

	i = 0;
	if (num > 9)
		i = i + ft_print_unum(num / 10);
	ft_putchar_fd((num % 10) + '0', 1);
	return (i + 1); 
}
