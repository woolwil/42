/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:32:39 by codespace         #+#    #+#             */
/*   Updated: 2025/11/08 16:33:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_abs.h" // Your header file containing the ABS macro

int main(void)
{
    int a = 10;
    int b = -42;
    int c = 0;
    int i = -5; // For side-effect test

    printf("--- Testing ABS Macro (ft_abs.h) ---\n");

    // Test 1: Positive value
    printf("ABS(%d)   = %d\n", a, ABS(a));
    // Expected output: ABS(10) = 10

    // Test 2: Negative value
    printf("ABS(%d)  = %d\n", b, ABS(b));
    // Expected output: ABS(-42) = 42

    // Test 3: Zero
    printf("ABS(%d)    = %d\n", c, ABS(c));
    // Expected output: ABS(0) = 0

    // Test 4: Expression
    printf("ABS(5-10) = %d\n", ABS(5 - 10));
    // Expected output: ABS(5-10) = 5

    // Test 5: Side-Effect BUG Demonstration
    printf("\n--- Side-Effect Test (i = %d) ---\n", i);
    int result = ABS(i--); // WARNING: May cause i to be decremented multiple times!
    printf("ABS(i--)  = %d\n", result);
    printf("i is now  = %d (Expected -6 if ABS was a function, but likely lower)\n", i);
    // If your macro is robust (like the GCC extension), i should be -6. 
    // If it's the basic macro, i will be lower (e.g., -7).

    return (0);
}