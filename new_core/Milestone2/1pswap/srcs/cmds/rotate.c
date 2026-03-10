/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:04:36 by ngvo              #+#    #+#             */
/*   Updated: 2026/03/10 19:53:14 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	rotate(t_stack **head)
{
	t_stack *last_node;
	t_stack *old_head;

	if (!*head || !(*head)->next)
		return ;

	// Move the head pointer to the second node
	old_head = *head;
	last_node = find_last(*head);
	*head = (*head)->next; // Move head to 2nd node
	(*head)->prev = NULL; // New head has no prev node
	last_node->next = old_head; // Link old tail to old head
	old_head->prev = last_node; // Link old head back to old tail
	old_head->next = NULL; // Old head is now last
}

void	ra(t_stack **a, bool print)
{
	rotate(a);
	if (print)
		write (1, "ra\n", 3);
}

void	rb(t_stack **b, bool print)
{
	rotate(b);
	if (print)
		write (1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, bool print)
{
	if (!*a || !(*a)->next || !*b || !(*b)->next)
		return ;
	rotate(a);
	rotate(b);
	if (print)
		write (1, "rr\n", 3);
}
