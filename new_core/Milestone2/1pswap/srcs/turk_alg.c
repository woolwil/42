/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 23:19:44 by ngvo              #+#    #+#             */
/*   Updated: 2026/02/27 23:19:44 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_stacks(t_stack **a, t_stack **b)
{
	if (stack_len(*a) > 3 && !stack_sorted(*a))
		pb(b, a, true);
	if (stack_len(*a) > 3 && !stack_sorted(*a))
		pb(b, a, true);
	while (stack_len(*a) > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a2b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b2a(a, b);
	}
	current_index(*a);
	prep_for_push(a, find_min(*a), 'a');
}

bool	stack_sorted(t_stack *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}
