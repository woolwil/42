/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 19:53:46 by ngvo              #+#    #+#             */
/*   Updated: 2026/03/10 20:16:13 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	reverse_rotate(t_stack **head)
{
	t_stack *last_node;
	
	if (!*head || !(*head)->next)
		return ;
	last_node = find_last(*head); // Detach last node: The second-to-last node becomes the new tail
	last_node->prev->next = NULL;
	last_node->next = *head; // attach last_node to the top of the stack.
	last_node->prev = NULL;
	(*head)->prev = last_node;
	*head = last_node;
}

void	rra(t_stack **a, bool print)
{
	reverse_rotate(a);
	if (print)
		write (1, "rra\n", 4);
}

void	rrb(t_stack **b, bool print)
{
	reverse_rotate(b);
	if (print)
		write (1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, bool print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print)
		write (1, "rrr\n", 4);
}
