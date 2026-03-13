/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 23:17:49 by ngvo              #+#    #+#             */
/*   Updated: 2026/02/27 23:17:49 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_stack_a(t_stack **a, char **argv, int is_split)
{
	int		i;
	long	nbr;
	int		app_bool;

	i = 0;
	if (is_split)
		i = 0;
	if (!*argv)
		return ;
	while (argv[i])
	{
		if (is_syntax_error(argv[i]))
			error_free(a, argv, is_split);
		nbr = ft_atol(argv[i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
			error_free(a, argv, is_split);
		if (is_duplicate(*a, (int)nbr))
			error_free(a, argv, is_split);
		app_bool = append_node(a, (int)nbr);
		if (!app_bool)
			error_free(a, argv, is_split);
		i++;
	}
}

static long	ft_atol(const char *s)
{
	long	result;
	int		sign;
	int		digit_count;

	result = 0;
	sign = 1;
	digit_count = 0;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s ++;
	}
	while (ft_isdigit(*s))
	{
		result = result * 10 + (*s++ - '0');
		if (++digit_count > 18)
			break ;
	}
	return (result * sign);
}

bool	is_duplicate(t_stack *stack, int n)
{
	if (!stack)
		return (false);
	while (stack)
	{
		if (stack->nbr == n)
			return (true);
		stack = stack->next;
	}
	return (false);
}

static bool	append_node(t_stack **stack, int n)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!stack)
		return (false);
	node = malloc(sizeof (t_stack));
	if (!node)
		return (false);
	node->nbr = n;
	node->next = NULL;
	if (!*stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
	return (true);
}
