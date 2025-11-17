/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:14:53 by codespace         #+#    #+#             */
/*   Updated: 2025/10/15 19:17:38 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_fibonacci(int index)
{
    if (index < 0)
        return -1;
    if (index == 0)
        return 0;
    if (index == 1)
        return 1;
    return ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
}

// int main(void)
// {
//     int index = 10;
//     int result = ft_fibonacci(index);
//     printf("Fibonacci of %d is %d\n", index, result);
//     return 0;
// }

