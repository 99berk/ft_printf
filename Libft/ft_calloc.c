/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:57:15 by bakgun            #+#    #+#             */
/*   Updated: 2023/07/10 15:34:16 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*s;
	int		i;

	i = (int)(count * size);
	s = (char *)malloc(sizeof(char) * (count * size));
	if (!s)
	{
		return (NULL);
	}
	while (--i >= 0)
	{
		s[i] = 0;
	}
	return ((void *)s);
}
