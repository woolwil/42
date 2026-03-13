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
	int		len_a;
	t_stack	*min_node;

	//init push 2 b
	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, true);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, true);
	// push a 2 b until 3 nodes left
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a2b(a, b);
	} // leaves remaining 3
	sort_three(a);
	while (*b)//push all back from b 2 a
	{
		init_nodes_b(*a, *b);
		move_b2a(a, b);
	} //final tweak
	current_index(*a);
	min_node = find_min(*a);
	prep_for_push(a, min_node, 'a');
}
bool	stack_sorted(t_stack *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		// If the current number is bigger than the next one, it's not sorted
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}
