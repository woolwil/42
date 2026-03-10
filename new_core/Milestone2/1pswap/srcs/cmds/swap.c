/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 15:17:19 by ngvo              #+#    #+#             */
/*   Updated: 2026/03/10 20:25:41 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	swap(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next; //1st now points to 3rd
	first->prev = second; //1st now points to 2nd
	second->next = first;
	second->prev = NULL;
	if (first->next) // Fix the "Third Node" (the one now after 'first')
		first->next->prev = first;
	*head = second;
}

void	sa(t_stack **a, bool print)
{
	swap(a);
	if (print)
		write (1, "sa\n", 3);
}

void	sb(t_stack **b, bool print)
{
	swap(b);
	if (print)
		write (1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, bool print)
{
	swap(a);
	swap(b);
	if (print)
		write (1, "ss\n", 3);
}
