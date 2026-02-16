/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:13:51 by codespace         #+#    #+#             */
/*   Updated: 2025/10/15 19:19:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_iterative_power(int nb, int power)
{
    int result;
    int i;

    if (power < 0)
        return (0);
    result = 1;
    i = 0;
    while (i < power)
    {
        result *= nb;
        i++;
    }
    return (result);
}

// int main(void)
// {
//     int number = 2;
//     int power = 10;
//     int result = ft_iterative_power(number, power);
//     printf("%d to the power of %d is %d\n", number, power, result);
//     return (0);
// }