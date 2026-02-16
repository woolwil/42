/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:19:57 by codespace         #+#    #+#             */
/*   Updated: 2025/10/15 21:32:31 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

int ft_is_prime(int nb)
{
    int i;

    if (nb <= 1)
        return 0;
    if (nb == 2)
        return 1;
    if (nb % 2 == 0)
        return 0;
    i = 3;
    /* use division to avoid i*i overflow */
    while (i <= nb / i)
    {
        if (nb % i == 0)
            return 0;
        i += 2;
    }
    return 1;
}

int ft_find_next_prime(int nb)
{
    if (nb <= 2)
        return 2;
    /* start with an odd candidate to skip even checks */
    if ((nb & 1) == 0)
        nb++;
    /* iterate odd candidates; avoid wrapping past INT_MAX */
    while (nb > 0)
    {
        if (ft_is_prime(nb))
            return nb;
        if (nb >= INT_MAX - 2) /* next increment would wrap -> stop */
            break;
        nb += 2;
    }
    return 0;
}

int main(void)
{
    int tests[] = {-1, 0, 1, 2, 3, 4, 14, 17, 30, 2147483646, 2147483647};
    int n = 11;
    for (int i = 0; i < n; ++i)
    {
        int t = tests[i];
        int p = ft_find_next_prime(t);
        printf("next prime after %d -> %d\n", t, p);
    }
    return 0;
}

