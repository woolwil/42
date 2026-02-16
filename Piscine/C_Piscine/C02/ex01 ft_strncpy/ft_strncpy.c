/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyevonam <nyevonam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 00:00:00 by nyevonam          #+#    #+#             */
/*   Updated: 2025/11/18 00:00:00 by nyevonam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(int length, char *str);
char	*ft_strncpy(char *dest, char *src, unsigned int n);

int	main(int argc, char *argv[])
{
	int			len;
	int			count;
	char		*dest;

	len = ft_strlen(argc, argv[1]);
	count = len;
	dest = (char *)malloc((count + 1) * sizeof(char));
	if (dest == NULL)
	{
		printf("Memory allocation failed\n");
		return (1);
	}
	ft_strncpy(dest, argv[1], count);
	printf("\n");
	printf("Destination: %s\n", dest);
	printf("\n");
	printf("Strlen: %d\n", len);
	return (0);
}

int	ft_strlen(int length, char *str)
{
	int			n;

	n = 0;
	if (length == 2)
	{
		while (*str != '\0')
		{
			n++;
			str++;
		}
	}
	else
		printf("invalid input for strlen\n");
	return (n);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	char			*og_ptr;

	i = 0;
	og_ptr = dest;
	while (*src != '\0' && i < n)
	{
		dest[i] = *src;
		src++;
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (og_ptr);
}
