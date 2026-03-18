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
		if (stack->value == n)
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
	node->value = n;
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

void	init_stack_a(t_stack **a, char **argv, int is_split)
{
	int		i;
	long	value;
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
		value = ft_atol(argv[i]);
		if (value < INT_MIN || value > INT_MAX)
			error_free(a, argv, is_split);
		if (is_duplicate(*a, (int)value))
			error_free(a, argv, is_split);
		app_bool = append_node(a, (int)value);
		if (!app_bool)
			error_free(a, argv, is_split);
		i++;
	}
}
