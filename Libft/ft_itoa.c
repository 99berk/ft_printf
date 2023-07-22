/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:31:02 by bakgun            #+#    #+#             */
/*   Updated: 2023/07/10 11:49:06 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	if (n < 0)
	{
		len++;
		n = n * (-1);
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	ln;

	ln = (long)n;
	len = ft_numlen(ln);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	*(str + len--) = '\0';
	if (n == 0)
		*str = '0';
	if (ln < 0)
	{
		*str = '-';
		ln = ln * (-1);
	}
	while (ln > 0)
	{
		*(str + len--) = ('0' + (ln % 10));
		ln = ln / 10;
	}
	return (str);
}
