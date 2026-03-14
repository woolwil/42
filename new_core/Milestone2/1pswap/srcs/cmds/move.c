/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:29:11 by ngvo              #+#    #+#             */
/*   Updated: 2026/03/13 18:00:09 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	move_a2b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*a);
	// 1. Loop rr as long as BOTH nodes are not at the top
	if (cheapest->above_median && cheapest->target_node->above_median)
	{
		while (*a != cheapest && *b != cheapest->target_node)
			rr(a, b, true); // This is your existing function!
	}
	// 2. Loop rrr as long as BOTH nodes are not at the top
	else if (!(cheapest->above_median) && !(cheapest->target_node->above_median))
	{
		while (*a != cheapest && *b != cheapest->target_node)
			rrr(a, b, true); // This is your existing function!
	}
	// 3. Refresh indices after simultaneous rotations
	current_index(*a);
	current_index(*b);
	// 4. Individual rotations to finish the job
	prep_for_push(a, cheapest, 'a');
	prep_for_push(b, cheapest->target_node, 'b');
	// 5. Finally push
	pb(b, a, true);
}

void	move_b2a(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b, true);
}
