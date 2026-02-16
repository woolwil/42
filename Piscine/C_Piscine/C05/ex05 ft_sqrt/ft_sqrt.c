/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:15:34 by codespace         #+#    #+#             */
/*   Updated: 2025/10/16 15:54:43 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_sqrt(int nb)
{
    int i;

    if (nb < 0)
        return (0);
    if (nb == 0)
        return (0);
    i = 1;
    /* loop condition uses division to avoid i * i overflowing */
    while (i <= nb / i)
    {
        if (i * i == nb)
            return (i);
        i++;
    }
    return (0);
}

int main(void)  
{
    int number = 16;
    int sqrt_result = ft_sqrt(number);

    /* printing 0 as a valid square root is handled explicitly */
    if (number == 0)
        printf("Square root of 0 is 0\n");
    else if (sqrt_result)
        printf("Square root of %d is %d\n", number, sqrt_result);
    else
        printf("%d does not have a perfect square root\n", number);
    return (0);
}
