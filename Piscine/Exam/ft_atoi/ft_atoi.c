/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 20:37:38 by codespace         #+#    #+#             */
/*   Updated: 2025/10/16 20:45:45 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(char*str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) && str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			sign = -sign;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	main(int ac, char **a)
{
	if (ac == 2)
	{
		printf("FT_ATOI: %d\n", ft_atoi(a[1]));
		printf("ATOI: %d\n", atoi(a[1]));
		return (0);
	}
	else
	{
		char	*str = "---+--+1234ab567";
		char	*str2 = "123456789123456"; // 15 characters long
		int			num;
		int 		num2;

		num = ft_atoi(str);
		num2 = ft_atoi(str2);
		printf("The FT_ATOI converted integer is: %d\n", num);
		printf("The FT_ATOI converted integer is: %d\n", num2);
		printf("The ATOI converted integer is: %d\n", atoi("123456789123456"));
		printf("The ATOI converted integer is: %d\n", atoi("-1234ab567"));
		return (0);
	}
}