/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 15:59:24 by ngvo              #+#    #+#             */
/*   Updated: 2026/03/01 15:59:24 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	push(t_stack **dest, t_stack **src)
{
	t_stack	*node_to_push;

	if (!*src)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	
	if (!*dest)
		node_to_push->next = NULL;
	else
    {
        node_to_push->next = *dest;
        (*dest)->prev = node_to_push;
    }
	*dest = node_to_push;
	(*dest)->prev = NULL;
}

void	pa(t_stack **a, t_stack **b, bool print)
{
	push(a, b);
	if (!print)
		write(1, "pa\n", 3);
}

void	pb(t_stack **b, t_stack **a, bool print)
{
	push(b, a);
	if (!print)
		write(1, "pb\n", 3);
}
