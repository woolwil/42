/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 16:32:41 by ngvo              #+#    #+#             */
/*   Updated: 2026/03/14 16:32:43 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	free_error(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

static void	apply_instruction(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(line, "sa\n"))
		sa(a, false);
	else if (!ft_strcmp(line, "sb\n"))
		sb(b, false);
	else if (!ft_strcmp(line, "ss\n"))
		ss(a, b, false);
	else if (!ft_strcmp(line, "pa\n"))
		pa(a, b, false);
	else if (!ft_strcmp(line, "pb\n"))
		pb(b, a, false);
	else if (!ft_strcmp(line, "ra\n"))
		ra(a, false);
	else if (!ft_strcmp(line, "rb\n"))
		rb(b, false);
	else if (!ft_strcmp(line, "rr\n"))
		rr(a, b, false);
	else if (!ft_strcmp(line, "rra\n"))
		rra(a, false);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(b, false);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(a, b, false);
	else
	{
		free(line);
		free_error(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (0);
	// Using your existing init logic from push_swap
	stack_init(&a, argv + 1);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		apply_instruction(line, &a, &b);
		free(line);
	}
	if (stack_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}