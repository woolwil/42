/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:29:11 by ngvo              #+#    #+#             */
/*   Updated: 2026/03/13 17:11:31 by ngvo             ###   ########.fr       */
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
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	// get cheapest node to A top
	prep_for_push(a, cheapest_node, 'a');
	// get its target node to B top
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a, true);
}

void	move_b2a(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b, true);
}

// void	set_target_b(t_stack *a, t_stack *b)
// {
// 	t_stack	*current_a;
// 	t_stack	*target_node;
// 	long	best_match_nbr;

// 	while (b)
// 	{
// 		best_match_nbr = LONG_MAX;
// 		current_a = a;
// 		while (current_a)
// 		{
// 			if (current_a->nbr > b->nbr && current_a->nbr < best_match_nbr)
// 			{
// 				best_match_nbr = current_a->nbr;
// 				target_node = current_a;
// 			}
// 			current_a = current_a->next;
// 		}
// 		if (best_match_nbr == LONG_MAX)
// 			b->target_node = find_min(a);
// 		else
// 			b->target_node = target_node;
// 		b = b->next;
// 	}
// }
