/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:34:19 by codespace         #+#    #+#             */
/*   Updated: 2025/11/08 16:39:06 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_point.h" // Your header file: ft_point.h

// The set_point function required by the exercise
// This function must be in your test file, not in the header.
void set_point(t_point *point)
{
    // The arrow operator (->) is used because 'point' is a pointer.
    point->x = 42;
    point->y = 21;
}

int main(void)
{
    // FIX: Initialize the structure to {0} to prevent the "uninitialized" error
    //      when reading its initial values with strict compiler flags.
    t_point point = {0}; 

    printf("--- Testing t_point Structure (ft_point.h) ---\n");

    // 1. Print initial (initialized) values
    printf("Point before set_point:\n");
    printf("  x: %d\n", point.x); // Should be 0
    printf("  y: %d\n", point.y); // Should be 0

    // 2. Call the function to modify the structure
    //    We pass the ADDRESS of the 'point' variable (&point)
    set_point(&point);

    // 3. Print values after function call
    printf("\nPoint after set_point:\n");
    printf("  x: %d (Expected: 42)\n", point.x);
    printf("  y: %d (Expected: 21)\n", point.y);

    // 4. Verification Check
    if (point.x == 42 && point.y == 21)
    {
        printf("\nResult: SUCCESS! t_point structure and function work.\n");
        return (0); // Return 0 for success
    }
    else
    {
        printf("\nResult: FAILURE! Values were not set correctly.\n");
        return (1); // Return non-zero for error
    }
}