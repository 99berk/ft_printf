/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:06:42 by bakgun            #+#    #+#             */
/*   Updated: 2023/07/24 17:18:39 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_put_s(int i, char *s);

int	ft_print_ptr(void *pointer)
{
	unsigned long long	address;
	static char			hex_digits[] = "0123456789abcdef";
	int					count;
	char				s[50];
	int					i;

	i = 0;
	if (write(1, "0x", 2) == -1)
		return (-1);
	address = (unsigned long long)pointer;
	count = 2;
	if (address == 0)
	{
		write(1, "0", 1);
		count += 1;
		return (count);
	}
	while (address != 0)
	{
		s[i++] = hex_digits[address % 16];
		address /= 16;
		count += 1;
	}
	ft_put_s(i, s);
	return (count);
}

static void	ft_put_s(int i, char *s)
{
	while (--i >= 0)
		write(1, &s[i], 1);
}
