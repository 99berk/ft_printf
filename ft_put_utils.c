/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:39:06 by bakgun            #+#    #+#             */
/*   Updated: 2023/07/25 17:39:11 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int ft_putstr(char *s)
{
	int	i;
    int tmp;

	i = 0;
	while (s[i])
	{
		tmp = ft_putchar(s[i]);
        if (tmp == -1)
            return (-1);
		i++;
	}
    return (tmp);
}

int ft_putnbr(int n)
{
    int tmp;

	if (n == -2147483648)
	{
		tmp = ft_putchar('-');
		ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		tmp = ft_putchar('-');
		n = n * (-1);
	}
	if (n >= 0 && n <= 9)
	{
		tmp = ft_putchar((48 + n));
	}
	else
	{
		ft_putnbr((n / 10));
		ft_putnbr((n % 10));
	}
    return (tmp);
}
