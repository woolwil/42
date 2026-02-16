/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:15:52 by codespace         #+#    #+#             */
/*   Updated: 2025/10/16 13:11:48 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_recursive_factorial(int nb)
{
    if (nb < 0)
        return (0);
    if (nb == 0)
        return (1);
    return (nb * ft_recursive_factorial(nb - 1));
}

int main(void)
{
    int number = 10;
    int factorial = ft_recursive_factorial(number);
    printf("Factorial of %d is %d\n", number, factorial);
    printf("Factorial of %d is %d\n", 0, ft_recursive_factorial(0));
    printf("Factorial of %d is %d\n", 1, ft_recursive_factorial(1));
    printf("Factorial of %d is %d\n", 2, ft_recursive_factorial(2));
    printf("Factorial of %d is %d\n", 3, ft_recursive_factorial(3));
    printf("Factorial of %d is %d\n", 4, ft_recursive_factorial(4));
    printf("Factorial of %d is %d\n", 5, ft_recursive_factorial(5));
    return (0);
}