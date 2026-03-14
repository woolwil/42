/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 15:17:22 by ngvo              #+#    #+#             */
/*   Updated: 2026/03/14 19:02:04 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	cost_analysis(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		if (a->above_median && a->target_node->above_median)
			a->push_cost = max(a->index, a->target_node->index);
		else if (!(a->above_median) && !(a->target_node->above_median))
			a->push_cost = max(len_a - a->index, len_b - a->target_node->index);
		else
		{
			if (a->above_median)
				a->push_cost = a->index;
			else
				a->push_cost = len_a - a->index;
			if (a->target_node->above_median)
				a->push_cost += a->target_node->index;
			else
				a->push_cost += len_b - a->target_node->index;
		}
		a = a->next;
	}
}
