/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 22:02:56 by codespace         #+#    #+#             */
/*   Updated: 2025/11/10 20:13:58 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	len;
	int	i;
	int *arr;

	if (min >= max)
		return NULL;
	len = max - min;
	arr = malloc(len * sizeof *arr);
	if (!arr)
		return NULL;
	i = 0;
	while (i < len)
	{
		arr[i] = min + i;
		i++;
	}
	return arr;
}

int	main(void)
{
	int min = 1;
	int max = 10;
	int	*range = ft_range(min, max);
	int	i = 0;

	if (!range)
	{	
		printf("NULL\n");
		return (0);
	}
	while (i < (max - min))
	{
		printf("range: %d\n", range[i]);
		i++;
	}
	free(range);
	return (0);
}
