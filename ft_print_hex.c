/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:03:51 by bakgun            #+#    #+#             */
/*   Updated: 2023/07/25 10:54:49 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static char	*ft_digits(int upper_case);

int	ft_print_hex(unsigned int number, int upper_case)
{
	char		buffer[50];
	char		*digits;
	int			i;
	int			count;

	digits = ft_digits(upper_case);
	i = 0;
	if (number == 0)
		buffer[i++] = '0';
	else
	{
		while (number != 0)
		{
			buffer[i++] = digits[number % 16];
			number /= 16;
		}
	}
	count = i;
	while (--i >= 0)
		if (write(1, &buffer[i], 1) == -1)
			return (-1);
	return (count);
}

static char	*ft_digits(int upper_case)
{
	static char	upper_digits[] = "0123456789ABCDEF";
	static char	lower_digits[] = "0123456789abcdef";

	if (upper_case == 1)
		return (upper_digits);
	else
		return (lower_digits);
	return (NULL);
}
