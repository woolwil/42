/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 20:31:12 by ngvo              #+#    #+#             */
/*   Updated: 2026/03/18 12:09:35 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*max_node;

	max_node = find_max(*a);
	if (*a == max_node)
		ra(a, true);
	else if ((*a)->next == max_node)
		rra(a, true);
	if ((*a)->value > (*a)->next->value)
		sa(a, true);
}
