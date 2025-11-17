/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot13.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 21:43:53 by codespace         #+#    #+#             */
/*   Updated: 2025/10/16 18:47:14 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Write a program that takes a string and displays it, replacing each of its
// letters by the letter 13 spaces ahead in alphabetical order.

// 'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

// The output will be followed by a newline.

// If the number of arguments is not 1, the program displays a newline.

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        int i = 0;
        while (argv[1][i])
        {
            if ((argv[1][i] >= 'a' && argv[1][i] <= 'm') ||
                (argv[1][i] >= 'A' && argv[1][i] <= 'M'))
                argv[1][i] += 13;
            else if ((argv[1][i] >= 'n' && argv[1][i] <= 'z') ||
                     (argv[1][i] >= 'N' && argv[1][i] <= 'Z'))
                argv[1][i] -= 13;
            write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}

