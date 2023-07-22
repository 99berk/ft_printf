/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:16:47 by bakgun            #+#    #+#             */
/*   Updated: 2023/07/13 16:42:58 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*last;

	if (s)
	{
		if (start >= ft_strlen(s) || len == 0)
			return (ft_strdup("\0"));
		i = 0;
		while (i < len && s[start + i])
			i++;
		last = (char *)malloc(sizeof(char) * i + 1);
		if (!last)
			return (NULL);
		j = 0;
		while (j < i)
		{
			last[j] = s[start + j];
			j++;
		}
		last[j] = '\0';
		return (last);
	}
	return (NULL);
}
