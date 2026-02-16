/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:13:11 by codespace         #+#    #+#             */
/*   Updated: 2025/10/15 19:18:37 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
    int	result;
    int	i;

    if (nb < 0)
        return (0);
    result = 1;
    i = 1;
    while (i <= nb)
    {
        result *= i;
        i++;
    }
    return (result);
}

// int main(void)
// {
//     int number = 10;
//     int factorial = ft_iterative_factorial(number);
//     printf("Factorial of %d is %d\n", number, factorial);
//     return 0;
// }