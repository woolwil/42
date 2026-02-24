/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 19:05:12 by ngvo              #+#    #+#             */
/*   Updated: 2026/02/21 19:12:16 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	syntax_err(char *s_n)
{
	if (!(*s_n == '+' || *s_n == '-' || (*s_n >= '0' && *s_n <= '9')))
		return (1);
	if ((*s_n == '+' || *s_n == '-') && !(s_n[1] >= '0' && s_n[1] <= '9'))
		return (1);
	while (*++s_n)
	{
		if (!(s_n >= '0' && *s_n <= '9'))
			return (1);
	}
	return (0);
}

int	duplicate_err(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return (NULL);
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_stack_node **a)
{
	free_stack(a);
	ft_printf("Error\n");
	exit(1);
}