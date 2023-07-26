/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:03:51 by bakgun            #+#    #+#             */
/*   Updated: 2023/07/26 18:14:33 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static char	*ft_digits(int upper_case);
static int	count_hex_digits(unsigned int number);

int	ft_print_hex(unsigned int number, int upper_case)
{
	char			*digits = ft_digits(upper_case);
	int				count;
	int				numDigits;
	unsigned int	tmp;
	int				i;

	count = 0;
	if (number == 0)
	{
		if (write(1, &digits[0], 1) == -1)
			return -1;
		count++;
	}
	else
	{
		numDigits = count_hex_digits(number);
		while (numDigits-- > 0)
		{
			tmp = number;
			i = numDigits;
			while (i-- > 0)
				tmp /= 16;
			tmp %= 16;
			if (write(1, &digits[tmp], 1) == -1)
				return -1;
			count++;
		}
	}
	return (count);
}

static int	count_hex_digits(unsigned int number)
{
	int	numDigits;
	
	numDigits = 0;
	while (number != 0)
	{
		number /= 16;
		numDigits++;
	}
	return (numDigits);
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
