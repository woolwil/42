/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 22:29:44 by ngvo              #+#    #+#             */
/*   Updated: 2026/02/27 22:29:44 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	init_stack_a(&a, args, (argc == 2));
	if (!stack_sorted(a))
		if (stack_len(a) == 2)
			sa(&a, false);
	else if (stack_len(a) == 3)
		sort_3(&a);
	else
		sort_stacks(&a, &b);
	free_stack(&a);
	if (argc == 2)
		free_split(args);
	return (0);
}
