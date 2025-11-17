/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 10:33:19 by ngvo              #+#    #+#             */
/*   Updated: 2025/10/15 15:30:49 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char *ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && (j < nb))
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int	main(void)
{
	int n = 0;

	char dest[100] = "i wanna go home, ";
	char src[100] = "let me go home";
	printf("Dest: %s\n", dest);
	printf("Src: %s\n", src);
	ft_strncat(dest, src, (sizeof(dest) - strlen(dest) - 1));
	// ft_strncat(dest, src, 10);
	printf("Concatenated output: %s\n", dest);
	return (0);
}
