/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 20:31:12 by ngvo              #+#    #+#             */
/*   Updated: 2026/03/12 16:51:56 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*max_node;
	
	max_node = find_max(*a);
	// Max top
	if (*a == max_node)
		ra(a, true);
	// Max mid
	else if ((*a)->next == max_node)
		rra(a, true);
	//Max bot, check if top mid are right
	if ((*a)->value > (*a)->next->value)
		sa(a, true);
}
