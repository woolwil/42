/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngvo <ngvo@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 16:37:01 by ngvo              #+#    #+#             */
/*   Updated: 2026/03/18 15:04:08 by ngvo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	apply_instruction(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(line, "sa\n", 4))
		return (sa(a, false), 1);
	else if (!ft_strncmp(line, "sb\n", 4))
		return (sb(b, false), 1);
	else if (!ft_strncmp(line, "ss\n", 4))
		return (ss(a, b, false), 1);
	else if (!ft_strncmp(line, "pa\n", 4))
		return (pa(a, b, false), 1);
	else if (!ft_strncmp(line, "pb\n", 4))
		return (pb(b, a, false), 1);
	else if (!ft_strncmp(line, "ra\n", 4))
		return (ra(a, false), 1);
	else if (!ft_strncmp(line, "rb\n", 4))
		return (rb(b, false), 1);
	else if (!ft_strncmp(line, "rr\n", 4))
		return (rr(a, b, false), 1);
	else if (!ft_strncmp(line, "rra\n", 5))
		return (rra(a, false), 1);
	else if (!ft_strncmp(line, "rrb\n", 5))
		return (rrb(b, false), 1);
	else if (!ft_strncmp(line, "rrr\n", 5))
		return (rrr(a, b, false), 1);
	return (0);
}

static char	*get_next_line_lite(int fd)
{
	char	*buf;
	char	c;
	int		i;
	int		rd;

	i = 0;
	rd = 0;
	buf = malloc(5);
	if (!buf)
		return (NULL);
	while (i < 4)
	{
		rd = read(fd, &c, 1);
		if (rd <= 0)
			break ;
		buf[i++] = c;
		if (c == '\n')
			break ;
	}
	if (rd <= 0 && i == 0)
		return (free(buf), NULL);
	if (i == 4 && buf[3] != '\n')
		return (free(buf), ft_strdup("INVALID"));
	buf[i] = '\0';
	return (buf);
}

static void	read_instructions(t_stack **a, t_stack **b,
		char **args, int is_split)
{
	char	*line;

	while (1)
	{
		line = get_next_line_lite(0);
		if (!line)
			break ;
		if (!ft_strncmp(line, "INVALID", 8) || !apply_instruction(line, a, b))
		{
			free(line);
			free_stack(b);
			error_free(a, args, is_split);
		}
		free(line);
	}
}

static int	init_checker_data(int argc, char **argv, char ***args)
{
	if (argc < 2)
		return (0);
	if (argc == 2 && !argv[1][0])
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (argc == 2)
		*args = ft_split(argv[1], ' ');
	else
		*args = argv + 1;
	return (2);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;
	int		status;
	int		is_split;

	a = NULL;
	b = NULL;
	status = init_checker_data(argc, argv, &args);
	if (status != 2)
		return (status);
	is_split = (argc == 2);
	if (is_split && !args)
		error_free(&a, args, is_split);
	init_stack_a(&a, args, is_split);
	read_instructions(&a, &b, args, is_split);
	if (stack_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	if (is_split)
		free_split(args);
	return (0);
}
