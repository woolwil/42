/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 16:37:01 by ngvo              #+#    #+#             */
/*   Updated: 2026/03/14 16:37:02 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_error(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

static void	apply_instruction(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(line, "sa\n", 3))
		sa(a, false);
	else if (!ft_strncmp(line, "sb\n", 3))
		sb(b, false);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(a, b, false);
	else if (!ft_strncmp(line, "pa\n", 3))
		pa(a, b, false);
	else if (!ft_strncmp(line, "pb\n", 3))
		pb(b, a, false);
	else if (!ft_strncmp(line, "ra\n", 3))
		ra(a, false);
	else if (!ft_strncmp(line, "rb\n", 3))
		rb(b, false);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(a, b, false);
	else if (!ft_strncmp(line, "rra\n", 4))
		rra(a, false);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rrb(b, false);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(a, b, false);
	else
		free_error(a, b);
}

/* ** Simple replacement for GNL: reads from stdin into a buffer 
** until a newline or EOF.
*/
static char	*get_next_line_lite(int fd)
{
	char	*buf;
	char	c;
	int		i;
	int		rd;

	i = 0;
	buf = malloc(10); // Instructions are max 4 chars + \n + \0
	if (!buf)
		return (NULL);
	while ((rd = read(fd, &c, 1)) > 0)
	{
		buf[i++] = c;
		if (c == '\n')
			break ;
	}
	if (rd <= 0 && i == 0)
		return (free(buf), NULL);
	buf[i] = '\0';
	return (buf);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;
	char	**args;

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (0);
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	init_stack_a(&a, args, (argc == 2));
	while (1)
	{
		line = get_next_line_lite(0);
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