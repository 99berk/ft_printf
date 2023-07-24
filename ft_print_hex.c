/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:03:51 by bakgun            #+#    #+#             */
/*   Updated: 2023/07/24 18:03:56 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_hex(unsigned int number, int upper_case)
{
    static char upper_digits[] = "0123456789ABCDEF";
    static char lower_digits[] = "0123456789abcdef";
    char buffer[50];  // yeterince büyük olmasına dikkat edin
    char *digits = upper_case ? upper_digits : lower_digits;
    int i = 0, count;

    if (number == 0) {
        buffer[i++] = '0';
    } else {
        while (number != 0) {
            buffer[i++] = digits[number % 16];
            number /= 16;
        }
    }

    count = i;
    while (--i >= 0) {
        write(1, &buffer[i], 1);
    }

    return count;
}


